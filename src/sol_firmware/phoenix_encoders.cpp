/**
 * phoenix_encoders.cpp
 **/

#include "phoenix_encoders.h"
#include <avr/io.h>
#include <avr/interrupt.h>

// Number of encoders
#define NUM_ENCODERS 3
/**
 * Encoder mask for Register K (From A8 to A15)
 * We use the following configuration:
 *
 *         /--J2--/--J1--/--J0--/ 
 * 0 - 0 - 1 - 1 - 1 - 1 - 1 - 1
 * A15 A14 A13 A12 A11 A10 A9 A8
 * regvalue: 0x3F
 **/
#define ENCODER_MASK 0x3F

// status of the encoder as the previous bits of port K
uint8_t _encoder_prev;
// Current encoder value
uint16_t _encoder_current_value[NUM_ENCODERS];
// Sampled value
uint16_t _encoder_sampled_value[NUM_ENCODERS];

void Encoder_init(void) {
  cli();
  for(int i=0;i<NUM_ENCODERS;++i){
    _encoder_current_value[i]=0;
    _encoder_sampled_value[i]=0;
  }
  DDRK &= ~ENCODER_MASK; // set encoder pins as INPUT
  PORTK |= ENCODER_MASK; // enable pullup resistors
  PCICR |= (1 << PCIE2); // set interrupt on change, looking up PCMSK2
  PCMSK2 |= ENCODER_MASK; // set PCINT2 to trigger an interrupt on state change  
  sei();
}

void Encoder_sample(void) {
  cli();
  register int16_t* sample=_encoder_sampled_value;
  register int16_t* current=_encoder_current_value;
  for (uint8_t i=0;i<NUM_ENCODERS;++i) {
    *sample=*current;
    sample++;
    current++;
  }
  sei();
}

uint16_t Encoder_getValue(uint8_t num_encoder) {
  return _encoder_sampled_value[num_encoder];
}

static const int8_t _transition_table []= {
  
  0,  //0000
  1,  //0001
  -1, //0010
  0,  //0011
  -1, //0100
  0,  //0101
  0,  //0110
  1,  //0111
  1,  //1000
  0,  //1001
  0,  //1010
  -1, //1011
  0,  //1100
  -1, //1101
  1,  //1110
  0   //1111
};

/**
 * La ISR deve eseguire i seguenti passi:
 * 
 * - salvare in port_value il valore di PINK (Port INput K)
 *   e prendere solamente i bit in corrispondenza della maschera
 *   ENCODER_MASK. Ricordare l'effetto dell'operatore AND bit a bit (&):
 *   0b11001010 & 0b00000011 = 0b00000010
 * - salva in prev_value il valore _encoder_prev
 * - salva in ttable la variabile _transition_table
 * - salva in curr_enc la variabile _encoder_current_value
 * 
 * Le variabili vengono salvate in variabili presenti all'interno della ISR
 * indicate come "register". Questo comporta un ottimizzazione a livello di
 * esecuzione, in quanto le variabili vengono mantenute nei registri della CPU
 * garantendo una velocita molto piu' alta in esecuzione.
 * 
 * Ora bisogna costruire l'indice della tavola di transizione (PER OGNI ENCODER)
 * componendo la lettura della precedente iterazione (_encoder_prev)
 *  con la lettura attuale (port_value).
 *  La composizione viene eseguita nel seguente modo:
 * 
 * - La transition_table contiene 16 elementi (4 bit per indicizzarli).
 * - Ogni encoder genera due bit. Uniti con i due bit dall'iterazione precedente
 *   si hanno 4 bit. Possiamo costruire un indice per la tabella unendoli.
 * - Si prendono i primi due bit (tramite una maschera 0x03) di c_value e si
 *   uniscono (tramite operazione di OR | ) ai primi due bit di prev_value.
 * - somma a *curr_value il valore di ttable[indice calcolato]
 * - finalmente si shifta c_value di 2 bit (c_value >>= 2) e 
 *   prev_value (prev_value >>= 2)
 * 
 * Al termine del ciclo sugli encoder, salvare in _encoder_prev il valore
 * di port_value
 **/
ISR(PCINT2_vect) {
  cli();
  uint8_t port_value=PINK&ENCODER_MASK; // Read encoder step
  
  register uint8_t c_value=port_value;
  register uint8_t prev_value=_encoder_prev;
  register const int8_t* ttable=_transition_table;
  register int16_t* curr_enc=_encoder_current_value;

  for(uint8_t i=0;i<NUM_ENCODERS;++i) {
    // build the following data:
    // first 2 bits of prev_value | first 2 bits of c_value
    uint8_t table_idx=(c_value&0x03)|((prev_value&0x03)<<2);
    *curr_enc += ttable[table_idx];
    c_value>>=2;
    prev_value>>=2;
  }
  _encoder_prev=port_value;
  sei();
}
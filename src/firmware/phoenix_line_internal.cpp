/**
 * phoenix_line_internal.cpp
 **/

#include "phoenix_line_internal.h"

// PER FRANCESCO:
// Togli il blocco di commenti qui sotto
// x attivare la sezione relativa all'ADS1015

//#include "Adafruit_ADS1015.h"
//#define NUM_ADC 4
//#define LINE_ADC_ADDR_FRONT  0
//#define LINE_ADC_ADDR_LEFT   1
//#define LINE_ADC_ADDR_RIGHT  2
//#define LINE_ADC_ADDR_BACK   3
//static Adafruit_ADS1015 line_adc[NUM_ADC] = {
// Adafruit_ADS1015(LINE_ADC_ADDR_FRONT),
// Adafruit_ADS1015(LINE_ADC_ADDR_LEFT),
//  Adafruit_ADS1015(LINE_ADC_ADDR_RIGHT),
//  Adafruit_ADS1015(LINE_ADC_ADDR_BACK)
//};



/**
 * inizializza l (PhoenixLineSensor) azzerando i valori di
 * soglia, misura, misura_max, misura_min, detect_flag e 
 * calibra_flag
 * OCCHIO a NON azzerare le variabili x ed y !
 **/
void PhoenixLineSensor_init(PhoenixLineSensor* l) {
  /**
   * Per Francesco:
   * In questa funzione dovrai anche inizializzare l'adc relativo
   * al sensore. Puoi farlo tramite la funzione:
   * line_adc[l->adc_addr].begin()
   **/
  // Da completare...
  return;
}

/**
 * Esegue la lettura del sensore, se la flag di calibrazione
 * (calibra_flag) e' attiva, allora aggiorna anche
 * misura_min e misura_max secondo queste condizioni:
 * misura < misura_min ? => misura_min = misura
 * misura > misura_max ? => misura_max = misura
 *
 *In oltre se la lettura e' maggiore della soglia
 * allora imposta ad 1 lo status (detect_flag)
 **/
void PhoenixLineSensor_handle(PhoenixLineSensor* l) {
  /**
   * ASSOLUTAMENTE DA LEGGERE:
   *
   * Per Francesco:
   * Puoi effettuare la lettura del sensore accedendo all'array
   * di ADS1015 (line_adc) nell'indice l->adc_addr e scrivendo
   * il seguente comando:
   * lettura = line_adc[d->adc_addr].readADC_SingleEnded(d->adc_idx);
   *
   * Per Sara:
   * Puoi effettuare la lettura del sensore tramite una lettura analogica
   * al pin: l->pin_reading
   **/
  // Da completare...
  return;
}

/**
 * imposta la variabile calibra_flag di l (PhoenixLineSensor)
 * pari a 1
 **/
void PhoenixLineSensor_startCalib(PhoenixLineSensor* l) {
  // Da completare...
  return;
}

/**
 * imposta la variabile calibra_flag di l (PhoenixLineSensor)
 * pari a 0 
 * Poi imposta soglia secondo la formula:
 * soglia = (misura_max + misura_min) / 2
 * Poi azzera anche misura_min e misura_max
 **/
void PhoenixLineSensor_stopCalib(PhoenixLineSensor* l) {
  // Da completare...
  return;
}

/**
 * restituisce il valore di detect_flag
 **/
uint8_t PhoenixLineSensor_getStatus(PhoenixLineSensor* l) {
  // Da completare...
  return 0;
}

/**
 * imposta la variabile  detect_flag di l (PhoenixLineSensor)
 * pari a 0
 **/
void PhoenixLineSensor_reset(PhoenixLineSensor* l) {
  // Da completare...
  return;
}

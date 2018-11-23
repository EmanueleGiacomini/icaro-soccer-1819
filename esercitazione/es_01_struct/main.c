/**
   main.c
**/

#include <stdio.h>

typedef struct {
  int x;
  int y;
  int sommaxy;
}MiaStruct;

/** Completare le funzioni qui sotto **/


/** 
    la funzione init deve impostare le variabili
    di m a 0 (ovvero x, y, sommaxy)
**/
void MiaStruct_init(MiaStruct* m) {
  
}

/** setX deve impostare la variabile x di m
    pari a v
**/
void MiaStruct_setX(MiaStruct* m, int v) {
  
}

/** getX deve restituire la variabile x di m **/
int MiaStruct_getX(MiaStruct* m) {
  return 0;//da modificare...
}

/** setX deve impostare la variabile y di m
    pari a v
**/
void MiaStruct_setY(MiaStruct* m, int v) {
  
}

/** getY deve restituire la variabile y di m **/
int MiaStruct_getY(MiaStruct* m) {
  return 0;//da modificare...
}

/** 
    compute deve eseguire la somma di 
    x ed y e salvarla in sommaxy
**/
void MiaStruct_compute(MiaStruct* m) {
  
}

/** #----------------> non modificare qui sotto... <--------------# **/

void MiaStruct_print(MiaStruct* m) {
  printf("sommaxy: %d\n", m->sommaxy);
}


MiaStruct ms;

int main(int argc, char* argv[]) {
  MiaStruct_init(&ms);
  MiaStruct_setX(&ms, 3);
  MiaStruct_setY(&ms, 2);
  MiaStruct_compute(&ms);
  // Test 1
  printf("[soluzione=5]\t");
  MiaStruct_print(&ms);
  return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
Qui sotto ci mettiamo i prototipi di tutte le noste funzioni
 */
void messaggioIntro(); //questa la useremo per il messaggio iniziale di benvenuto



/*
Qui sotto c'è il nostro main minimale
 */
int main(){
  srand48(time(0)); //per ogni evenienza ho già inizializzato la sequenza di numeri casuali


  return 0;
}






/*
Qui sotto le nostre innumerevoli funzioni
 */
void messaggioIntro(){
  printf("\nBenvenuto nel nostro programma\n");
  return;
}

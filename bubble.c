//Emilio Taggi 1910388
#include <stdlib.h>
#include <stdio.h>
#include <time.h> //ho incluso le librerie di cui avrò bisogno

#define Nseq 8     //numero di elementi negli array
#define puntMax 50 //punteggio massimo che mette fine alla partita

void genera(char *,int); //funzione che riempirà i miei array mediante generazionedi numeri casuali
void stampa(char *,int); //funzione per stampare gli array nel formato richiesto
int count(char *,int);   //funzione che si occupa di contare la sequenza piu' lunga di "sfere dello stesso colore"


int main(){

  srand48(time(0)); //inizializzo la sequenza di numeri casuali

  char bubbleA[Nseq],bubbleB[Nseq];
  int punteggioA=0,punteggioB=0;
  int contoA=0,contoB=0;
  int turno = 0;
  int record = 0;
  char arrayRecord[Nseq];
  int i=0;
  /*premetto che tutto quello che si trova qui nel main potrebbe essere sfoltito
 implementando un paio di semplici funzioni, ma per ora ancora non ci sono :/
   */
  while(punteggioA<=puntMax || punteggioB<=puntMax){   //simula dei turni di gioco fino a che non si raggiunge il punteggio massimo      
    turno++;
    printf("\nTurno Numero %i ",turno);
    genera(bubbleA,Nseq);
    genera(bubbleB,Nseq);                      //quale che si il bug, se genero l'array di B una sola volta, lui finisce sempre con 53 punti
    genera(bubbleB,Nseq);
    printf("\nPerformance del giocatore A :  ");
    stampa(bubbleA,Nseq);
    printf("\nPerformance del giocatore B :  ");
    stampa(bubbleB,Nseq);
    contoA=count(bubbleA,Nseq);                    //conto è una variabile che uso per evitare che il pc faccia piu' calcoli del dovuto
    contoB=count(bubbleB,Nseq);
    punteggioA+=contoA;
    punteggioB+=contoB;
    if(contoA>record){                             //questi due if mi servono a salvare la sequenza record
      record=contoA;
      for(i=0;i<Nseq;i++){
	arrayRecord[i]=bubbleA[i];
      }
    }
     if(contoB>record){
      record=contoB;
      for(i=0;i<Nseq;i++){
	arrayRecord[i]=bubbleB[i];
      }
    }
  }

  printf("\nPartita terminataaa !! \nAddirittura %i turni di gioco !! ",turno);         //messaggi di fine partita
  if(punteggioA>=punteggioB){
    if(punteggioA==punteggioB){
      printf("\nLa partita si è conclusa in pareggio");
    }
    else printf("\nLa partita si è conclusa con la vittoria del giocatore A");
  }
  else printf("\nLa partita si è conclusa con la vittoria del giocatore B");

  printf("\nIl punteggio del giocatore A è di ben %i punti ",punteggioA);
  printf("\nIl punteggio del giocatore B è di ben %i punti ",punteggioB);

  printf("\nLa prima sequenza record è  : ");
  stampa(arrayRecord,Nseq);
  printf("\nChe è valsa addirittura un punteggio di %i punti \n",record);
  
  

  return 0;
}


void genera(char array[],int n){
  int i=0;
  for(i=0;i<n;i++){             //il ciclo viene iterato finchè l'array non è colmo          
    if(lrand48()%2){             //se il numero genrato è dispari l'if viene eseguito
      array[i] = 'R';            //e nella posizione i viene inserita una 'pallina rossa'
    }
    else array[i] = 'B' ;        //una bleu altrimenti
  }
}

void stampa(char array[],int n){
  int i=0;
  printf("\n  |");                      //per prima cosa stampo una linea vuota e inizializzo la stampa dell'arrai con un " | "
  for(i=0;i<n;i++){
    printf(" %c |",array[i]);           //successivamente stampo ogni elemento dell'array sulla stessa riga
  }
}

int count(char array[],int n){
  int i=0,conto = 1,conto_max = 1;     //inizializzo la sequenza contata(conto) e quella piu lunga(conto_max) a 1
  char temp = array[i];                //mi salvo in una variabile temporanea il primo elemento dell'array
  for(i=1;i<n;i++){                    //il ciclo for inizia così a contare dal secondo elemento
    if(array[i]==temp){
      conto++;                         //aumento il conteggio se un elemento e il precedente sono uguali
    }
    else conto = 1;                    //altrimento il conteggio torna a 1
    if(conto>conto_max){
      conto_max = conto;               //se il conteggio è il piu' alto finora me lo salvo in una variabile(conto_max)
    }
    temp = array[i];                   //dopo essere stato contato l'elemento viena salvato in modo temporaneo 
  }
  return conto_max;
}

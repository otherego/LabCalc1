//Emilio Taggi  versione 2.0
#include <stdlib.h>
#include <stdio.h>
#include <time.h> //ho incluso le librerie di cui avrò bisogno

#define Nseq 8     //numero di elementi negli array
#define puntMax 50 //punteggio massimo che mette fine alla partita

void genera(char *,int); //funzione che riempirà i miei array mediante generazionedi numeri casuali
void stampa(char *,int); //funzione per stampare gli array nel formato richiesto
int count(char *,int);   //funzione che si occupa di contare la sequenza piu' lunga di "sfere dello stesso colore"
void updateRecord(char *,int,char *,int *,int *); //funzione per tener traccia della sequenza piu' lunga
void dichiaraVincitore(int ,int); //funzione che compara i punteggi e dichiara il vincitore
void stampaRecord(char *,int ,int); //funzione che printa i record a fine partita
void simulaTurno(char *,char *,int ,int *, int *,char *,int *); //funzione che simula un turno di gioco


int main(){

  srand(time(0)); //inizializzo la sequenza di numeri casuali

  char bubbleA[Nseq],bubbleB[Nseq],arrayRecord[Nseq];
  int punteggioA=0,punteggioB=0,record = 0;
  int turno = 0,i=0;
  
  while(punteggioA<=puntMax && punteggioB<=puntMax){   //simula dei turni di gioco fino a che non si raggiunge il punteggio massimo      
    turno++;
    printf("\nTurno Numero %i ",turno);
    simulaTurno(bubbleA,bubbleB,Nseq,&punteggioA,&punteggioB,arrayRecord,&record);
    
  }
  printf("\nPartita terminataaa !! \nAddirittura %i turni di gioco !! ",turno);  //messaggi di fine partita
  dichiaraVincitore(punteggioA,punteggioB);
  stampaRecord(arrayRecord,Nseq,record);
  return 0;
}


void genera(char array[],int n){
  int i=0;
  for(i=0;i<n;i++){             //il ciclo viene iterato finchè l'array non è colmo          
    if(rand()%2){             //se il numero genrato è dispari l'if viene eseguito
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


void updateRecord(char array[],int n,char arrayrecord[],int *conto,int *record){
  int i=0;
   if(*conto>*record){
     *record=*conto;                       //in queste linee di codice salvo le sequenze record dopo averle comparate
      for(i=0;i<n;i++){
	arrayrecord[i]=array[i];
      }
    }
}


void dichiaraVincitore(int a,int b){         
   if(a>=b){
    if(a==b){
      printf("\nLa partita si è conclusa in pareggio");       //vengono stampati diversi messaggi finali a seconda dei punteggi           
    }
    else printf("\nLa partita si è conclusa con la vittoria del giocatore A");
  }
  else printf("\nLa partita si è conclusa con la vittoria del giocatore B");
   printf("\nIl punteggio del giocatore A è di ben %i punti ",a);
   printf("\nIl punteggio del giocatore B è di ben %i punti ",b);
}


void stampaRecord(char arrayRecord[],int n,int record){      //funzione che come richiesto stampa i record a fine partita
  printf("\nLa prima sequenza record è  : ");
  stampa(arrayRecord,n);
  printf("\nChe è valsa addirittura un punteggio di %i punti \n",record);
}


void simulaTurno(char arrayA[],char arrayB[],int n,int *a,int *b,char arrayRecord[],int *record){
  int contoA=0,contoB=0;
  genera(arrayA,n);
  genera(arrayB,n);                     //quale che sia il bug, se genero l'array di B una sola volta, lui finisce sempre con 53 punti
  genera(arrayB,n);
  contoA=count(arrayA,n);                    //conto è una variabile che uso per evitare che il pc faccia piu' calcoli del dovuto
  contoB=count(arrayB,n);
  *a+=contoA;                                 //in queste due linee vengono aggiornati i punteggi di A e B
  *b+=contoB;
  printf("\nPerformance del giocatore A :  ");
  stampa(arrayA,n);
  printf("  + %i punti per A ",contoA);
  printf("\nPerformance del giocatore B :  ");
  stampa(arrayB,n);
  printf("  + %i punti per B ",contoB);
  updateRecord(arrayA,n,arrayRecord,&contoA,record); //aggiorno la mia sequenza record ad ogni turno
  updateRecord(arrayB,n,arrayRecord,&contoB,record);
}

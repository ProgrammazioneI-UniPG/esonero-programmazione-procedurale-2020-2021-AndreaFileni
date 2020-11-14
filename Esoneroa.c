#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
int Lunghezza_Di_m, Lunghezza_Di_k, scelta;
char m[128], k[128], c[128];
time_t t;
//inserimento della stringa iniziale M
printf("Inserisci la stringa M (la sua lunghezza massima è di 128 caratteri, quindi inserendo una stringa che superi questo limite il programma la ridurrà automaticamente)\n");
fgets(m, 128, stdin);
Lunghezza_Di_m= strlen(m)-1;
printf("La stringa M è lunga %d caratteri\n\n", Lunghezza_Di_m);
//Menu dello switch
printf("Come vuoi procedere? Puoi scegliere tra 2 opzioni:\n1)La prima opzione ti permette di inserire una chiave k che sia di lunghezza uguale o maggiore a quella di M; k servirà a cifrare il testo di M.\n2)Selezionando la seconda opzione, invece, il programma genererà randomicamente una chiave casuale k, che servirà comunque a cifrare il testo di M.\n\nIndipendentemente dall'opzione che si sceglierà, il programma proseguirà cifrando la stringa M con la chiave k, generando così la stringa C; successivamente, il programma svolgerà l'operazione opposta, ovvero cifrando la stringa C con la chiave k, ottenendo nuovamente il nostro messaggio originale M.\n\n");
printf("Digita 1 per scegliere la prima opzione, digita 2 per scegliere la seconda (digitando un numero diverso da 1 e 2 il programma non andrà avanti, ma continuerà a chiedere di inserire una delle due opzioni fino a quando il numero inserito non sarà corretto)\n");
scanf("%d", &scelta);
//ciclo per mettere l'opzione giusta nello switch
while(scelta<1||scelta>2)
     {
       scanf("%d", &scelta);
       while(getchar()!='\n');
     }
printf("\n") ;

switch(scelta)
      {
      case 1:
      //inserimento chiave k
      printf("Inserire la chiave K tale che sia della stessa lunghezza o più lunga di M\n");
      getchar();
      fgets(k, 128, stdin);
      Lunghezza_Di_k=strlen(k)-1;
      //ciclo per controllare che k sia della lunghezza giusta
      while(Lunghezza_Di_k<Lunghezza_Di_m)
        {
        printf("La stringa precedentemente inserita è troppo corta, inserirne un'altra che sia della stessa lunghezza o più lunga di M\n");
        fgets(k, 128, stdin);
        Lunghezza_Di_k=strlen(k)-1;
        }
        printf("\nCifrando la stringa M con la chiave k otteniamo la stringa C=");
        //M XOR k
        for(int j=0; j<Lunghezza_Di_m; j++)
           {
           c[j]=m[j]^k[j];
           printf("%d", c[j]);
           }
        printf("\n\n");
        printf("A questo punto svogliamo l'operazione inversa cifrando la stringa C con la chiave k, così da riottenere il nostro messaggio originale M=");
        //C XOR k
        for(int p=0; p<Lunghezza_Di_m; p++)
            {
            m[p]=c[p]^k[p];
            printf("%c", m[p]);
            }
          printf("\n");
      break;
      case 2:
      printf("La chiave k generata randomicamente è: ");
      srand((unsigned)time(&t));
      //generazione della chiave random
      for(int i=0; i<Lunghezza_Di_m; i++)
         {
         printf("%c", 32+rand() %96);
         }
      printf("\n");
        printf("\nCifrando la stringa M con la chiave k otteniamo la stringa C=");
          //M XOR k
          for(int j=0; j<Lunghezza_Di_m; j++)
             {
             c[j]=m[j]^k[j];
             printf("%d", c[j]);
             }
          printf("\n\n");
          printf("A questo punto svogliamo l'operazione inversa cifrando la stringa C con la chiave k, così da riottenere il nostro messaggio originale M=");
          //C XOR k
          for(int p=0; p<Lunghezza_Di_m; p++)
              {
              m[p]=c[p]^k[p];
              printf("%c", m[p]);
              }
            printf("\n");

      break;
      }
return 0;
}

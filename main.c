#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"
#include "PQueue.h"
#include "utili.h"

void stampa_menu(FILE *);

int main()
{
    // Contatore utile per gli ID dei vari ordini
    int conto_ordini = 1;

    // Dichiarazione delle code utili per la gestione degli ordini
    queue ordini_in_attesa, ordini_consegnati;
    PQueue ordini_in_elaborazione;

    // Dichiarazione dei puntatori a file utili per la gestione degli ordini
    FILE *menu, *tempo_di_preparazione;

    ordine ord;

    int scelta;

    // Allocazione delle code che contengono gli ordini
    ordini_in_attesa = crea_queue();
    ordini_in_elaborazione = crea_PQ();
    ordini_consegnati = crea_queue();

    // Apertura del file che contiene il MENU'
    menu = fopen("MENU.txt", "r");
    if(menu == NULL)
    {
        printf("Apertura file fallita.\n");
        exit(1);
    }

    // Apertura del file che contiene il tempo di preparazione dei piatti contenuti nel MENU'
    tempo_di_preparazione = fopen("PREPARAZIONE.txt", "r");
    if(tempo_di_preparazione == NULL)
    {
        printf("Apertura file fallita.\n");
        exit(1);
    }

    printf("\nGestore Ordinazioni\n\n");

    while(1)
    {
        // Pulisce il terminale
        system("clear");

        // Stampa delle operazioni disponibili nel programma
        printf("+-------------------------------------+\n");
        printf("| 1: Aggiungi ordine.                 |\n");
        printf("| 2: Visualizza ordini in attesa.     |\n");
        printf("| 3: Invia ordine in cucina.          |\n");
        printf("| 4: Visualizza ordini in cucina.     |\n");
        printf("| 5: Marca ordine come consegnato.    |\n");
        printf("| 6: Visualizza ordini consegnati.    |\n");
        printf("| 7: Esci.                            |\n");
        printf("+-------------------------------------+\n");

        printf("\nSeleziona un operazione: ");
        scanf("%d", &scelta);

        // Pulisce il buffer
        while(getchar() != '\n');

        // Sceglie l'operazione in base alla richiesta dell'utente
        switch(scelta)
        {
            case 1:
                // Stampa a schermo il MENU'
                stampa_menu(menu);

                // Crea l'ordine
                printf("\n\nOrdine %03d\n\n", conto_ordini);
                ord = crea_ordine(menu, tempo_di_preparazione, conto_ordini);

                // Se l'ordine non è stato creato correttamente
                // stampa un messaggio di errore
                if(ord == NULL)
                {
                    printf("\nL'ordine non e' valido.\n\n");
                    attesa();
                    break;
                }

                // Stampa un messaggio di errore in caso in cui l'aggiunta
                // dell'ordine in coda di attesa non e' andato a buon fine
                if(!aggiungi_in_queue(ordini_in_attesa, ord))
                {
                    printf("\nL'ordine non e' stato inserito correttamente.\n");
                    attesa();
                    break;
                }
                printf("\n");


                // Incremanta la variabile che tiene conto degli ID degli ordini
                conto_ordini++;

                attesa();
                break;
            case 2:
                // In caso in cui viene richiesta la stampa della coda degli ordini
                // in attesa ma essa è vuota, stampa un messaggio d'errore
                if(queue_vuota(ordini_in_attesa))
                {
                    printf("\nLa coda degli ordini in attesa e' vuota.\n\n");
                    attesa();
                    break;
                }

                // Stampa la coda degli ordini in attesa
                printf("\n\nOrdini in attesa:");
                stampa_queue(menu, ordini_in_attesa);
                printf("\n\n");

                attesa();
                break;
            case 3:
                // In caso in cui la coda degli ordini in attesa è vuota stampa un
                // messaggio di errore
                if(queue_vuota(ordini_in_attesa))
                {
                    printf("\nLa coda degli ordini in attesa e' vuota.\n\n");
                    attesa();
                    break;
                }

                // In caso in cui la coda degli ordini in cucina è piena
                // stampa un messaggio di errore
                if(PQ_piena(ordini_in_elaborazione))
                {
                    printf("\nLa coda degli ordini in cucina e' piena.\n\n");
                    attesa();
                    break;
                }

                // Inserisce in ord l'ordine in testa alla coda degli ordini in attesa
                ord = ottieni_testa_queue(ordini_in_attesa);

                // Stampa un messaggio di errore in caso in cui l'aggiunta
                // dell'ordine in coda di elaborazione non e' andato a buon fine
                if(!aggiungi_in_PQ(ordini_in_elaborazione, ord))
                {
                    printf("\nL'ordine non e' stato inserito.\n");
                    attesa();
                    break;
                }

                // Rimuove l'ordine dalla lista di attesa
                rimuovi_testa_queue(ordini_in_attesa);

                printf("\nIl primo ordine in attesa e' stato inviato in cucina.\n\n");

                attesa();
                break;
            case 4:
                // In caso in cui la coda degli ordini in cucina è vuota stampa un
                // messaggio di errore
                if(PQ_vuota(ordini_in_elaborazione))
                {
                    printf("\nLa coda degli ordini in cucina e' vuota.\n\n");
                    attesa();
                    break;
                }

                // Stampa la coda degli ordini in cucina
                printf("\n\nOrdini in cucina:");
                stampa_PQ(menu, ordini_in_elaborazione);
                printf("\n\n");

                attesa();
                break;
            case 5:
                // In caso in cui la coda degli ordini in elaborazione è vuota stampa un
                // messaggio di errore
                if(PQ_vuota(ordini_in_elaborazione))
                {
                    printf("\nLa coda degli ordini in cucina e' vuota.\n\n");
                    attesa();
                    break;
                }

                // Inserisce in ord l'ordine in testa alla coda degli ordini in elaborazione
                ord = ottieni_testa_PQ(ordini_in_elaborazione);

                // Stampa un messaggio di errore in caso in cui l'aggiunta
                // dell'ordine in lista degli ordini consegnati non e' andato a buon fine
                if(!aggiungi_in_queue(ordini_consegnati, ord))
                {
                    printf("\nL'ordine non e' stato inserito.\n\n");
                    attesa();
                    break;
                }

                // Rimuove l'ordine in testa alla coda degli ordini in elaborazione
                rimuovi_testa_PQ(ordini_in_elaborazione);

                printf("\nIl primo ordine in cucina e' stato marcato come consegnato.\n\n");

                attesa();
                break;
            case 6:
                // In caso in cui la coda degli ordini conseganti è vuota stampa un
                // messaggio di errore
                if(queue_vuota(ordini_consegnati))
                {
                    printf("\nLa coda e' vuota.\n\n");
                    attesa();
                    break;
                }

                // Stampa la coda degli ordini consegnati
                printf("\n\nOrdini consegnati:");
                stampa_queue(menu, ordini_consegnati);
                printf("\n\n");

                attesa();
                break;
            case 7:
                // Controlla se la deallocazione delle code è andata a buon fine
                if(!dealloca_queue(ordini_in_attesa))
                    printf("Deallocazione non andata a buon fine.\n");
                if(!dealloca_PQ(ordini_in_elaborazione))
                    printf("Deallocazione non andata a buon fine.\n");
                if(!dealloca_queue(ordini_consegnati))
                    printf("Deallocazione non andata a buon fine.\n\n");

                // Chiude i file aperti dal programma
                fclose(menu);
                fclose(tempo_di_preparazione);

                // Termina l'esecuzione del programma
                return 0;
            default:
                // Stampa di un messaggio in caso in cui viene inserito un carattere non valido
                // durante la scelta delle operazioni del programma
                printf("\nScelta non valida.\n\n");
                attesa();
                break;
        }
    }
}


void stampa_menu(FILE *menu)
{
    char temporaneo[500];

    printf("\n\nMENU':\n\n");

    // Itera fino alla fine del file di testo
    while((fgets(temporaneo, 500, menu)))
    {
        temporaneo[strcspn(temporaneo, "\n")] = '\0';
        printf("%s\n", temporaneo);
    }

    // Rimanda il puntatore all'inizio del file
    rewind(menu);
}

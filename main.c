#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"


int main()
{
    int conto_ordini = 1;
    int scelta;
    queue ordini_in_attesa, ordini_in_elaborazione, ordini_consegnati;
    FILE *menu, *tempo_di_preparazione;
    ordine ord;

    ordini_in_attesa = crea_queue();
    ordini_in_elaborazione = crea_queue();
    ordini_consegnati = crea_queue();

    menu = fopen("MENU.txt", "r");
    if(menu == NULL)
    {
        printf("Apertura file fallita.\n");
        exit(1);
    }

    tempo_di_preparazione = fopen("PREPARAZIONE.txt", "r");
    if(tempo_di_preparazione == NULL)
    {
        printf("Apertura file fallita.\n");
        exit(1);
    }

    printf("\nGestore Ordinazioni\n\n");

    while(1)
    {
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
        while(getchar() != '\n');

        switch(scelta)
        {
            case 1:
                printf("\n\nOrdine %d\n\n", conto_ordini);
                ord = crea_ordine(menu, tempo_di_preparazione, conto_ordini);
                if(ord == NULL)
                {
                    printf("\nL'ordine non contiene piatti.\n\n");
                    break;
                }
                conto_ordini++;
                if(!aggiungi_in_queue(ordini_in_attesa, ord))
                    printf("\nL'ordine non e' stato inserito.\n");
                printf("\n");
                break;
            case 2:
                if(queue_vuota(ordini_in_attesa))
                {
                    printf("\nLa coda è vuota.\n\n");
                    break;
                }
                printf("\n\nOrdini in attesa:");
                stampa_queue(menu, ordini_in_attesa);
                printf("\n\n");
                break;
            case 3:
                if(queue_vuota(ordini_in_attesa))
                {
                    printf("\nLa coda è vuota.\n\n");
                    break;
                }
                ord = ottieni_testa_queue(ordini_in_attesa);
                if(!aggiungi_in_queue(ordini_in_elaborazione, ord))
                    printf("\nL'ordine non e' stato inserito.\n");
                rimuovi_testa_queue(ordini_in_attesa);
                printf("\nIl primo ordine in attesa e' stato inviato in cucina.\n\n");
                break;
            case 4:
                if(queue_vuota(ordini_in_elaborazione))
                {
                    printf("\nLa coda è vuota.\n\n");
                    break;
                }
                printf("\n\nOrdini in cucina:");
                stampa_queue(menu, ordini_in_elaborazione);
                printf("\n\n");
                break;
            case 5:
                if(queue_vuota(ordini_in_elaborazione))
                {
                    printf("\nLa coda è vuota.\n\n");
                    break;
                }
                ord = ottieni_testa_queue(ordini_in_elaborazione);
                if(!aggiungi_in_queue(ordini_consegnati, ord))
                    printf("\nL'ordine non e' stato inserito.\n\n");
                rimuovi_testa_queue(ordini_in_elaborazione);
                printf("\nIl primo ordine in cucina e' stato marcato come consegnato.\n\n");
                break;
            case 6:
                if(queue_vuota(ordini_consegnati))
                {
                    printf("\nLa coda è vuota.\n\n");
                    break;
                }
                printf("\n\nOrdini consegnati:");
                stampa_queue(menu, ordini_consegnati);
                printf("\n\n");
                break;
            case 7:
                if(!dealloca_queue(ordini_in_attesa))
                    printf("Deallocazione non andata a buon fine.\n");
                if(!dealloca_queue(ordini_in_elaborazione))
                    printf("Deallocazione non andata a buon fine.\n");
                if(!dealloca_queue(ordini_consegnati))
                    printf("Deallocazione non andata a buon fine.\n\n");
                return 0;
            default:
                printf("\nScelta non valida.\n\n");
                break;
        }
    }
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utili.h"
#include "queue.h"
#include "ordine.h"
#include "PQueue.h"

// Dichiarazione della funzione che confronta due file
int controllo_file(FILE *fp_output, FILE *fp_oracle);

int main(int argc, char *argv[])
{
    // Controllo che il numero di argomenti sia corretto
    if(argc != 2)
    {
        printf("Inserire il file contenente la test suite.\n");
        return(1);
    }

    int conto_ordini = 1;
    queue ordini_in_attesa, ordini_consegnati;
    PQueue ordini_in_elaborazione;
    FILE *menu, *tempo_di_preparazione;
    FILE *fp_testsuite, *fp_input, *fp_operazione, *fp_output, *fp_oracle, *fp_risultato;
    char input[50], operazione[50], output[50], oracle[50];
    ordine ord;
    int scelta;
    int num = 0;
    int righe_test_suite = 0;
    int righe_file = 0;
    int op = 0;

    // Apertura del file che contiene il MENU
    menu = fopen("MENU.txt", "r");
    if(menu == NULL)
    {
        printf("Apertura file fallita. (Menu)\n");
        exit(1);
    }

    // Apertura del file che contiene il tempo di preparazione dei piatti contenuti nel MENU
    tempo_di_preparazione = fopen("PREPARAZIONE.txt", "r");
    if(tempo_di_preparazione == NULL)
    {
        printf("Apertura file fallita. (tempo)\n");
        exit(1);
    }

    // Apertura del file della test suite
    fp_testsuite = fopen(argv[1], "r");
    if(fp_testsuite == NULL)
    {
        printf("Apertura file fallita. (testsuite)\n");
        return 1;
    }

    // Apertura del file per i risultati
    fp_risultato = fopen("risultato.txt", "w");
    if(fp_risultato == NULL)
    {
        printf("Apertura file fallita. (risultato)\n");
        return 1;
    }

    // Lettura del numero di righe nel file della test suite
    righe_test_suite = leggi_righe_file(fp_testsuite);

    // Loop per ogni coppia di righe nella test suite
    for(int i = 0; i < righe_test_suite / 2; i++)
    {
        op = 0;
        // Creazione delle strutture dati necessarie
        ordini_in_attesa = crea_queue();
        ordini_in_elaborazione = crea_PQ();
        ordini_consegnati = crea_queue();

        // Lettura del nome del file di input
        fgets(input, 50, fp_testsuite);
        input[strcspn(input, "\n")] = '\0';

        // Lettura del nome del file delle operazioni
        fgets(operazione, 50, fp_testsuite);
        operazione[strcspn(operazione, "\n")] = '\0';

        // Generazione dei nomi per i file di output e oracle
        sprintf(output, "TestC_Output%d.txt", i + 1);
        sprintf(oracle, "TestC_Oracle%d.txt", i + 1);

        // Apertura dei file di input, operazione, output e oracle
        fp_input = fopen(input, "r");
        if(fp_input == NULL)
        {
            printf("Apertura file fallita. (input)\n");
            return 1;
        }

        fp_operazione = fopen(operazione, "r");
        if(fp_operazione == NULL)
        {
            printf("Apertura file fallita. (operazione)\n");
            return 1;
        }

        fp_output = fopen(output, "w+");
        if(fp_output == NULL)
        {
            printf("Apertura file fallita. (output)\n");
            return 1;
        }

        fp_oracle = fopen(oracle, "r");
        if(fp_oracle == NULL)
        {
            printf("Apertura file fallita. (oracle)\n");
            return 1;
        }

        // Lettura della scelta dal file delle operazioni
        fscanf(fp_operazione, "%d\n", &scelta);

        // Esecuzione dell'operazione scelta
        switch(scelta)
        {
            default:
                op = 0;
                break;
            case 1:
                conto_ordini = 1;
                op = 0;
                // Lettura degli ordini dal file di input e aggiunta alla coda
                while(!feof(fp_input))
                {
                    ord = leggi_ordine_da_file(menu, tempo_di_preparazione, fp_input, conto_ordini);
                    if(ord == NULL)
                    {
                        break;
                    }

                    if(!aggiungi_in_queue(ordini_in_attesa, ord))
                    {
                        break;
                    }
                    op = 1;
                    conto_ordini++;
                }
                break;
            case 2:
                conto_ordini = 1;
                int i = 0;
                // Lettura degli ordini dal file di input e aggiunta alla coda
                while(!feof(fp_input))
                {
                    ord = leggi_ordine_da_file(menu, tempo_di_preparazione, fp_input, conto_ordini);
                    if(ord == NULL)
                    {
                        break;
                    }

                    if(!aggiungi_in_queue(ordini_in_attesa, ord))
                    {
                        break;
                    }

                    op = 1;
                    conto_ordini++;
                }

                op = 0;
                // Lettura del numero di ordini da spostare nella priority queue
                fscanf(fp_operazione, "%d\n", &num);

                for(int j = 0; j < num; j++)
                {
                    if(queue_vuota(ordini_in_attesa))
                    {
                        break;
                    }

                    if(PQ_piena(ordini_in_elaborazione))
                    {
                        break;
                    }

                    ord = ottieni_testa_queue(ordini_in_attesa);

                    if(!aggiungi_in_PQ(ordini_in_elaborazione, ord))
                    {
                        break;
                    }

                    rimuovi_testa_queue(ordini_in_attesa);
                    op = 1;
                }
                break;
            case 3:
                conto_ordini = 1;
                // Lettura degli ordini dal file di input e aggiunta alla coda
                while(!feof(fp_input))
                {
                    ord = leggi_ordine_da_file(menu, tempo_di_preparazione, fp_input, conto_ordini);
                    if(ord == NULL)
                    {
                        break;
                    }

                    if(!aggiungi_in_queue(ordini_in_attesa, ord))
                    {
                        break;
                    }

                    op = 1;
                    conto_ordini++;
                }
                op = 0;
                // Lettura del numero di ordini da spostare nella priority queue
                fscanf(fp_operazione, "%d", &num);
                for(int j = 0; j < num; j++)
                {
                    if(queue_vuota(ordini_in_attesa))
                    {
                        break;
                    }

                    if(PQ_piena(ordini_in_elaborazione))
                    {
                        break;
                    }

                    ord = ottieni_testa_queue(ordini_in_attesa);

                    if(!aggiungi_in_PQ(ordini_in_elaborazione, ord))
                    {
                        break;
                    }

                    rimuovi_testa_queue(ordini_in_attesa);
                    op = 1;
                }
                op = 0;
                // Lettura del numero di ordini da spostare nella coda consegnati
                fscanf(fp_operazione, "%d", &num);
                for(int j = 0; j < num; j++)
                {
                    if(PQ_vuota(ordini_in_elaborazione))
                    {
                        break;
                    }

                    ord = ottieni_testa_PQ(ordini_in_elaborazione);

                    if(!aggiungi_in_queue(ordini_consegnati, ord))
                    {
                        break;
                    }

                    rimuovi_testa_PQ(ordini_in_elaborazione);
                    op = 1;
                }
                break;
        }

        // Scrittura dei risultati nel file di output
        if(op == 0)
        {
            fprintf(fp_output, "Nessuna operazione effettuata.");
        }
        else
        {
            fprintf(fp_output, "Ordini in attesa:\n");
            if(queue_vuota(ordini_in_attesa))
                fprintf(fp_output, "Nessuno.\n");
            else
                stampa_queue_file(menu, fp_output, ordini_in_attesa);
            fprintf(fp_output, "\nOrdine in cucina:\n");
            if(PQ_vuota(ordini_in_elaborazione))
                fprintf(fp_output, "Nessuno.\n");
            else
                stampa_PQ_file(menu, fp_output, ordini_in_elaborazione);
            fprintf(fp_output, "\nOrdini consegnati:\n");
            if(queue_vuota(ordini_consegnati))
                fprintf(fp_output, "Nessuno.\n");
            else
                stampa_queue_file(menu, fp_output, ordini_consegnati);
        }

        // Rewind del file di output per la lettura
        rewind(fp_output);

        // Confronto tra file di output e oracle
        if(controllo_file(fp_output, fp_oracle))
            fprintf(fp_risultato, "Successo.\n");
        else
            fprintf(fp_risultato, "Fallimento.\n");

        // Deallocazione delle strutture dati
        dealloca_queue(ordini_in_attesa);
        dealloca_PQ(ordini_in_elaborazione);
        dealloca_queue(ordini_consegnati);

        // Chiusura dei file
        fclose(fp_input);
        fclose(fp_output);
        fclose(fp_operazione);
        fclose(fp_oracle);
    }

    // Chiusura dei file rimanenti
    fclose(fp_testsuite);
    fclose(menu);
    fclose(tempo_di_preparazione);
    return 0;
}

// Funzione che confronta il contenuto di due file carattere per carattere
int controllo_file(FILE *fp_output, FILE *fp_oracle)
{
    char ch1, ch2;

    while((ch1 = fgetc(fp_output)) != EOF && (ch2 = fgetc(fp_oracle)) != EOF)
    {
        if(ch1 != ch2)
            return 0;
    }

    return 1;
}

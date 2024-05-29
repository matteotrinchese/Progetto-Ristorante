#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordine.h"

// Definizione del numero massimo di piatti per un ordine
#define MASSIMO_PIATTI 20


// Definizione del tipo c_ordine
struct c_ordine
{
    int ID;
    int *piatti;            // vettore che contiene il valore associato ai piatti presenti nell'ordine
    char *descrizione;
    int t_preparazione;
};


// Funzioni


ordine crea_ordine(FILE *menu, FILE *tempo_di_preparazione, int ID)
{
    ordine ord;
    int *piatti;

    piatti = leggi_piatti(menu);

    // Se non ci sono piatti, restituisce NULL senza creare l'ordine
    if(piatti[0] == 0)
    {
        free(piatti);
        return NULL;
    }

    // Allocazione dinamica per un nuovo ordine
    ord = malloc(sizeof(struct c_ordine));
    if(ord == NULL)
    {
        printf("Allocazione dinamica non andata a buon fine.\n");
        exit(1);
    }

    ord->ID = ID;
    ord->piatti = piatti;


    // Legge la descrizione dell'ordine
    ord->descrizione = leggi_descrizione();

    // Calcola il tempo di preparazione dell'ordine
    ord->t_preparazione = calcola_tempo_di_preparazione(tempo_di_preparazione, ord->piatti);

    return ord;
}


int *leggi_piatti(FILE *menu)
{
    int *piatti;
    int num = 0;
    int righe;

    righe = leggi_righe_file(menu);

    // Allocazione dinamica per l'array piatti
    piatti = calloc(MASSIMO_PIATTI, sizeof(int));
    if(piatti == NULL)
    {
        printf("Allocazione dinamica non andata a buon fine.\n");
        exit(1);
    }

    for(int i = 0; i < MASSIMO_PIATTI - 1; i++)
    {
        printf("Inserisci il piatto dell'ordine (0 per terminare): ");

        // Controlla se il valore inserito dell'utente è valido
        if(scanf("%d", &num) != 1 || num > righe)
        {
            // Pulisce il buffer
            while(getchar() != '\n');

            printf("Valore inserito non valido\n");
            i -= 1;
            continue;
        }

        // Pulisce il buffer
        while(getchar() != '\n');

        // In caso in cui il valore inserito dall'utente e' 0
        // esce dal ciclo
        if(num == 0)
        {
            piatti[i] = num;
            break;
        }
        else
            piatti[i] = num;
    }

    return piatti;
}


int leggi_righe_file(FILE *file)
{
    char temp[100];
    int righe = 0;

    // Conta le righe finche' non arriva alla fine del file
    while(fgets(temp, 100, file) != NULL)
        righe++;

    rewind(file);

    return righe;
}


char *leggi_descrizione()
{
    char *descrizione;
    char temporaneo[500];

    printf("Inserire una descrizione dell'ordine:\n");
    fgets(temporaneo, sizeof(temporaneo), stdin);

    // Rimuove il carattere '\n' dalla stringa
    temporaneo[strcspn(temporaneo, "\n")] = '\0';

    if(temporaneo[0] == '\0')
        return NULL;

    descrizione = malloc(strlen(temporaneo) + 1);
    if(descrizione == NULL)
    {
        printf("Allocazione dinamica non andata a buon fine.\n");
        exit(1);
    }

    strcpy(descrizione, temporaneo);

    return descrizione;
}


int calcola_tempo_di_preparazione(FILE *tempo_di_preparazione, int *piatti)
{
    int t = 0;
    int t_preparazione = 0;
    char temporaneo[50];

    // Il ciclo itera fin quando non trova il valore 0 nell'array piatti
    for(int i = 0; piatti[i] != 0; i++)
    {
        rewind(tempo_di_preparazione);

        // Il ciclo itera fino alla riga precedente a quella dove e' presente
        // il tempo di preparazione ricercato
        for(int j = 0; j < piatti[i] - 1; j++)
        {
            fgets(temporaneo, sizeof(temporaneo), tempo_di_preparazione);
        }

        // Legge il numero del piatto da cui si vuole ottenere il tempo di preparazione
        fscanf(tempo_di_preparazione, "%d", &t);

        // Legge il tempo di preparazione del piatto voluto
        fscanf(tempo_di_preparazione, "%d", &t);

        // Somma il tempo di preparazione
        t_preparazione += t;
    }

    return t_preparazione;
}


void stampa_ordine(FILE *menu, ordine ord)
{
    printf("\n");
    printf("+-------------------------------------+\n");
    printf("| ID: %03d\n", ord->ID);
    printf("+-------------------------------------+\n");
    printf("| Piatti:\n");

    // Stampa i nomi dei piatti dell'ordine
    stampa_nome_piatti(menu, ord->piatti);
    printf("+-------------------------------------+\n");

    // Stampa la descrizione dell'ordine se presente
    if(ord->descrizione != NULL)
    {
        printf("| Descrizione:\n| %s\n", ord->descrizione);
        printf("+-------------------------------------+\n");
    }

    printf("| Tempo stimato di preparazione: %d min.\n", ord->t_preparazione);
    printf("+-------------------------------------+\n");
}


void stampa_nome_piatti(FILE *menu, int *piatti)
{
    char temporaneo[50];
    int num;
    int spazi;

    // Il ciclo itera fin quando non trova il valore 0 nell'array piatti
    for(int i = 0; piatti[i] != 0; i++)
    {
        rewind(menu);

        // Il ciclo itera fino alla riga dove e' presente il piatto
        for(int j = 0; j < piatti[i]; j++)
        {
            fgets(temporaneo, sizeof(temporaneo), menu);
        }

        // Trova la posizione del primo '\t' e lo ignora
        spazi = strcspn(temporaneo, "\t") + 1;

        // Rimuove il carattere '\n' dalla stringa
        temporaneo[strcspn(temporaneo, "\n")] = '\0';

        // Stampa il nome del piatto ignorando i caratteri prima di esso
        printf("| %s\n", temporaneo + spazi);
    }

    rewind(menu);
}


void dealloca_ordine(ordine ord)
{
    // Se l'ordine non è stato allocato ferma la funzione
    if(ord == NULL)
        return;

    free(ord->piatti);

    // Se nell'ordine e' presente una descrizione, la dealloca
    if(ord->descrizione != NULL)
        free(ord->descrizione);

    free(ord);
}


int ottieni_tempo_di_preparazione(ordine ord)
{
    // Restituisce il tempo di preparazione dell'ordine
    return ord->t_preparazione;
}

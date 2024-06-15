#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordine.h"
#include "utili.h"

// Definizione del numero massimo di piatti per un ordine
#define MASSIMO_PIATTI 21


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
        if(scanf("%d", &num) != 1 || num > righe || num < 0)
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


int calcola_tempo_di_preparazione(FILE *tempo_di_preparazione, int *piatti)
{
    // Variabile che mantiene il tempo di preparazione letto dal file
    int t = 0;

    // Contatore che mantiene il numero di piatti inseriti nell'ordine
    int num = 0;

    // Variabile che contiene il tempo di preparazione effettivo dell'ordine
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

        // Inserisce in t_preparazione il tempo di preparazione maggiore
        // dei piatti inseriti nell'ordine e somma 2 minuti in più per ciascun piatto
        if(t > t_preparazione)
            t_preparazione = t;

        // Incrementa il numero di piatti letti nel ciclo
        num++;
    }

    // Aggiunge un minuto in più per ogni piatto presente nell'ordine
    t_preparazione += num;

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

    // Libera la memoria allocata per l'array piatti
    free(ord->piatti);

    // Se nell'ordine è presente una descrizione, la dealloca
    if(ord->descrizione != NULL)
        free(ord->descrizione);

    // Libera la memoria allocata per l'ordine stesso
    free(ord);
}


int ottieni_tempo_di_preparazione(ordine ord)
{
    // Restituisce il tempo di preparazione dell'ordine
    return ord->t_preparazione;
}

int ottieni_ID(ordine ord)
{
    // Restituisce l'ID dell'ordine
    return ord->ID;
}


ordine leggi_ordine_da_file(FILE * menu, FILE *tempo_di_preparazione, FILE *input, int ID)
{
    ordine ord;
    int *piatti;

    piatti = leggi_piatti_da_file(menu, input);
    if(piatti[0] == 0)
    {
        free(piatti);
        return NULL;
    }

    ord = malloc(sizeof(struct c_ordine));
    if(ord == NULL)
    {
        printf("Allocazione dinamica non andata a buon fine.\n");
        exit(1);
    }

    ord->ID = ID;
    ord->piatti = piatti;

    ord->descrizione = leggi_descrizione_da_file(input);

    ord->t_preparazione = calcola_tempo_di_preparazione(tempo_di_preparazione, ord->piatti);

    return ord;

}


int *leggi_piatti_da_file(FILE *menu, FILE *input)
{
    int *piatti;
    char temporaneo[50];
    int num = 0;
    int righe;

    // Legge il numero di righe del file di menu
    righe = leggi_righe_file(menu);

    // Allocazione dinamica per l'array piatti
    piatti = calloc(MASSIMO_PIATTI, sizeof(int));
    if(piatti == NULL)
    {
        printf("Allocazione dinamica non andata a buon fine.\n");
        exit(1);
    }

    // Legge i piatti dal file di input
    for(int i = 0; i < MASSIMO_PIATTI - 1; i++)
    {
        fgets(temporaneo, 50, input);
        num = atoi(temporaneo);

        // Se il numero letto non è valido, esce dal ciclo
        if(num > righe || num < 0)
        {
            i -= 1;
            continue;
        }

        // In caso in cui il valore inserito dall'utente è 0 esce dal ciclo
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


void stampa_ordine_file(FILE *menu, FILE *output, ordine ord)
{
    // Stampa l'ordine su un file di output
    fprintf(output, "\n");
    fprintf(output, "ID: %03d\n", ord->ID);
    fprintf(output, "Piatti:\n");

    // Stampa i nomi dei piatti dell'ordine su un file di output
    stampa_nome_piatti_file(menu, output, ord->piatti);

    // Stampa la descrizione dell'ordine se presente
    if(ord->descrizione != NULL)
        fprintf(output, "Descrizione:\n%s\n", ord->descrizione);

    // Stampa il tempo stimato di preparazione dell'ordine
    fprintf(output, "Tempo stimato di preparazione: %d min.\n", ord->t_preparazione);
}


void stampa_nome_piatti_file(FILE *menu, FILE *output, int *piatti)
{
    char temporaneo[50];
    int num;
    int spazi;

    // Stampa i nomi dei piatti dell'ordine su un file di output
    for(int i = 0; piatti[i] != 0; i++)
    {
        rewind(menu);

        // Il ciclo itera fino alla riga dove è presente il piatto
        for(int j = 0; j < piatti[i]; j++)
            fgets(temporaneo, 50, menu);

        // Trova la posizione del primo '\t' e lo ignora
        spazi = strcspn(temporaneo, "\t") + 1;

        // Rimuove il carattere '\n' dalla stringa
        temporaneo[strcspn(temporaneo, "\n")] = '\0';

        // Stampa il nome del piatto ignorando i caratteri prima di esso
        fprintf(output, "%s\n", temporaneo + spazi);
    }

    rewind(menu);
}


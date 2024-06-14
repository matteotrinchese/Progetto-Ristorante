#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utili.h"


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


void attesa()
{
    printf("Premi invio per continuare...");

    // Termina il ciclo solo quando l'utente inserisce '\n'
    while(getchar() != '\n');

    printf("\n");
}


char *leggi_descrizione_da_file(FILE *input)
{
    char *descrizione;
    char temporaneo[500];

    // Legge una linea di testo dal file
    if(fgets(temporaneo, 500, input) == NULL)
        return NULL;  // Se il file è vuoto o terminato, restituisce NULL

    // Rimuove il carattere '\n' finale se presente
    temporaneo[strcspn(temporaneo, "\n")] = '\0';

    // Se la linea letta è vuota, restituisce NULL
    if(temporaneo[0] == '\0')
        return NULL;

    // Alloca memoria per la descrizione
    descrizione = malloc(strlen(temporaneo) + 1);
    if(descrizione == NULL)
    {
        printf("Allocazione dinamica non andata a buon fine.\n");
        exit(1);  // Esce dal programma se malloc fallisce
    }

    // Copia la descrizione temporanea nella memoria allocata
    strcpy(descrizione, temporaneo);

    // Legge la prossima linea (se presente) per evitare sovrascritture
    fgets(temporaneo, 500, input);

    return descrizione;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordine.h"


// Definizione del tipo c_struct
struct c_ordine
{
    int ID;
    int *piatti;
    char *descrizione;
    int t_preparazione;
};


// Funzioni


ordine crea_ordine(int ID, FILE *tempo)
{
    ordine ord;

    ord = malloc(sizeof(struct c_ordine));
    if(ord == NULL)
    {
        printf("Allocazione dinamica non andata a buon fine.\n");
        exit(1);
    }

    ord->ID = ID;
    ord->piatti = leggi_piatti();
    ord->descrizione = leggi_descrizione();
    ord->t_preparazione = tempo_di_preparazione(tempo, ord->piatti);

    return ord;
}


void stampa_ordine(FILE *menu, ordine ord)
{
    printf("\n\n");
    printf("ID: %d\n\n", ord->ID);
    printf("Piatti:\n");
    stampa_nome_piatti(menu, ord->piatti);
    printf("\nDescrizione:\n%s\n\n", ord->descrizione);
    printf("Tempo stimato di preparazione: %d min.\n", ord->t_preparazione);
}


void dealloca_ordine(ordine ord)
{
    free(ord->piatti);
    free(ord->descrizione);
    free(ord);
}


char *leggi_descrizione()
{
    char *descrizione;
    char temp[500];

    printf("Inserire una descrizione dell'ordine:\n");
    fgets(temp, 500, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    descrizione = malloc(strlen(temp) + 1);
    if(descrizione == NULL)
    {
        printf("Allocazione dinamica non andata a buon fine.\n");
        exit(1);
    }

    strcpy(descrizione, temp);

    return descrizione;
}


void stampa_nome_piatti(FILE *tempo, int *piatti)
{
    char temp[50];
    int num;

    for(int i = 0; piatti[i] != 0; i++)
    {
        rewind(tempo);
        for(int j = 0; j < piatti[i]; j++)
        {
            fgets(temp, 50, tempo);
        }

        temp[strcspn(temp, "\n")] = '\0';
        printf("%s\n", temp + 2);
    }
}


int tempo_di_preparazione(FILE *tempo, int *piatti)
{
    int t = 0;
    int somma = 0;
    char temp[50];

    for(int i = 0; piatti[i] != 0; i++)
    {
        rewind(tempo);
        for(int j = 0; j < piatti[i] - 1; j++)
        {
            fgets(temp, 50, tempo);
        }
        fscanf(tempo, "%d", &t);
        fscanf(tempo, "%d", &t);
        somma += t;
    }

    return somma;
}


int *leggi_piatti()
{
    int *piatti;
    int num;

    piatti = malloc(20 * sizeof(int));
    if(piatti == NULL)
    {
        printf("Allocazione dinamica non andata a buon fine.\n");
        exit(1);
    }

    for(int i = 0; i < 20 - 1; i++)
    {
        printf("Inserisci il piatto dell'ordine (0 per terminare): ");
        scanf("%d", &num);
        while(getchar() != '\n');
        printf("%d\n", num);
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

int differenza_tempo(ordine ord1, ordine ord2)
{
    int diff;

    diff = ord1->t_preparazione - ord2->t_preparazione;
}

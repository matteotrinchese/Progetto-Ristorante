#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordine.h"

#define MASSIMO_PIATTI 20


// Definizione del tipo c_struct
struct c_ordine
{
    int ID;
    int *piatti;
    char *descrizione;
    int t_preparazione;
};


// Funzioni


ordine crea_ordine(int ID, FILE *menu, FILE *tempo)
{
    ordine ord;

    ord = malloc(sizeof(struct c_ordine));
    if(ord == NULL)
    {
        printf("Allocazione dinamica non andata a buon fine.\n");
        exit(1);
    }

    ord->ID = ID;
    ord->piatti = leggi_piatti(menu);

    if(ord->piatti[0] == 0)
        return NULL;

    ord->descrizione = leggi_descrizione();
    ord->t_preparazione = tempo_di_preparazione(tempo, ord->piatti);

    return ord;
}


void stampa_ordine(FILE *menu, ordine ord)
{
    printf("\n");
    printf("+-------------------------------------+\n");
    printf("| ID: %d\n", ord->ID);
    printf("+-------------------------------------+\n");
    printf("| Piatti:\n");
    stampa_nome_piatti(menu, ord->piatti);
    printf("+-------------------------------------+\n");
    if(ord->descrizione != NULL)
    {
        printf("| Descrizione:\n| %s\n", ord->descrizione);
        printf("+-------------------------------------+\n");
    }
    printf("| Tempo stimato di preparazione: %d min.\n", ord->t_preparazione);
    printf("+-------------------------------------+\n");
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

    if(temp[0] == '\0')
        return NULL;

    descrizione = malloc(strlen(temp) + 1);
    if(descrizione == NULL)
    {
        printf("Allocazione dinamica non andata a buon fine.\n");
        exit(1);
    }

    strcpy(descrizione, temp);

    return descrizione;
}


void stampa_nome_piatti(FILE *menu, int *piatti)
{
    char temp[50];
    int num;

    for(int i = 0; piatti[i] != 0; i++)
    {
        rewind(menu);
        for(int j = 0; j < piatti[i]; j++)
        {
            fgets(temp, 50, menu);
        }
        int spazi;
        spazi = strcspn(temp, "\t") + 1;
        temp[strcspn(temp, "\n")] = '\0';
        printf("| %s\n", temp + spazi);
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


int *leggi_piatti(FILE *menu)
{
    int *piatti;
    int num = 0;
    int righe;

    righe = leggi_righe_file(menu);

    piatti = calloc(MASSIMO_PIATTI, sizeof(int));
    if(piatti == NULL)
    {
        printf("Allocazione dinamica non andata a buon fine.\n");
        exit(1);
    }

    for(int i = 0; i < MASSIMO_PIATTI - 1; i++)
    {
        printf("Inserisci il piatto dell'ordine (0 per terminare): ");
        if(scanf("%d", &num) != 1 || num > righe)
        {
            while(getchar() != '\n');
            printf("Valore inserito non valido\n");
            i -= 1;
            continue;
        }
        while(getchar() != '\n');
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


int leggi_righe_file(FILE *fp)
{
    char temp[100];
    int righe = 0;

    while(fgets(temp, 100, fp) != NULL)
        righe++;

    return righe;
}

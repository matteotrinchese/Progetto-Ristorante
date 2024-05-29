#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "PQueue.h"


#define MASSIMO_ORDINI 20


struct c_PQ
{
    ordine ord[MASSIMO_ORDINI];
    int num_el;
};


PQueue crea_PQ()
{
    PQueue q;
    q = malloc(sizeof(struct c_PQ));
    if(q == NULL)
    {
        printf("Allocazione dinamica non andata a buon fine.\n");
        exit(1);
    }

    q->num_el = 0;

    return q;
}


int PQ_vuota(PQueue q)
{
    if(q == NULL)
        return -1;

    return q->num_el == 0;
}


ordine ottieni_testa_PQ(PQueue q)
{
    if(q == NULL)
        return NULL;

    if(q->num_el == 0)
        return NULL;

    return q->ord[1];
}


int rimuovi_testa_PQ(PQueue q)
{
    if(q == NULL)
        return 0;

    if(q->num_el == 0)
        return 0;

    q->ord[1] = q->ord[q->num_el];
    (q->num_el)--;

    scorri_PQ_verso_il_basso(q);

    return 1;
}


void scorri_PQ_verso_il_basso(PQueue q)
{
    ordine temp;
    int n = q->num_el;
    int i = 1;
    int pos;

    while(1)
    {
        if((2 * i + 1) <= n)
        {
            if(ottieni_tempo_di_preparazione(q->ord[2 * i]) < ottieni_tempo_di_preparazione(q->ord[2 * i + 1]))
                pos = i * 2;
            else
                pos = i * 2 + 1;
        }

        if(2 * i <= n)
            pos = 2 * i;
        else
            break;

        if(ottieni_tempo_di_preparazione(q->ord[pos]) < ottieni_tempo_di_preparazione(q->ord[i]))
        {
            temp = q->ord[i];
            q->ord[i] = q->ord[pos];
            q->ord[pos] = temp;
            i = pos;
        }
        else
            break;
    }
}


int aggiungi_in_PQ(PQueue q, ordine ord)
{
    if(q == NULL)
        return 0;

    // if(q->num_el == 0)
    //     return 0;

    (q->num_el)++;

    q->ord[q->num_el] = ord;

    scorri_PQ_verso_alto(q);

    return 1;
}


void scorri_PQ_verso_alto(PQueue q)
{
    ordine temp;
    int pos = q->num_el;
    int i = pos / 2;

    while(pos > 1)
    {
        if(ottieni_tempo_di_preparazione(q->ord[pos]) < ottieni_tempo_di_preparazione(q->ord[i]))
        {
            temp = q->ord[i];
            q->ord[i] = q->ord[pos];
            q->ord[pos] = temp;
            i = pos / 2;
        }
        else
            break;
    }
}


void stampa_PQ(FILE *menu, PQueue q)
{
    // stampa_ordine(menu, q->ord[1]);
    // printf("\n\n");

    for(int i = 1; i < q->num_el + 1; i++)
    {
        stampa_ordine(menu, q->ord[i]);
        printf("\n\n");
    }
}


int dealloca_PQ(PQueue q)
{
    if(q == NULL)
        return 0;

    for(int i = 1; i <= q->num_el; i++)
    {

    }
}

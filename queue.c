#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"


// Definizione del tipo struct nodo
struct nodo
{
    ordine ord;
    struct nodo *prossimo;
};


// Definizione del tipo struct c_queue
struct c_queue
{
    struct nodo *testa, *coda;
    int num_el;
};


// Funzioni


queue crea_queue()
{
    queue q;

    q = malloc(sizeof(struct c_queue));
    if(q == NULL)
    {
        printf("Allocazione dinamica non andata a buon fine.\n");
        exit(1);
    }

    q->testa = NULL;
    q->coda = NULL;
    q->num_el = 0;

    return q;
}


int queue_vuota(queue q)
{
    if(q == NULL)
        return -1;
    return q->num_el == 0;
}


int aggiungi_in_queue(queue q, ordine ord)
{
    if(q == NULL)
    {
        printf("La coda e' vuota.\n");
        return 0;
    }

    struct nodo *nuovo;
    nuovo = malloc(sizeof(struct nodo));
    if(nuovo == NULL)
    {
        printf("Allocazione dinamica non andata a buon fine.\n");
        exit(1);
    }

    nuovo->ord = ord;
    nuovo->prossimo = NULL;

    if(q->testa == NULL)
        q->testa = nuovo;
    else
        q->coda->prossimo = nuovo;

    q->coda = nuovo;
    (q->num_el)++;

    return 1;
}


ordine ottieni_testa_queue(queue q)
{
    if(q == NULL)
        return NULL;

    if(q->num_el == 0)
        return NULL;

    ordine ord = q->testa->ord;

    return ord;
}


int rimuovi_testa_queue(queue q)
{
    if(q == NULL)
        return 0;

    if(q->num_el == 0)
        return 0;

    struct nodo *temporaneo = q->testa;
    q->testa = q->testa->prossimo;

    if(q->testa == NULL)
        q->coda = NULL;

    free(temporaneo);

    (q->num_el)--;

    return 1;
}


void stampa_queue(FILE *menu, queue q)
{
    struct nodo *temporaneo;
    temporaneo = q->testa;

    while(temporaneo != NULL)
    {
        stampa_ordine(menu, temporaneo->ord);
        temporaneo = temporaneo->prossimo;
    }
}


int dealloca_queue(queue q)
{
    if(q == NULL)
        return 0;


    while(q->testa != NULL)
    {
        ordine temporaneo = ottieni_testa_queue(q);
        dealloca_ordine(temporaneo);
        rimuovi_testa_queue(q);
    }
    free(q);

    return 1;
}

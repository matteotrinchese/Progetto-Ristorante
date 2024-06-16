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

    // Allocazione dinamica per la queue
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
    // Se la queue non e' allocata restituisce 0
    if(q == NULL)
        return 0;

    // Creazione di un nuovo nodo dove contenere l'ordine da inserire nella queue
    struct nodo *nuovo;
    nuovo = malloc(sizeof(struct nodo));
    if(nuovo == NULL)
    {
        printf("Allocazione dinamica non andata a buon fine.\n");
        exit(1);
    }

    nuovo->ord = ord;
    nuovo->prossimo = NULL;

    // Se la coda e' vuota inserisce il nuovo ordine in testa alla queue
    if(q->testa == NULL)
        q->testa = nuovo;
    else
        // Se la coda possiede già ordini inserisce il nuovo ordine in coda
        q->coda->prossimo = nuovo;

    // Aggiorna il puntatore all'ultimo ordine della queue
    q->coda = nuovo;

    // Incrementa il numero di elementi presenti nella queue
    (q->num_el)++;

    return 1;
}


ordine ottieni_testa_queue(queue q)
{
    // Se la queue non e' stata allocata restituisce NULL
    if(q == NULL)
        return NULL;

    // Se la queue e' vuota restituisce NULL
    if(q->num_el == 0)
        return NULL;

    // Inserisce in ord l'ordine in testa alla queue
    ordine ord = q->testa->ord;

    return ord;
}


int rimuovi_testa_queue(queue q)
{
    // Se la queue non e' stata allocata restituisce 0
    if(q == NULL)
        return 0;

    // Se la queue e' vuota restituisce 0
    if(q->num_el == 0)
        return 0;

    // Inserisce in un nodo temporaneo la testa della queue
    struct nodo *temporaneo = q->testa;

    // Aggiorna la testa della queue
    q->testa = q->testa->prossimo;

    // Se la queue e' vuota dopo la rimozione dell'elemento aggiorna il puntatore della coda a NULL
    if(q->testa == NULL)
        q->coda = NULL;

    // Dealloca lo spazio occupato dalla precedente testa della queue
    free(temporaneo);

    // Decrementa il numero di elementi presenti nella queue
    (q->num_el)--;

    return 1;
}


void stampa_queue(FILE *menu, queue q)
{
    // Copia la testa della queue in un nodo temporaneo
    struct nodo *temporaneo;
    temporaneo = q->testa;

    while(temporaneo != NULL)
    {
        // Stampa tutti gli ordini finche' la queue non e' vuota
        stampa_ordine(menu, temporaneo->ord);
        temporaneo = temporaneo->prossimo;
    }
}


int dealloca_queue(queue q)
{
    // Se la queue non e' mai stata allocata restituisce 0
    if(q == NULL)
        return 0;


    while(q->testa != NULL)
    {
        // Dealloca l'ordine in testa finche' la queue non e' vuota
        ordine temporaneo = ottieni_testa_queue(q);
        dealloca_ordine(temporaneo);
        rimuovi_testa_queue(q);
    }

    // Dealloca lo spazio occupato da q
    free(q);

    return 1;
}


void stampa_queue_file(FILE *menu, FILE *output, queue q)
{
    // Puntatore per iterare attraverso la coda
    struct nodo *temporaneo = q->testa;

    // Itera finché non si raggiunge la fine della coda
    while (temporaneo != NULL)
    {
        // Stampa l'ordine corrente nel file di output
        stampa_ordine_file(menu, output, temporaneo->ord);
        // Passa al nodo successivo nella coda
        temporaneo = temporaneo->prossimo;
    }
}


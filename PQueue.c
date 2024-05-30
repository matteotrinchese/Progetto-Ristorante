#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "PQueue.h"


// Definizione del numero massimo di ordini contenuti nella PQueue
#define MASSIMO_ORDINI 21


struct c_PQ
{
    ordine ord[MASSIMO_ORDINI];
    int num_el;
};


PQueue crea_PQ()
{
    PQueue q;

    // Alloca lo spazio necessario per la PQueue
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
    // Se la PQueue non e' stata allocata restituisce -1
    if(q == NULL)
        return -1;

    // Se il numero di elementi contenuti nella PQueue è 0 restituisce 1,
    // in caso contrario restituisce 0
    return q->num_el == 0;
}


ordine ottieni_testa_PQ(PQueue q)
{
    // Se la PQueue non e' stata allocata o non possiede ordini
    // restituisce NULL
    if(q == NULL || q->num_el == 0)
        return NULL;


    // Restituisce l'ordine con priorita' maggiore presente
    // nella coda
    return q->ord[1];
}


int rimuovi_testa_PQ(PQueue q)
{
    // Se la PQueue non e' stata allocata o non possiede ordini
    // restituisce 0
    if(q == NULL || q->num_el == 0)
        return 0;

    // L'ultimo elemento presente nella PQueue viene spostato
    // in posizione 1
    q->ord[1] = q->ord[q->num_el];
    (q->num_el)--;

    // Sistema la PQueue trovando la posizione giusta per l'ordine spostato in posizione 1
    scorri_PQ_verso_il_basso(q);

    return 1;
}


void scorri_PQ_verso_il_basso(PQueue q)
{
    // // Variabile temporanea per lo scambio degli ordini
    // ordine temporaneo;
    //
    // // Indice dell'elemento corrente nella PQ
    // int i = 1;
    //
    // // Variabile per determinare la posizione dell'ordine da confrontare
    // int pos;
    //
    // while(1)
    // {
    //     // Controlla se l'ordine corrente ha entrambi i figli (destro e sinistro)
    //     if((2 * i + 1) <= q->num_el)
    //     {
    //         // Confronta il tempo di preparazione dei due figli e determina quale ha il valore minore
    //         if(ottieni_tempo_di_preparazione(q->ord[2 * i]) < ottieni_tempo_di_preparazione(q->ord[2 * i + 1]))
    //             pos = i * 2;            // L'ordine figlio sinistro ha il tempo di preparazione minore
    //         else
    //             pos = i * 2 + 1;        // L'ordine figlio destro ha il tempo di preparazione minore
    //     }
    //
    //
    //     // Controlla se l'ordine corrente ha solo figlio sinistro
    //     if(2 * i <= q->num_el)
    //         pos = 2 * i;
    //     else
    //         break;      // Se l'ordine non ha figli termina il ciclo
    //
    //
    //     // Confronta il tempo di preparazione dell'ordine corrente con quello del figlio determinato in pos
    //     if(ottieni_tempo_di_preparazione(q->ord[pos]) < ottieni_tempo_di_preparazione(q->ord[i]))
    //     {
    //         // Se il figlio ha un tempo di preparazione minore, scambia i due ordini
    //         temporaneo = q->ord[i];
    //         q->ord[i] = q->ord[pos];
    //         q->ord[pos] = temporaneo;
    //         // Aggiorna l'indice corrente alla posizione del figlio
    //         i = pos;
    //     }
    //     else
    //         break;      // Se l'ordine corrente ha tempo di preparazione minore o uguale al figlio, esce dal ciclo
    // }

    // Variabile temporanea per lo scambio degli ordini
    ordine temporaneo;

    // Indice dell'elemento corrente nella PQ
    int i = 1;

    while (i <= q->num_el)
    {
        // Indici dei figli sinistro e destro
        int sinistro = 2 * i;
        int destro = 2 * i + 1;

        // Teniamo traccia dell'indice del figlio con la priorità più alta (minore tempo di preparazione)
        int maggiore_priorita = i;

        // Confronta l'elemento corrente con il figlio sinistro
        if (sinistro <= q->num_el && ottieni_tempo_di_preparazione(q->ord[sinistro]) < ottieni_tempo_di_preparazione(q->ord[maggiore_priorita]))
        {
            maggiore_priorita = sinistro;
        }

        // Confronta l'elemento corrente con il figlio destro
        if (destro <= q->num_el && ottieni_tempo_di_preparazione(q->ord[destro]) < ottieni_tempo_di_preparazione(q->ord[maggiore_priorita]))
        {
            maggiore_priorita = destro;
        }

        // Se l'elemento corrente ha la priorità minore (tempo di preparazione maggiore) di entrambi i figli, scambiamo
        if (maggiore_priorita != i)
        {
            temporaneo = q->ord[i];
            q->ord[i] = q->ord[maggiore_priorita];
            q->ord[maggiore_priorita] = temporaneo;

            // Aggiorna l'indice corrente alla posizione del figlio con maggiore priorità
            i = maggiore_priorita;
        }
        else
        {
            // Se l'elemento corrente è nel posto giusto, termina il ciclo
            break;
        }
    }
}


int aggiungi_in_PQ(PQueue q, ordine ord)
{
    // Se la PQueue non e' stata allocata restituisce 0
    if(q == NULL)
        return 0;

    // Se la PQueue e' piena restituisce 0
    if(q->num_el == MASSIMO_ORDINI - 1)
        return 0;

    (q->num_el)++;

    // Inserisce l'ordine nell'ultima posizione della PQueue
    q->ord[q->num_el] = ord;

    // Sistema la PQueue trovando la posizione giusta per l'ordine inserito
    scorri_PQ_verso_alto(q);

    return 1;
}


void scorri_PQ_verso_alto(PQueue q)
{
    // Variabile temporanea per lo scambio degli ordini
    ordine temporaneo;

    // Inizializza pos alla posizione dell'ultimo ordine in PQueue
    int pos = q->num_el;

    // Inizializza l'indicatore i alla posizione del genitore dell'ultimo elemento
    int i = pos / 2;


    // Itera finchè pos non e' la posizione della radice della PQueue
    while(pos > 1)
    {
        // Confronta il tempo di preparazione dell'ordine corrente con quello del suo genitore
        if(ottieni_tempo_di_preparazione(q->ord[pos]) < ottieni_tempo_di_preparazione(q->ord[i]))
        {
            // Se l'ordine corrente ha un tempo di preparazione minore, scambia i due elementi
            temporaneo = q->ord[i];
            q->ord[i] = q->ord[pos];
            q->ord[pos] = temporaneo;

            // Aggiorna pos alla posizione del genitore
            pos = i;
            // Aggiorna i alla posizione del nuovo genitore
            i = pos / 2;
        }
        else
            break;      // Se l'ordine corrente ha tempo di preparazione maggiore o uguale al figlio, esce dal ciclo
    }
}


void stampa_PQ(FILE *menu, PQueue q)
{
    if(q == NULL || q->num_el == 0)
        return;

    ordine temporaneo[MASSIMO_ORDINI];
    int i = 0;
    int num_el_originale = q->num_el;

    while(q->num_el > 0)
    {
        ordine ord = ottieni_testa_PQ(q);

        temporaneo[i++] = ord;
        stampa_ordine(menu, ord);
        rimuovi_testa_PQ(q);
    }

    for(int j = 0; j < num_el_originale; j++)
    {
        aggiungi_in_PQ(q, temporaneo[j]);
    }
}


int dealloca_PQ(PQueue q)
{
    if(q == NULL)
        return 0;

    while(q->num_el > 0)
    {
        ordine temporaneo = ottieni_testa_PQ(q);
        dealloca_ordine(temporaneo);
        rimuovi_testa_PQ(q);
    }

    free(q);

    return 1;
}
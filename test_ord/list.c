#include <stdio.h>
#include <stdlib.h>
#include"ordine.h"
#include "list.h"

struct nodo
{
    ordine ord;
    struct nodo *prossimo;
};

lista Inserici_elem_lista(lista list_ord, ordine ord)
{
    lista nuovo = malloc(sizeof(struct nodo));

    nuovo->ord = ord;
    nuovo->prossimo = list_ord;
    list_ord = nuovo;

    return list_ord;
}

void ordina_elementi(lista list_ordine)
{
    lista i;
    lista j;
    lista temp;
    int diff1 = 0, diff2 = 0;

    for(i = list_ordine; i != NULL && i->prossimo != NULL; i = i->prossimo)
    {
        for(j = i->prossimo; j != NULL; j = j->prossimo)
        {
            if((diff1=differenza_tempo(i->ord, j->ord)) >10 || (diff1=differenza_tempo(j->ord, i->ord)) >10)
            {
                temp = i;
                i = j;
                j = temp;
            }
        }
    }
}

void Stampa_lista(FILE *fp, lista list_ord)
{
    lista temp;
    temp = list_ord;
    while(temp != NULL)
    {
        stampa_ordine(fp, temp->ord);
        temp = temp->prossimo;
    }
}

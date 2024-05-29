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

void scambia_ordini(struct nodo *ord1, struct nodo*ord2)
{
    ordine temp = ord1->ord;
    ord1->ord = ord2->ord;
    ord2->ord = temp;
}

lista ordina_elementi(lista list_ordine)
{
    if(list_ordine == NULL || list_ordine->prossimo == NULL)
    {
        return list_ordine;
    }

    int scambiati;
    lista ptr1, ptr2 = NULL;

    do
    {
        scambiati = 0;
        ptr1 = list_ordine;

        while (ptr1->prossimo != ptr2)
        {
            if(prendi_t_preparazione(ptr1->ord) < prendi_t_preparazione(ptr1->prossimo->ord))
            {
                scambia_ordini(ptr1, ptr1->prossimo);
                scambiati = 1;
            }
            ptr1 = ptr1->prossimo;
        }
        
        ptr2 = ptr1;
    } while (scambiati);
    
    return list_ordine;
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"
#include "list.h"


int main()
{
    struct nodo *list_ord;
    FILE *menu = fopen("MENU.txt", "r");
    FILE *tempo_di_preparazione = fopen("PREPARAZIONE.txt", "r");

    ordine ord1 = crea_ordine(1, tempo_di_preparazione);
    ordine ord2 = crea_ordine(2, tempo_di_preparazione);
    ordine ord3 = crea_ordine(3, tempo_di_preparazione);
    ordine ord4 = crea_ordine(4, tempo_di_preparazione);
    ordine ord5 = crea_ordine(5, tempo_di_preparazione);

    list_ord = Inserici_elem_lista(list_ord, ord1);
    list_ord = Inserici_elem_lista(list_ord, ord2);
    list_ord = Inserici_elem_lista(list_ord, ord3);
    list_ord = Inserici_elem_lista(list_ord, ord4);
    list_ord = Inserici_elem_lista(list_ord, ord5);



    Stampa_lista(menu, list_ord);

    ordina_elementi(list_ord);

    Stampa_lista(menu, list_ord);

}

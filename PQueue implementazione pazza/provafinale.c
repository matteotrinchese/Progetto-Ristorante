#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "PQueue.h"

int main()
{
    PQueue q;
    FILE *menu, *tempo;
    ordine ord1, ord2, ord3, ord4;

    menu = fopen("MENU.txt", "r");
    if(menu == NULL)
    {
        printf("Apertura file fallita.\n");
        exit(1);
    }

    tempo = fopen("PREPARAZIONE.txt", "r");
    if(tempo == NULL)
    {
        printf("Apertura file fallita.\n");
        exit(1);
    }

    q = crea_PQ();
    ord1 = crea_ordine(menu, tempo, 1);

    ord2 = crea_ordine(menu, tempo, 2);

    ord3 = crea_ordine(menu, tempo, 3);

    ord4 = crea_ordine(menu, tempo, 4);

    aggiungi_in_PQ(q, ord1);
    aggiungi_in_PQ(q, ord2);
    aggiungi_in_PQ(q, ord3);
    aggiungi_in_PQ(q, ord4);

    stampa_PQ(menu, q);

    ordine ordsmiao;

    ordsmiao = ottieni_testa_PQ(q);

    stampa_ordine(menu, ordsmiao);
    rimuovi_testa_PQ(q);


    stampa_ordine(menu, ottieni_testa_PQ(q));
    rimuovi_testa_PQ(q);

    stampa_ordine(menu, ottieni_testa_PQ(q));
    rimuovi_testa_PQ(q);

    stampa_ordine(menu, ottieni_testa_PQ(q));
    rimuovi_testa_PQ(q);



    return 0;

}

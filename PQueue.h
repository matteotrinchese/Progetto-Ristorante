#include "ordine.h"


typedef struct c_PQ *PQueue;


PQueue crea_PQ();


int PQ_vuota(PQueue q);


ordine ottieni_testa_PQ(PQueue q);


int rimuovi_testa_PQ(PQueue q);


void scorri_PQ_verso_il_basso(PQueue q);


int aggiungi_in_PQ(PQueue q, ordine ord);


void scorri_PQ_verso_alto(PQueue q);


void stampa_PQ(FILE *menu, PQueue q);


int dealloca_PQ(PQueue q);

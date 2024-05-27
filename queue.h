#include "ordine.h"


// Definizione del tipo queue
typedef struct c_queue *queue;


// Prototipi


// Alloca lo spazio necessario per la queue
queue crea_queue();


// Controlla se la queue è vuota
int queue_vuota(queue);


// Aggiunge un elemento in coda alla queue
int aggiungi_in_queue(queue, ordine);


// Legge l'elemento in testa alla queue
ordine ottieni_testa_queue(queue);


// Rimuove l'elemento in testa alla queue
int rimuovi_testa_queue(queue);


// Stampa a schermo le informazioni contenute nella queue
void stampa_queue(FILE *, queue);


// Dealloca lo spazio occupato dalla queue
int dealloca_queue(queue);


// Ordina la coda di ordini in base al tempo di preparazione e all'ID





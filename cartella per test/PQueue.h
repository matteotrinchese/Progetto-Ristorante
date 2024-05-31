#include "ordine.h"


typedef struct c_PQ *PQueue;


// Prototipi


/*
 * Specifica sintattica:
 * - crea_PQ() -> PQueue
 * - tipi: PQueue
 *
 * Specifica semantica:
 * - Funzione: crea_PQ() -> PQueue
 * - Descrizione: Alloca lo spazio necessario per la queue a priorità.
 * - Pre-condizioni: //
 * - Post-condizioni: la funzione restituisce la nuova queue creata, in caso in cui non
 *                    venga allocata allora restituirà NULL.
 *
 */
PQueue crea_PQ();


/*
 * Specifica sintattica:
 * - PQueue_vuota(PQueue) -> int
 * - tipi: PQueue ed int
 *
 * Specifica semantica:
 * - Funzione: PQueue_vuota(q) -> int
 * - Descrizione: Controlla se la queue a priorità è vuota.
 * - Pre-condizioni: la PQueue deve essere correttamente creata ed allocata.
 * - Post-condizioni: la funzione restituisce un intero, -1 se la queue a priorità è NULL,
 *                    1 se la queue a priorità non ha elementi e 0 se ha degli elementi.
 *
 */
int PQ_vuota(PQueue);


/*
 * Specifica sintattica:
 * - ottieni_testa_PQ(PQueue) -> ordine
 * - tipi: PQueue ed ordine
 *
 * Specifica semantica:
 * - Funzione: ottieni_testa_PQ(q) -> ordine
 * - Descrizione: Legge l'elemento in testa alla queue a priorità.
 * - Pre-condizioni: la queue a priorità deve essere correttamente creata ed allocata.
 * - Post-condizioni: la funzione restituisce l'ordine in testa alla queue a priorità se ha degli elementi,
 *                    restituisce NULL se la queue a priorità non ha elementi o se è NULL.
 *
 */
ordine ottieni_testa_PQ(PQueue);


/*
 * Specifica sintattica:
 * - rimuovi_testa_PQ(PQueue) -> int
 * - tipi: PQueue ed int
 *
 * Specifica semantica:
 * - Funzione: rimuovi_testa_PQ(q) -> int
 * - Descrizione: Rimuove l'elemento in testa alla queue a priorità.
 * - Pre-condizioni: la queue a priorità deve essere correttamente creata ed allocata.
 * - Post-condizioni: la funzione restituisce un intero, 1 se la rimozione avviene con successo
 *                    0 se la queue a priorità è NULL o ha zero elementi.
 *
 */
int rimuovi_testa_PQ(PQueue);


/*
 * Specifica sintattica:
 * - scorri_PQ_verso_il_basso(PQueue) -> void
 * - tipi: PQueue
 *
 * Specifica semantica:
 * - Funzione: scorri_PQ_verso_il_basso(q) -> void
 * - Descrizione: Scorre dall'alto verso il basso la queue a priorità.
 * - Pre-condizioni: la queue a priorità deve essere correttamente creata ed allocata.
 * - Post-condizioni: la funzione scorre dall'alto verso il basso la queue a priorità andando poi a scambiare gli indirizzi di memoria 
 *                    all'interno della queue stessa.
 *
 */
void scorri_PQ_verso_il_basso(PQueue);


/*
 * Specifica sintattica:
 * - aggiungi_in_PQ(PQueue, ordine) -> int
 * - tipi: PQueue, ordine ed int
 *
 * Specifica semantica:
 * - Funzione: aggiungi_in_PQ(q, ord) -> int
 * - Descrizione: Aggiunge un elemento in coda alla queue a priorità.
 * - Pre-condizioni: la queue a priorità deve essere correttamente creata ed allocata,
 *                   l'ordine deve essere allocato correttamente e deve contenere degli elementi.
 * - Post-condizioni: la funzione restituisce un intero, 1 se ha inserimento correttamente
 *                    l'ordine nella PQueue 0 invece se la queue a priorità è NULL oppure è piena.
 *
 */
int aggiungi_in_PQ(PQueue,  ordine);


/*
 * Specifica sintattica:
 * - scorri_PQ_verso_alto(PQueue) -> void
 * - tipi: PQueue
 *
 * Specifica semantica:
 * - Funzione: scorri_PQ_verso_alto(q) -> void
 * - Descrizione: Scorre dal basso verso l'alto la queue a priorità.
 * - Pre-condizioni: la queue a priorità deve essere correttamente creata ed allocata.
 * - Post-condizioni: la funzione scorre dal basso verso l'alto la queue a priorità andando poi a scambiare gli indirizzi di memoria 
 *                    all'interno della queue stessa.
 *
 */
void scorri_PQ_verso_alto(PQueue);


/*
 * Specifica sintattica:
 * - stampa_PQ(FILE *, PQueue) -> void
 * - tipi: puntatore ad un file e PQueue
 *
 * Specifica semantica:
 * - Funzione: stampa_PQ(menu, q) -> void
 * - Descrizione: Stampa a schermo le informazioni contenute nella queue a priorità.
 * - Pre-condizioni: la queue a priorità deve essere correttamente creata ed allocata
 *                   ed il puntatore al file deve essere aperto correttamente.
 * - Post-condizioni: La funzione stampa a video tutta la queue a priorità contenente gli ordini in attesa.
 *
 */
void stampa_PQ(FILE *, PQueue);


/*
 * Specifica sintattica:
 * - dealloca_PQ(queue) -> int
 * - tipi: PQueue ed int
 *
 * Specifica semantica:
 * - Funzione: dealloca_PQ(q) -> int
 * - Descrizione: Dealloca lo spazio occupato dalla queue a priorità.
 * - Pre-condizioni: la queue a priorità deve essere correttamente creata ed allocata.
 * - Post-condizioni: La funzione restituisce un intero, 0 se la queue a priorità è NULL
 *                    invece 1 se ha deallocato correttamente la memoria.
 *
 */
int dealloca_PQ(PQueue);


int PQ_piena(PQueue);

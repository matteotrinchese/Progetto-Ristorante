#include "ordine.h"

// Definizione del tipo PQueue
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
int rimuovi_testa_PQ(PQueue q);


void scorri_PQ_verso_il_basso(PQueue q);


int aggiungi_in_PQ(PQueue q, ordine ord);


void scorri_PQ_verso_alto(PQueue q);


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
void stampa_PQ(FILE *menu, PQueue q);


int dealloca_PQ(PQueue q);

#include "ordine.h"


// Definizione del tipo queue
typedef struct c_queue *queue;


// Prototipi


/*
 * Specifica sintattica:
 * - crea_queue() -> queue
 * - tipi: void
 *
 * Specifica semantica:
 * - Funzione: crea_queue(menu, tempo_di_preparazione, ID) -> queue
 * - Descrizione: Alloca lo spazio necessario per la queue.
 * - Pre-condizioni: //
 * - Post-condizioni: la funzione restituisce la nuova coda creata, in caso in cui non
 *                    venga allocata allora restituirà NULL.
 *
 */
queue crea_queue();


/*
 * Specifica sintattica:
 * - queue_vuota(queue) -> int
 * - tipi: queue ed int
 *
 * Specifica semantica:
 * - Funzione: queue_vuota(q) -> int
 * - Descrizione: Controlla se la queue è vuota.
 * - Pre-condizioni: la queue deve essere correttamente creata ed allocata.
 * - Post-condizioni: la funzione restituisce un intero, -1 se la queue è NULL,
 *                    1 se la queue non ha elementi ed 0 se ha degli elementi.
 *
 */
int queue_vuota(queue);


/*
 * Specifica sintattica:
 * - aggiungi_in_queue(queue, ordine) -> int
 * - tipi: queue, ordine ed int
 *
 * Specifica semantica:
 * - Funzione: aggiungi_in_queue(q, ord) -> int
 * - Descrizione: Aggiunge un elemento in coda alla queue.
 * - Pre-condizioni: la queue deve essere correttamente creata ed allocata, l'ordine deve essere allocato correttamente 
 *                   e deve contenere degli elementi.
 * - Post-condizioni: la funzione restituisce un intero, 1 se ha inserimento correttamente l'ordine nella queue
 *                    0 invece se la queue è NULL.
 *
 */
int aggiungi_in_queue(queue, ordine);


/*
 * Specifica sintattica:
 * - ottieni_testa_queue(queue) -> ordine
 * - tipi: queue ed ordine
 *
 * Specifica semantica:
 * - Funzione: ottieni_testa_queue(q) -> ordine
 * - Descrizione: Legge l'elemento in testa alla queue.
 * - Pre-condizioni: la queue deve essere correttamente creata ed allocata.
 * - Post-condizioni: la funzione restituisce l'ordine in testa alla queue se ha egli elementi,
 *                    restituisce NULL se la queue non ha elementi e se la queueu è NULL.
 *
 */
ordine ottieni_testa_queue(queue);


// Rimuove l'elemento in testa alla queue
int rimuovi_testa_queue(queue);


// Stampa a schermo le informazioni contenute nella queue
void stampa_queue(FILE *, queue);


// Dealloca lo spazio occupato dalla queue
int dealloca_queue(queue);


// Ordina la coda di ordini in base al tempo di preparazione e all'ID





#include <stdio.h>


typedef struct c_ordine *ordine;


// Prototipi


/*
 * Specifica sintattica:
 * - crea_ordine(FILE *, FILE *, int) -> ordine
 * - tipi: puntatore a file e interi
 *
 * Specifica semantica:
 * - Funzione: crea_ordine(menu, tempo_di_preparazione, ID) -> ordine
 * - Descrizione: Crea un nuovo ordine
 * - Pre-condizioni: I file devono essere stati correttamente aperti e il valore ID deve essere un intero
 * - Post-condizioni: la funzione restituisce il nuovo ordine creato, in caso in cui non
 *                    vengono inseriti piatti la funzione restituisce NULL
 *
 */
ordine crea_ordine(FILE *menu, FILE *tempo_di_preparazione, int ID);


/*
 * Specifica sintattica:
 * - stampa_ordine(FILE *, ordine) -> void
 * - tipi: puntatore a file e ordine
 *
 * Specifica semantica:
 * - Funzione: stampa_ordine(menu, ord) -> void
 * - Descrizione: Stampa a schermo le informazioni dell'ordine
 * - Pre-condizioni: Il file deve esser stato correttamente aperto e ord deve puntare
 *                   a un ordine valido
 * - Post-condizioni: la funzione non restituisce valori ma stampa a schermo le informazioni
 *                    dell'ordine
 */
void stampa_ordine(FILE *menu, ordine ord);


// Dealloca lo spazio utilizzato dall'item
void dealloca_ordine(ordine ord);


// Legge l'eventuale descrizione inserita per l'ordine
char *leggi_descrizione();


// Stampa il nome dei piatti in base al numero inserito dal file
void stampa_nome_piatti(FILE *menu, int *piatti);


// Ottiene da un file i valori dei tempi di preparazione di cib
int calcola_tempo_di_preparazione(FILE *tempo_di_preparazione, int *piatti);


// Legge i piatti che vengono inseriti dall'utente e li inserisce in un array
int *leggi_piatti(FILE *menu);


// Funzione che legge le righe di un file
int leggi_righe_file(FILE *file);


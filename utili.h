#include <stdio.h>


/*
 * Specifica sintattica:
 * - leggi_righe_file(FILE *) -> int
 * - tipi: puntatore a file e int
 *
 * Specifica semantica:
 * - Funzione: leggi_righe_file(file) -> righe
 * - Descrizione: Legge il numero di righe nel file in input alla funzione.
 * - Pre-condizioni: il file deve esser stato correttamente aperto.
 * - Post-condizioni: la funzione restituisce il numero di righe presente nel file.
 *
 */
int leggi_righe_file(FILE *file);


/*
 * Specifica sintattica:
 * - leggi_descrizione(void) -> char *
 * - tipi: char *
 *
 * Specifica semantica:
 * - Funzione: leggi_descrizione() -> descrizione
 * - Descrizione: Legge e alloca dinamicamente la descrizione inserita per l'ordine.
 * - Pre-condizioni: nessuna.
 * - Post-condizioni: la funzione resitutisce la stringa che contiene la descrizione,
 *                    in caso in cui l'utente non inserisce una stringa (inserisce '\n'), la funzione
 *                    restituisce NULL.
 *
 */
char *leggi_descrizione();


/*
 * Specifica sintattica:
 * - attesa(void) -> void
 * - tipi: nessuno
 *
 * Specifica semantica:
 * - Funzione: attesa(void) -> void
 * - Descrizione: Chiede all'utente di premere invio per proseguire.
 * - Pre-condizioni: nessuna.
 * - Post-condizioni: La funzione non restituisce nessun valore però richiede all'utente di
 *                    premere invio per proseguire nell'esecuzione del programma.
 *
 */
void attesa();





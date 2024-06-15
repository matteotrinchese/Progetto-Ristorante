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
 * - Descrizione: Crea un nuovo ordine.
 * - Pre-condizioni: I file devono essere stati correttamente aperti e il valore ID deve essere un intero
 * - Post-condizioni: la funzione restituisce il nuovo ordine creato, in caso in cui non
 *                    vengono inseriti piatti la funzione restituisce NULL.
 *
 */
ordine crea_ordine(FILE *menu, FILE *tempo_di_preparazione, int ID);


/*
 * Specifica sintattica:
 * - leggi_piatti(FILE *) -> int *
 * - tipi: puntatore a file e puntatore ad int
 *
 * Specifica semantica:
 * - Funzione: leggi_piatti(menu) -> piatti
 * - Descrizione: Leggi il numero dei piatti inseriti dall'utente e li inserisce nel vettore piatti.
 * - Pre-condizioni: il file deve esser stato correttamente aperto.
 * - Post-condizioni: la funzione restituisce il vettore piatti che contiene i numeri inseriti dall'utente,
 *                    in caso in cui l'utente non inserisce un valore valido esso non viene inserito
 *                    nel vettore piatti.
 *
 */
int *leggi_piatti(FILE *menu);


/*
 * Specifica sintattica:
 * - calcola_tempo_di_preparazione(FILE *, int *) -> int
 * - tipi: puntatore a file e puntatore ad int
 *
 * Specifica semantica:
 * - Funzione: calcola_tempo_di_preparazione(tempo_di_preparazione, piatti) -> t_preparazione
 * - Descrizione: Calcola il tempo stimato di preparazione in base ai patti inseriti nell'ordine
 * - Pre-condizioni: il file deve esser stato correttamente aperto
 * - Post-condizioni: la funzione restituisce t_preparazione che contiene la somma dei tempi di
 *                    preparazione di ciascun piatto.
 *
 */
int calcola_tempo_di_preparazione(FILE *tempo_di_preparazione, int *piatti);


/*
 * Specifica sintattica:
 * - stampa_ordine(FILE *, ordine) -> void
 * - tipi: puntatore a file e ordine
 *
 * Specifica semantica:
 * - Funzione: stampa_ordine(menu, ord) -> void
 * - Descrizione: Stampa a schermo le informazioni dell'ordine.
 * - Pre-condizioni: Il file deve esser stato correttamente aperto e ord deve puntare
 *                   a un ordine valido.
 * - Post-condizioni: la funzione non restituisce valori ma stampa a schermo le informazioni
 *                    dell'ordine.
 *
 */
void stampa_ordine(FILE *menu, ordine ord);


/*
 * Specifica sintattica:
 * - stampa_nome_piatti(FILE *, int *) -> void
 * - tipi: puntatore a file e puntatore ad int
 *
 * Specifica semantica:
 * - Funzione: stampa_nome_piatti(menu, piatti) -> void
 * - Descrizione: Stampa a schermo il nome del piatto associato al numero inserito nel vettore piatti.
 * - Pre-condizioni: il file deve esser stato correttamente aperto.
 * - Post-condizioni: la funzione non restituisce valori ma stampa a schermo il nome del piatto
 *                    associato al valore inserito dall'utente nel vettore piatti.
 *
 */
void stampa_nome_piatti(FILE *menu, int *piatti);


/*
 * Specifica sintattica:
 * - dealloca_ordine(ordine) -> void
 * - tipi: ordine
 *
 * Specifica semantica:
 * - Funzione: stampa_ordine(ord) -> void
 * - Descrizione: dealloca le informazioni contenute nell'ordine.
 * - Pre-condizioni: ord deve puntare ad un ordine valido.
 * - Post-condizioni: la funzione non restituisce valori ma dealloca le informazioni
 *                    contenute nell'ordine.
 */
void dealloca_ordine(ordine ord);


/*
 * Specifica sintattica:
 * - ottieni_tempo_di_preparazione(ordine) -> int
 * - tipi: ordine
 *
 * Specifica semantica:
 * - Funzione: ottieni_tempo_di_preparazione(ord) -> int
 * - Descrizione: Restituisce il tempo di preparaizione.
 * - Pre-condizioni: ord deve puntare ad un ordine valido.
 * - Post-condizioni: la funzione restituisce il tempo di preparazione dell'ordine passato.
 */
int ottieni_tempo_di_preparazione(ordine ord);


int ottieni_ID(ordine ord);

/*
 * Specifica sintattica:
 * - leggi_ordine_da_file(FILE *, FILE *, FILE *, int) -> ordine
 * - tipi: puntatore a file e interi
 *
 * Specifica semantica:
 * - Funzione: leggi_ordine_da_file(menu, tempo_di_preparazione, input, ID) -> ordine
 * - Descrizione: Legge un ordine da un file di input e lo crea.
 * - Pre-condizioni: I file devono essere stati correttamente aperti e il valore ID deve essere un intero.
 * - Post-condizioni: La funzione restituisce il nuovo ordine creato leggendo le informazioni dal file
 *                    di input, in caso in cui non vengono inseriti piatti la funzione restituisce NULL.
 */
ordine leggi_ordine_da_file(FILE * menu, FILE *tempo_di_preparazione, FILE *input, int ID);


/*
 * Specifica sintattica:
 * - leggi_piatti_da_file(FILE *, FILE *) -> int *
 * - tipi: puntatore a file
 *
 * Specifica semantica:
 * - Funzione: leggi_piatti_da_file(menu, input) -> piatti
 * - Descrizione: Legge i numeri dei piatti da un file di input e li inserisce nel vettore piatti.
 * - Pre-condizioni: I file devono essere stati correttamente aperti.
 * - Post-condizioni: La funzione restituisce il vettore piatti che contiene i numeri letti dal file
 *                    di input, in caso in cui l'utente non inserisce un valore valido esso non viene
 *                    inserito nel vettore piatti.
 */
int *leggi_piatti_da_file(FILE *menu, FILE *input);


/*
 * Specifica sintattica:
 * - stampa_ordine_file(FILE *, FILE *, ordine) -> void
 * - tipi: puntatore a file e ordine
 *
 * Specifica semantica:
 * - Funzione: stampa_ordine_file(menu, output, ord) -> void
 * - Descrizione: Stampa su un file le informazioni dell'ordine.
 * - Pre-condizioni: I file devono essere stati correttamente aperti e ord deve puntare
 *                   a un ordine valido.
 * - Post-condizioni: La funzione non restituisce valori ma stampa su un file le informazioni
 *                    dell'ordine.
 */
void stampa_ordine_file(FILE *menu, FILE *output, ordine ord);


/*
 * Specifica sintattica:
 * - stampa_nome_piatti_file(FILE *, FILE *, int *) -> void
 * - tipi: puntatore a file e puntatore ad int
 *
 * Specifica semantica:
 * - Funzione: stampa_nome_piatti_file(menu, output, piatti) -> void
 * - Descrizione: Stampa su un file il nome del piatto associato al numero inserito nel vettore piatti.
 * - Pre-condizioni: I file devono essere stati correttamente aperti.
 * - Post-condizioni: La funzione non restituisce valori ma stampa su un file il nome del piatto
 *                    associato al valore inserito dall'utente nel vettore piatti.
 */
void stampa_nome_piatti_file(FILE *menu, FILE *output, int *piatti);

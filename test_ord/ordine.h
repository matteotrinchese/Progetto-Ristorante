#include <stdio.h>


// Definizione del tipo ordine
typedef struct c_ordine *ordine;


// Prototipi


// Crea un nuovo item e alloca dinamicamente lo spazio necessario
ordine crea_ordine(int, FILE *);


// Stampa a schermo le informazioni dell'item
void stampa_ordine(FILE *, ordine);


// Dealloca lo spazio utilizzato dall'item
void dealloca_ordine(ordine);


// Legge l'eventuale descrizione inserita per l'ordine
char *leggi_descrizione();




// Stampa il nome dei piatti in base al numero inserito dal file
void stampa_nome_piatti(FILE *, int *);


// Ottiene da un file i valori dei tempi di preparazione di cib
int tempo_di_preparazione(FILE *, int *);


// Legge i piatti che vengono inseriti dall'utente e li inserisce in un array
int *leggi_piatti();

// restituisce il tempo di preparazione di un ordine
int prendi_t_preparazione(ordine);
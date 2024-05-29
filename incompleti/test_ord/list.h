
typedef struct nodo *lista;


// Ordina la coda di ordini in base al tempo di preparazione e all'ID


lista ordina_elementi(lista);


// Inserisce gli ordini all'interno di una lista

lista Inserici_elem_lista(lista, ordine);


// Stampa lista degli ordini

void Stampa_lista(FILE *, lista);

void scambia_ordini(struct nodo *, struct nodo*);
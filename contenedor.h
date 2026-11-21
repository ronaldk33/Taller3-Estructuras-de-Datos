
#ifndef CONTENEDOR_H
#define CONTENEDOR_H

typedef struct Contenedor {
    int id;

    float tara;
    float pesoCarga;
    float pesoTotal;
    float costo;

    struct Contenedor *anterior;
    struct Contenedor *siguiente;

} Contenedor;

// Apuntadores principales
extern Contenedor *inicio;
extern Contenedor *fin;

// Generador de identificadores
extern int siguienteID;

#endif

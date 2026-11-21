
#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"


// ==========================================
// 1. INSERTAR CONTENEDOR
// ==========================================

void insertarContenedor() {

    Contenedor *nuevo = malloc(sizeof(Contenedor));

    if (nuevo == NULL) {
        printf("\nError al reservar memoria.\n");
        return;
    }

    nuevo->id = siguienteID;
    siguienteID++;

    printf("\n--- REGISTRAR CONTENEDOR ---\n");

    printf("Ingrese la tara: ");
    scanf("%f", &nuevo->tara);

    printf("Ingrese el peso de carga: ");
    scanf("%f", &nuevo->pesoCarga);

    printf("Ingrese el peso total: ");
    scanf("%f", &nuevo->pesoTotal);

    printf("Ingrese el costo: ");
    scanf("%f", &nuevo->costo);

    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;

    if (inicio == NULL) {

        inicio = nuevo;
        fin = nuevo;

    } else {

        nuevo->anterior = fin;
        fin->siguiente = nuevo;
        fin = nuevo;

    }

    printf("\nContenedor registrado correctamente.\n");
    printf("Identificador asignado: %d\n", nuevo->id);
}


// ==========================================
// 2. BUSCAR CONTENEDOR
// ==========================================

void buscarContenedor() {

    int idBuscar;
    Contenedor *actual = inicio;

    if (inicio == NULL) {
        printf("\nNo hay contenedores registrados.\n");
        return;
    }

    printf("\nIngrese el ID del contenedor: ");
    scanf("%d", &idBuscar);

    while (actual != NULL) {

        if (actual->id == idBuscar) {

            printf("\n--- CONTENEDOR ENCONTRADO ---\n");

            printf("ID: %d\n", actual->id);
            printf("Tara: %.2f\n", actual->tara);
            printf("Peso de carga: %.2f\n", actual->pesoCarga);
            printf("Peso total: %.2f\n", actual->pesoTotal);
            printf("Costo: %.2f\n", actual->costo);

            return;
        }

        actual = actual->siguiente;
    }

    printf("\nNo se encontro el contenedor.\n");
}


// ==========================================
// 3. ACTUALIZAR CONTENEDOR
// ==========================================

void actualizarContenedor() {

    int idBuscar;
    Contenedor *actual = inicio;

    if (inicio == NULL) {
        printf("\nNo hay contenedores registrados.\n");
        return;
    }

    printf("\nIngrese el ID del contenedor a actualizar: ");
    scanf("%d", &idBuscar);

    while (actual != NULL) {

        if (actual->id == idBuscar) {

            printf("\n--- ACTUALIZAR CONTENEDOR ---\n");

            printf("Nueva tara: ");
            scanf("%f", &actual->tara);

            printf("Nuevo peso de carga: ");
            scanf("%f", &actual->pesoCarga);

            printf("Nuevo peso total: ");
            scanf("%f", &actual->pesoTotal);

            printf("Nuevo costo: ");
            scanf("%f", &actual->costo);

            printf("\nContenedor actualizado correctamente.\n");

            return;
        }

        actual = actual->siguiente;
    }

    printf("\nNo se encontro el contenedor.\n");
}


// ==========================================
// 4. ELIMINAR CONTENEDOR
// ==========================================

void eliminarContenedor() {

    int idEliminar;
    Contenedor *actual = inicio;

    if (inicio == NULL) {
        printf("\nNo hay contenedores registrados.\n");
        return;
    }

    printf("\nIngrese el ID del contenedor a eliminar: ");
    scanf("%d", &idEliminar);

    while (actual != NULL && actual->id != idEliminar) {

        actual = actual->siguiente;
    }

    if (actual == NULL) {

        printf("\nNo se encontro el contenedor.\n");
        return;
    }

    // Actualizar el enlace anterior
    if (actual->anterior != NULL) {

        actual->anterior->siguiente = actual->siguiente;

    } else {

        inicio = actual->siguiente;
    }

    // Actualizar el enlace siguiente
    if (actual->siguiente != NULL) {

        actual->siguiente->anterior = actual->anterior;

    } else {

        fin = actual->anterior;
    }

    free(actual);

    printf("\nContenedor eliminado correctamente.\n");
}


// ==========================================
// 5. MOSTRAR TODOS LOS CONTENEDORES
// ==========================================

void mostrarContenedores() {

    Contenedor *actual = inicio;

    if (inicio == NULL) {

        printf("\nNo hay contenedores registrados.\n");
        return;
    }

    printf("\n--- LISTADO DE CONTENEDORES ---\n");

    while (actual != NULL) {

        printf("\nID: %d\n", actual->id);
        printf("Tara: %.2f\n", actual->tara);
        printf("Peso de carga: %.2f\n", actual->pesoCarga);
        printf("Peso total: %.2f\n", actual->pesoTotal);
        printf("Costo: %.2f\n", actual->costo);

        actual = actual->siguiente;
    }
}

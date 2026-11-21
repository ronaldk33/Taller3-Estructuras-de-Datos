
#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main() {

    int opcion;

    do {

        printf("\n====================================\n");
        printf(" SISTEMA DE GESTION DE CONTENEDORES\n");
        printf("====================================\n");

        printf("1. Registrar contenedor\n");
        printf("2. Buscar contenedor\n");
        printf("3. Actualizar contenedor\n");
        printf("4. Eliminar contenedor\n");
        printf("5. Mostrar contenedores\n");
        printf("6. Salir\n");

        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {

            case 1:
                insertarContenedor();
                break;

            case 2:
                buscarContenedor();
                break;

            case 3:
                actualizarContenedor();
                break;

            case 4:
                eliminarContenedor();
                break;

            case 5:
                mostrarContenedores();
                break;

            case 6:
                printf("\nSaliendo del sistema...\n");
                break;

            default:
                printf("\nOpcion no valida.\n");
        }

    } while (opcion != 6);

    return 0;
}

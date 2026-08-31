#include <stdio.h>
#include <string.h>
#include "agenda.h"

void limpiarBuffer(void) {
    while (getchar() != '\n');
}

void leerTexto(char *buffer, int tamano) {
    fgets(buffer, tamano, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int main(void) {
    Agenda agenda;
    inicializarAgenda(&agenda);

    int opcion;
    char nombre[50], apellido[50], telefono[20];

    printf("\n-Agenda de Contactos-\n");

    do {
        printf("1. Agregar nuevo contacto\n");
        printf("2. Listar todos los contactos\n");
        printf("3. Salir\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1:
                printf("Nombre: ");
                leerTexto(nombre, sizeof(nombre));
                printf("Apellido: ");
                leerTexto(apellido, sizeof(apellido));
                printf("Telefono: ");
                leerTexto(telefono, sizeof(telefono));

                agregarContacto(&agenda, nombre, apellido, telefono);
                printf("\nContacto agregado con exito.\n\n");
                break;
            case 2:
                listarContactos(&agenda);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("\nOpcion invalida.\n\n");
        }

    } while (opcion != 3);

    liberarAgenda(&agenda);

    return 0;
}

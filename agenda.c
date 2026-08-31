#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

void inicializarAgenda(Agenda *agenda) {
    agenda->contactos = NULL;
    agenda->cantidad = agenda->capacidad = 0;
}

void agregarContacto(Agenda *agenda, const char *nombre, const char *apellido, const char *telefono) {
    if (agenda->cantidad == agenda->capacidad) {
        agenda->capacidad = agenda->capacidad ? agenda->capacidad * 2 : 4;
        agenda->contactos = realloc(agenda->contactos, agenda->capacidad * sizeof(Contacto *));
    }

    Contacto *contacto = malloc(sizeof(Contacto));

    if (!agenda->contactos || !contacto) {
        printf("Error de memoria.\n");
        return;
    }

    strcpy(contacto->nombre, nombre);
    strcpy(contacto->apellido, apellido);
    strcpy(contacto->telefono, telefono);

    agenda->contactos[agenda->cantidad++] = contacto;
}

void listarContactos(Agenda *agenda) {
    if (!agenda->cantidad) {
        printf("\nLa agenda esta vacia.\n\n");
        return;
    }

    printf("\n--- Lista de contactos ---\n");

    for (int i = 0; i < agenda->cantidad; i++) {
        Contacto *contacto = agenda->contactos[i];
        printf("%d. %s %s - %s\n", i + 1, contacto->nombre,
               contacto->apellido, contacto->telefono);
    }
    printf("\n");
}

void liberarAgenda(Agenda *agenda) {
    for (int i = 0; i < agenda->cantidad; i++)
        free(agenda->contactos[i]);

    free(agenda->contactos);
    agenda->contactos = NULL;
    agenda->cantidad = agenda->capacidad = 0;
}

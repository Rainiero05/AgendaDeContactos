#pragma once

#include "contacto.h"

typedef struct {
    Contacto **contactos;
    int cantidad;
    int capacidad;
} Agenda;

void inicializarAgenda(Agenda *agenda);
void agregarContacto(Agenda *agenda, const char *nombre, const char *apellido, const char *telefono);
void listarContactos(Agenda *agenda);
void liberarAgenda(Agenda *agenda);
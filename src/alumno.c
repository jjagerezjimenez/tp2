#include "alumno.h"
#include <stdlib.h>
#include <stdio.h>

//static int SerializarCadena();

//static int SerializarNumero();


static int SerializarCadena(const char * campo, const char * valor, char * cadena, int espacio) {           //const?
    return snprintf(cadena, espacio, "\"%s\":\"%s\",", campo, valor);
}

static int SerializarNumero(const char * campo, int valor, char * cadena, int espacio) {
    return snprintf(cadena, espacio, "\"%s\":\"%d\",", campo, valor);
}

int serializar(const struct alumno_s * alumno, char cadena[], uint32_t espacio) {
    int disponibles = espacio;
    int resultado;
    
    
    cadena[0] = '{';
    //*cadena = '{';
    cadena++;

    disponibles--;
    resultado = SerializarCadena("apellido", alumno->apellido, cadena, disponibles);

    if (resultado > 0) {
        disponibles -= resultado;
        cadena += resultado;
        largo+= resultado;
        resultado = SerializarCadena("nombre", alumno->nombre, cadena, disponibles);
    }

    if (resultado > 0) {
        disponibles -= resultado;
        cadena += resultado;
        resultado = SerializarNumero("documento", alumno->documento, cadena, disponibles);
    }

    if (resultado > 0) {
        cadena += resultado;
        *(cadena - 1) = '}';
        resultado = espacio - disponibles;
    }

    
    
    return resultado;
}



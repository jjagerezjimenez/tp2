#include "alumno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TAMANO 100

#define opcion 1 //modificar a 2 si quiero ver estatico, 1 para dinamico





struct alumno_s {  
    char apellido[TAMANO]; 
    char nombre[TAMANO];   
    uint32_t documento;  
    bool ocupado;             //otra forma con estatica
};


static int SerializarCadena(const char * campo, const char * valor, char * cadena, int espacio) {          
    return snprintf(cadena, espacio, "\"%s\":\"%s\",", campo, valor);
}

static int SerializarNumero(const char * campo, int valor, char * cadena, int espacio) {
    return snprintf(cadena, espacio, "\"%s\":\"%d\",", campo, valor);
}


//static struct alumno_s instancias[50] = {0}; //50 huecos              //otra forma

alumno_t CrearAlumno (char * apellido, char * nombre, int documento) {
    alumno_t resultado;             //parto aqui
    
#if opcion == 1             // Forma Dinamica

    resultado = malloc(sizeof(struct alumno_s));                   //Malloc se usa para crear "objetos" de forma dinamica
    strcpy(resultado->apellido, apellido);
    strcpy(resultado->nombre, nombre);
    resultado->documento = documento;


    return resultado;

#else       //parte estatica

static struct alumno_s instancias[50] = {0}; //50 huecos

uint8_t i = 0;//consultar porque no int

for (uint8_t i = 0; i <= 50; i++) {

    if (instancias[i].ocupado == 0) {

        resultado = &instancias[i];
        strcpy(instancias[i].apellido, apellido);
        strcpy(instancias[i].nombre, nombre);
        instancias[i].documento = documento;
        instancias[i].ocupado = true;

        return resultado;   // va aqui el return?
    }
    return NULL;    //problema compil

}
#endif

return resultado;

}



int GetCompleto(alumno_t alumno, char cadena[], uint32_t espacio) {
    return -1;      //para sacar warning
}

int GetDocumento(alumno_t alumno) {
    return -1;      //para sacar warning
}






int Serializar(alumno_t alumno, char cadena[], uint32_t espacio) {
    int disponibles = espacio;
    int resultado;
       
    cadena[0] = '{';
    cadena++;

    disponibles--;
    resultado = SerializarCadena("apellido", alumno->apellido, cadena, disponibles);

    if (resultado > 0) {
        disponibles -= resultado;
        cadena += resultado;
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



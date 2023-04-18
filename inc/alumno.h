#ifndef ALUMNO_H
#define ALUMNO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @struct EstructuraAlumno
 * @brief Define tamaño de los campos de texto
 *
 * descripcion mas extensa
 *
 */

#define TAMANO 100

//! Estructura para almacenar datos de un alumno
typedef struct alumno_s {  // aqui en H va lo publico, en C lo privado
    char apellido[TAMANO]; //!< almacena el apellido
    char nombre[TAMANO];   //!< almacena el Nombre
    uint32_t documento;    //!< almacena el Documento
} * alumno_t;

int serializar(
    const struct alumno_s * alumno, //!< Puntero con la estructura con los datos del alumno
    char cadena[],                  //!< Puntero a la cadena de resultado
    uint32_t espacio);              //!< Espacio disponible

#ifdef __cplusplus
}
#endif

#endif /* ALUMNO_H */

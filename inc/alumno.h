#ifndef ALUMNO_H
#define ALUMNO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define TAMANO 60

typedef struct alumno_s {
    char apellido[TAMANO]; //!< almacena el apellido
    char nombre[TAMANO];   //!< almacena el nombre
    uint32_t documento;    //!< almacena numero de documento
} * alumno_t;

#ifdef __cplusplus
}
#endif

#endif /* ALUMNO_H */

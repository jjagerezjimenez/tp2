#ifndef ALUMNO_H
#define ALUMNO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define TAMANO 100

typedef struct alumno_s {
    char apellido[TAMANO];
    char nombre[TAMANO];
    uint32_t documento;
} * alumno_t;

int serializar(const struct alumno_s * alumno, char cadena[], uint32_t espacio);

#ifdef __cplusplus
}
#endif

#endif /* ALUMNO_H */

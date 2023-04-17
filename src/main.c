#include "alumno.h"
#include <stdio.h>

int main(void) {

    static const struct alumno_s yo = {
        .apellido = "Gerez Jimenez",
        .nombre = "Juan Jose Armando"
        .documento = 41649897,          //Necesita coma?
    };

    char cadena[256];
    
    
       if(serializar(&yo, cadena, sizeof(cadena)) >= 0) {                                   //quitar "resultado"
            printf("%s\n", cadena);
       }else{
            printf("Error al serializar\n");
       } // ;?

    return 0;
}
#include "alumno.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  //  static const struct alumno_s yo = {
   //     .apellido = "Gerez Jimenez",
   //     .nombre = "Juan Jose Armando",
   //     .documento = 41649897,
   // };

    char cadena[256];
    alumno_t yo = CrearAlumno("Gerez Jimenez", "Juan Jose Armando", 41649897);
    //alumno_t otro = CrearAlumno("Garcia", "Pablo", 1234567);            //por si quiero agregar otro alumno

    /**
     * @brief Cargo mis datos con la funcion main.
     *
     */

    
       if(Serializar(yo, cadena, sizeof(cadena)) >= 0) {                                   //quitar "resultado"
            printf("%s\n", cadena);
       }else{
            printf("Error al serializar\n");
       }

       //if(Serializar(otro, cadena, sizeof(cadena)) >= 0) {                                   //quitar "resultado"
       //     printf("%s\n", cadena);
       //}else{
       //     printf("Error al serializar\n");
       //} 

     //free(yo);

     return 0;
}
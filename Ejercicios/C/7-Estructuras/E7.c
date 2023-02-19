#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "status_t.h"

/*
Escribir una porción de código para cargar la estructura robot_pose usando las demás estructuras. Luego, para acceder a cada uno 
de los campos de las estructuras, escribir una expresión.
*/

struct header {
    int secuencia;
    time_t stamp;
    char * frame;
} header;

struct punto {
    double x, y, z;
} point;

struct cuaternion {
    double qx, qy, qz, qw;
} quaternion;

struct pose {
    struct punto * posicion;
    struct cuaternion * orientacion;
} pose;

struct pose_stamped {
    struct header * encabezado;
    struct pose * pose;
} robot_pose, * robot_pose_ptr;


int main(void){
    robot_pose_ptr->encabezado->secuencia = 10;
    robot_pose_ptr->encabezado->stamp = time(NULL);
    robot_pose_ptr->encabezado->frame = "base_link";
    robot_pose_ptr->pose->posicion->x = 1.0;
    robot_pose_ptr->pose->posicion->y = 2.0;
    robot_pose_ptr->pose->posicion->z = 3.0;
    robot_pose_ptr->pose->orientacion->qx = 0.0;
    robot_pose_ptr->pose->orientacion->qy = 0.0;
    robot_pose_ptr->pose->orientacion->qz = 0.0;
    robot_pose_ptr->pose->orientacion->qw = 1.0;
    
    printf("Secuencia: %d \n", robot_pose_ptr->encabezado->secuencia);
    printf("Stamp: %ld \n", robot_pose_ptr->encabezado->stamp);
    printf("Frame: %s \n", robot_pose_ptr->encabezado->frame);
    printf("Posicion x: %f \n", robot_pose_ptr->pose->posicion->x);
    printf("Posicion y: %f \n", robot_pose_ptr->pose->posicion->y);
    printf("Posicion z: %f \n", robot_pose_ptr->pose->posicion->z);
    printf("Orientacion qx: %f \n", robot_pose_ptr->pose->orientacion->qx);
    printf("Orientacion qy: %f \n", robot_pose_ptr->pose->orientacion->qy);
    printf("Orientacion qz: %f \n", robot_pose_ptr->pose->orientacion->qz);
    printf("Orientacion qw: %f \n", robot_pose_ptr->pose->orientacion->qw);
    return EXIT_SUCCESS;
}
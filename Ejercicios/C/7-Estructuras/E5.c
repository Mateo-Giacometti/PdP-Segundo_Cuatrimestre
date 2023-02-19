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
Para acceder a cada uno de los campos de las estructuras, escribir una expresión.
*/

struct header {
    int secuencia;
    time_t stamp;
    char * frame;
};

struct pose {
    struct {
        double x, y, z;
    } posicion;
    struct {
        double qx, qy, qz, qw;
    } orientacion;
};

struct pose_stamped {
    struct header encabezado;
    struct pose pose;
} robot_pose;

int main(void){
    robot_pose.encabezado.secuencia = 10;
    robot_pose.encabezado.stamp = time(NULL);
    robot_pose.encabezado.frame = "base_link";
    robot_pose.pose.posicion.x = 1.0;
    robot_pose.pose.posicion.y = 2.0;
    robot_pose.pose.posicion.z = 3.0;
    robot_pose.pose.orientacion.qx = 0.0;
    robot_pose.pose.orientacion.qy = 0.0;
    robot_pose.pose.orientacion.qz = 0.0;
    robot_pose.pose.orientacion.qw = 1.0;
    printf("Secuencia: %d \n", robot_pose.encabezado.secuencia);
    printf("Stamp: %ld \n", robot_pose.encabezado.stamp);
    printf("Frame: %s \n", robot_pose.encabezado.frame);
    printf("Posicion x: %f \n", robot_pose.pose.posicion.x);
    printf("Posicion y: %f \n", robot_pose.pose.posicion.y);
    printf("Posicion z: %f \n", robot_pose.pose.posicion.z);
    printf("Orientacion qx: %f \n", robot_pose.pose.orientacion.qx);
    printf("Orientacion qy: %f \n", robot_pose.pose.orientacion.qy);
    printf("Orientacion qz: %f \n", robot_pose.pose.orientacion.qz);
    printf("Orientacion qw: %f \n", robot_pose.pose.orientacion.qw);

    return EXIT_SUCCESS;
}
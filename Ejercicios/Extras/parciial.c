#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

typedef enum {ST_OK, ST_ERR, ST_ERR_NULL_PTR, ST_ERR_ENOMEM} status_t;

/* C */
/* ejercicio 1: definiciones */
typedef struct materia {
    const char *nombre;
    const char *codigo;
    double *notas;
    size_t len_notas;
    double nota_final;
} materia_t;


typedef struct estudiante {
    const char *nombre;
    int carrera;
    materia_t *materias;
    size_t len_materias;
} estudiante_t;

/* ejercicio 2: crear estudiante */
status_t crear_estudiante(struct estudiante **estudiante, const char *nombre, int carrera)
{
    struct estudiante *aux;

    if ((NULL == estudiante) || (NULL == nombre)) {
        return ST_ERR_NULL_PTR;
    }

    aux = calloc(1, sizeof(struct estudiante));
    if (NULL == aux) {
        return ST_ERR_ENOMEM;
    }

    aux->nombre = strdup(nombre);
    if (NULL == aux->nombre) {
        free(aux);
    }

    aux->carrera = carrera;
    aux->materias = NULL;
    aux->len_materias = 0;

    *estudiante = aux;
    return ST_OK;
}

/* ejercicio 3: agregar materia */
status_t agregar_materia(struct estudiante *estudiante, const char *nombre, const char *codigo)
{
    struct materia *aux;
    char *_nombre;
    char *_codigo;

    if ((NULL == estudiante) || (NULL == nombre) || (NULL == codigo)) {
        return ST_ERR_NULL_PTR;
    }

    _nombre = strdup(nombre);
    _codigo = strdup(codigo);

    if ((NULL == _nombre) || (NULL == _codigo)) {
        free(_nombre);
        free(_codigo);
        return ST_ERR_ENOMEM;
    }

    aux = (struct materia *) realloc(estudiante->materias, (estudiante->len_materias + 1) * sizeof(struct materia));
    if (NULL == aux) {
        free(_nombre);
        free(_codigo);
        return ST_ERR_ENOMEM;
    }
    estudiante->materias = aux;
    estudiante->materias[estudiante->len_materias].nombre = _nombre;
    estudiante->materias[estudiante->len_materias].codigo = _codigo;
    estudiante->materias[estudiante->len_materias].notas = NULL;
    estudiante->materias[estudiante->len_materias].len_notas = 0;
    estudiante->len_materias++;

    return ST_OK;
}


/* ejercicio 4: promedio */
status_t promedio(double *prom, const struct estudiante *estudiante)
{
    if ((NULL == estudiante) || (NULL == estudiante->materias) || (NULL == prom)) {
        return ST_ERR_NULL_PTR;
    }

    *prom = estudiante->materias[0].nota_final;
    for (size_t i = 0; i < estudiante->len_materias; ++i) {
        *prom += estudiante->materias[i].nota_final;
    }
    *prom /= estudiante->len_materias;

    return ST_OK;
}


/* ejercicio 5: arreglo de punteros */
status_t agregar_materia(struct estudiante *estudiante, const char *nombre, const char *codigo)
{
    struct materia **aux;
    char *_nombre;
    char *_codigo;
    struct materia *nueva_materia;

    if ((NULL == estudiante) || (NULL == nombre) || (NULL == codigo)) {
        return ST_ERR_NULL_PTR;
    }

    _nombre = strdup(nombre);
    _codigo = strdup(codigo);
    nueva_materia = (struct materia *) calloc(1, sizeof(struct materia));

    if ((NULL == _nombre) || (NULL == _codigo) || (NULL == nueva_materia)) {
        free(_nombre);
        free(_codigo);
        free(nueva_materia);
        return ST_ERR_ENOMEM;
    }

    aux = (struct materia **) realloc(estudiante->materias, (estudiante->len_materias + 1) * sizeof(struct materia *));
    if (NULL == aux) {
        free(_nombre);
        free(_codigo);
        free(nueva_materia);
        return ST_ERR_ENOMEM;
    }
    estudiante->materias = aux;

    nueva_materia->nombre = _nombre;
    nueva_materia->codigo = _codigo;
    nueva_materia->notas = NULL;
    nueva_materia->len_notas = 0;
    estudiante->materias[estudiante->len_materias++] = nueva_materia;

    return ST_OK;
}

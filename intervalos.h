/*
  Módulo de definición de `intervalos'.


  Laboratorio de Programación 3.
  InCo-FIng-UDELAR
 */

#ifndef _INTERVALOS_H
#define _INTERVALOS_H

typedef unsigned int nat;

struct intervalo_t {
  nat inicio;
  nat fin;
};

/* Devuelve un arreglo de 'n' booleanos con TRUE en los intervalos asignados,
   los cuales no se superponen.
   La cantidad de intervalos asignados debe ser la máxima posible.
   'intervalos' es un arreglo con 'n' intervalo_t.
   El tiempo de ejecucion en peor caso debe ser O(n*log(n)).
*/
bool *max_cantidad(intervalo_t *intervalos, nat n);


#endif

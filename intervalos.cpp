/* 5307385 */

#include "intervalos.h"

/*
  Ordena la lista de posiciones de intervalos de menor a mayor tiempo de fin.
  Algoritmo: Merge sort.
  Tiempo de ejecución: O(n*log(n)).
*/
static void ordenar(intervalo_t *intervalos, nat *pos, nat n) {
  if (n <= 1)
    return;

  ordenar(intervalos, pos, n / 2);
  ordenar(intervalos, pos + (n / 2), n - (n / 2));

  nat *pos_copy = new nat[n];
  for (nat i = 0 ; i < n ; i++)
    pos_copy[i] = pos[i];

  nat *pos1 = pos_copy, *pos2 = pos_copy + (n / 2);
  nat count1 = 0, count2 = 0;

  while ((count1 < n / 2) && (count2 < n - (n / 2))) {
    if (intervalos[pos1[count1]].fin < intervalos[pos2[count2]].fin) {
      pos[count1 + count2] = pos1[count1];
      count1++;
    } else if (intervalos[pos1[count1]].fin > intervalos[pos2[count2]].fin) {
      pos[count1 + count2] = pos2[count2];
      count2++;
    } else if (intervalos[pos1[count1]].inicio < intervalos[pos2[count2]].inicio) {
      pos[count1 + count2] = pos1[count1];
      count1++;
    } else {
      pos[count1 + count2] = pos2[count2];
      count2++;
    }
  }

  while (count1 < n / 2) {
    pos[count1 + count2] = pos1[count1];
    count1++;
  }

  while (count2 < n - (n / 2)) {
    pos[count1 + count2] = pos2[count2];
    count2++;
  }

  delete[] pos_copy;
}

/* Devuelve un arreglo de 'n' booleanos con TRUE en los intervalos asignados,
   los cuales no se superponen.
   La cantidad de intervalos asignados debe ser la máxima posible.
   'intervalos' es un arreglo con 'n' intervalo_t.
   El tiempo de ejecucion en peor caso es O(n*log(n)).
*/
bool *max_cantidad(intervalo_t *intervalos, nat n) {
  if (n == 0) return new bool[0];

  nat *pos = new nat[n];
  bool *res = new bool[n];
  for (nat i = 0 ; i < n ; i++) {
    pos[i] = i;
    res[i] = false;
  }

  ordenar(intervalos, pos, n);

  res[pos[0]] = true;
  nat last = 0;
  for (nat count = 1; count < n ; count++) {
    if (intervalos[pos[last]].fin <= intervalos[pos[count]].inicio) {
      res[pos[count]] = true;
      last = count;
    }
  }

  delete[] pos;

  return res;
}
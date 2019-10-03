#!/usr/bin/env python3

import random
import os

def genCaso():
  caso = ""

  cant_llamadas = random.randrange(1, 11)
  for i in range(0, cant_llamadas):
    caso += "max_cantidad\n"

    cant_intervalos = random.randrange(0, 10000)
    caso += f"{cant_intervalos}\n"

    for j in range(0, cant_intervalos):
      inicio = random.randrange(0, 101)
      fin = random.randrange(inicio, 101)
      caso += f"{inicio}-{fin}\n"

  caso += "Fin\n"

  return caso

for x in range(0, 1000):
  caso_name = str(x)
  caso_name = "0" * (3 - len(caso_name)) + caso_name
  print(caso_name)

  with open(f"test/{caso_name}.in", 'w') as in_file:
    in_file.write(genCaso())

  res = os.system(f"timeout 6 valgrind -q --leak-check=full ./principal < test/{caso_name}.in > test/{caso_name}.out")
  if res != 0:
    print(f"Problema: {res}")
    break
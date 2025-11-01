# P3_SSSP_ApellidoNombre

Implementación de SSSP desde una fuente: **BFS** (no ponderado) y **Dijkstra** (ponderado, sin pesos negativos).

## Estructura
```
P3_SSSP_ApellidoNombre/
├─ README.md
├─ data/
│  ├─ caso_no_ponderado.txt
│  └─ caso_ponderado.txt
├─ results/
│  ├─ dist_caso1.txt
│  ├─ dist_caso2.txt
│  └─ tiempos.csv
├─ src/
│  ├─ graph.hpp
│  ├─ graph.cpp
│  ├─ bfs_sp.cpp
│  ├─ dijkstra.cpp
│  └─ main.cpp
└─ report/
   └─ Informe.pdf
```

## Compilar
Desde la raíz del proyecto:
```bash
g++ src/*.cpp -std=c++17 -O2 -o main
```

## Ejecutar
Modo general (entrada, salida_distancias, csv_tiempos):
```bash
./main data/caso_no_ponderado.txt results/dist_caso1.txt results/tiempos.csv
./main data/caso_ponderado.txt results/dist_caso2.txt results/tiempos.csv
```

Formato de entrada (`data/casoX.txt`):
```
n m s tipo
u1 v1 w1
u2 v2 w2
...
um vm wm
```
- `tipo = 0` → no ponderado (BFS): `w` se ignora.
- `tipo = 1` → ponderado (Dijkstra): se rechazan aristas con peso negativo.

Formato de salida (`results/dist_casoX.txt`):
Para cada vértice `v` (1..n) se imprime:
```
v: distancia = <d> ; camino = s -> ... -> v
```
Si inalcanzable la distancia aparece `INF` y el camino queda `-`.

En `results/tiempos.csv` se registra: `n,m,tipo,t_ms` (append por ejecución).

---

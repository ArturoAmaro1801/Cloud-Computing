# Cloud Computing - Suma de Arreglos en Paralelo (OpenMP)

## Descripción
Este proyecto implementa una suma de dos arreglos de 1000 elementos utilizando programación paralela en C++ con la librería **OpenMP**. El objetivo es demostrar la eficiencia de la distribución de carga entre múltiples hilos del procesador.

## Requisitos
* Compilador C++ (g++ o Clang) con soporte para OpenMP.
* Xcode (en macOS) o Visual Studio.

## Cómo Ejecutar
1. Clonar el repositorio.
2. Compilar el archivo `main.cpp` incluyendo las banderas de OpenMP:
   ```bash
   clang++ -Xpreprocessor -fopenmp main.cpp -o main -lomp

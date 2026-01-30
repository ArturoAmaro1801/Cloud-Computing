#include <iostream>
#include <vector>
#include <cstdlib> // Requerido para rand()
#include <ctime>   // Requerido para la semilla de los números aleatorios
#include <omp.h>   // OpenMP

int main() {
    const int SIZE = 1000;
    std::vector<int> a(SIZE); //Primer arreglo a sumar
    std::vector<int> b(SIZE); //Segundo arreglo a sumar
    std::vector<int> c(SIZE); //Arreglo resultante de la suma de los arreglos a y b

    // Se inicializa una semilla aleatoria para obtener números distintos en cada compilación
    std::srand(std::time(0));

    // Se llenan los arreglos con valores aleatorios de 0-99
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = std::rand() % 100;
        b[i] = std::rand() % 100;
    }

    std::cout << "Sumando " << SIZE << " elementos en paralelo...\n";

    // Se crea un vector para saber la distribución de los hilos
    std::vector<int> thread_map(SIZE);
    
    // Se utiliza un for en paralelo utilizando OpenMP
    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++)
    {
        c[i] = a[i] + b[i]; //Se suman los arreglos y se guardan en c
        thread_map[i] = omp_get_thread_num(); //Se guarda la información del hilo para cada suma
    }

    // Se inicializan variables para encontrar los cambios de hilo
    int current_thread = thread_map[0];
    int start_index = 0;
    
    std::cout << "\nDistribución de carga de trabajo de los hilos:\n\n";

    for (int i = 1; i < SIZE; i++)
    {
            if (thread_map[i] != current_thread) // Se detecta el cambio de hilo
            {
                std::cout << "El hilo " << current_thread << " procesó los índices " << start_index << " - " << (i - 1) << "\n";
                
                // Se actualizan las variables
                current_thread = thread_map[i];
                start_index = i;
            }
    }
    
    std::cout << "El hilo " << current_thread << " procesó los índices " << start_index << " - " << (SIZE - 1) << "\n";
        
    // Se imprimen las primeras 10 sumas
    std::cout << "\nVerificación de las primeras 10 sumas de elementos:\n\nFormato -> [# Suma]: a[i] + b[i] = c[i]\n\n";
    
    for (int i = 0; i < 10; i++)
        std::cout << "[" << (i+1) << "]" << ":\t" << a[i] << " + " << b[i] << " = " << c[i] << "\n";
    
    std::cout << "\n";
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

// DEBUG es una variable de pre-procesador, si está activada, chequea
// que el programa no se salga de los limites de números que se pueden guardar en 64 bits. Pero eso
// obvio hace que vaya más lento. 
#define DEBUG true

// Definimos un tipo para que sea más fácil trabajar
typedef uint64_t int_t;

// Esta función es la de la conjetura
bool collatz(int_t* n);

int main(int argc, char* argv[])
{
    // a es el acumulador
    int_t a;
    // MAX es el número hasta el que se va a llegar a calcular. Por defecto, 100.000
    int_t MAX = 100000;

    // Si se le pasó por lo menos un argumento al programa, toma ese argumento como número y se lo asigna a max.
    // O sea, que calcular hasta el 1.000.000, por ejemplo sería haciendo "collatz 1000000". 
    if (argc >= 2) MAX = atoi(argv[1]);

    // Comenzamos a contar el tiempo
    clock_t begin = clock();

    // Por cada número hasta el max...
    for (int i = 1; i < MAX; i++)
    {
        a = i;
        while (a != 1)
        #if DEBUG == true
            if(collatz(&a)) 
                goto end_for;
        #else
            collatz(&a);
        #endif

        // Podés imprimir el número por pantalla una vez que se chequeó que vuelve a uno (solo
        // tenés que descomentar esta linea) pero imprimir por pantalla es suuuuuuper lento, así que ojo.

        //printf("%i\n", i);
    }
    end_for:

    // Guardamos en que tiempo terminó
    clock_t end = clock();

    // Calculamos cuantos segundos tardó en terminar
    printf("Took %lf seconds.\n", (double) (end - begin) / CLOCKS_PER_SEC);

    return 0;
}

// Calcular el collatz de n y guardarlo en el mismo n. Esta función toma un puntero a int_t, no un int_t !!
// La función devuelve true cuando hubo un error de buffer.
bool collatz(int_t* n)
{
    #if DEBUG == true
        if (*n % 2 && *n > (1ULL << 63)) 
        {
            printf("[WARNING] Buffer overflowed: %li\n", *n);
            return true;
        }
    #endif

    // Los condicionales en general hacen a los programas más lentos. Si no entendes por qué esto funciona
    // preguntame por wpp
    *n = (*n >> 1) * !(*n % 2) + (3 * *n + 1) * (*n % 2);
    return false;
}
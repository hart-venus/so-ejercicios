#include <stdio.h>
#include <unistd.h>

/*  Cree una cadena de 5 procesos donde cada proceso padre creará un único proceso hijo. 
    Cada proceso debe imprimir su número de PID y el padre el PID de hijo creado.
*/

int main () {

    const int N_FORKS = 4; // Número de forks a realizar
    int i = 0; // Contador de forks


    for (i = 0; i < N_FORKS; i++) {
        // fork() crea un subproceso, el cual es una copia exacta del proceso padre
        // excepto por el valor que retorna fork()
        // 0 -> soy el hijo
        // > 0 -> soy el padre, el valor es el PID (Process ID) del hijo
        // -1 -> error

        int pid = fork();
        if (pid == 0) {
            printf("Soy el hijo con PID: %d\n", getpid());
        } else {
            printf("Soy el padre con PID: %d y mi hijo es: %d\n", getpid(), pid);
            break; // para que el padre no cree más hijos, el proceso que continúa es el hijo 
        }

    }

    return 0;
}
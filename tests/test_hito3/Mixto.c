#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
    volatile long long i;
    int ciclo = i;
    printf("----Proceso Camaleon----\n");
    printf("Mi pid es %d\n", getpid());
    while (1) {
        // Hacer algo intensivo en CPU
        for(i = 0; i < 1000000000; i++) {
    
        }

        for(int j = 0; j < 10; j++) {
            // Hacer algo no intensivo en CPU
            sleep(2); // Dormir un poco para simular un proceso no intensivo
        }
    }
    return 0;
}
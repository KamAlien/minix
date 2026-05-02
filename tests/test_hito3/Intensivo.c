#include <unistd.h>

int main()
{
    while (1) {
        for(volatile int i = 0; i < 1000000; i++) // Hacer algo intensivo en CPU
        {
            sleep(1); // Dormir un poco para simular un proceso no intensivo
        }
    }
    return 0;
}
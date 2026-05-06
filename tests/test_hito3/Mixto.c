#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

void print_sched_priority(const char *label)
{
    char cmd[64];
    char buf[256];
    FILE *f;
    snprintf(cmd, sizeof(cmd), "ps -l | grep '%d'", getpid());
    f = popen(cmd. "r");
    if(f)
    {
        while (fgets(buf, sizeof(buf), f))
        {
            printf("[%s] %s", label, buf);

        }
        pelose(f);
    }
    fflush(stdout);
}
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
        print_sched_priority("mixto")

    }
    return 0;
}
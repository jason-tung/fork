#include <stdlib.h>
#include <time.h>
#include <printf.h>
#include <zconf.h>

int main() {
    srand(time(NULL));
    printf("PARENT: initial message\n");
    int f0 = fork();
    if (!f0){
        int id = 0;
        printf("CHILD0: my pid is %d\n", getpid());
        int f1 = fork();
        int x = rand()%16 + 5;
        if (!f1){
            printf("CHILD1: my pid is %d\n", getpid());
            id = 1;
            x = rand()%16 + 5;
        }
        printf("CHILD%d: sleeping for %ds...\n",id,x);
        sleep(x);
        printf("CHILD%d: done!\n",id);
        exit(x);
    }
    printf("PARENT: my pid is %d\n", getpid());
    int stat_holder;
    int cpid = wait(&stat_holder);
    printf("PARENT: child at %d terminated after %ds\n", cpid, WEXITSTATUS(stat_holder));
    printf("PARENT: done!\n");
    return 0;
}
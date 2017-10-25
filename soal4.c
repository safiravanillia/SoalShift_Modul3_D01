#include <stdio.h>
#include <string.h>
#include <pthread.h>

void * thread_fakt(void *);

int main() {
    int num,count,i;
    char run[13];
    pthread_t tid1,tid2,tid3;
    scanf("%s", run);

    while(scanf("%d", &num) != EOF) {
    pthread_create(&tid1,NULL,thread_fakt,(void *)&num);
    pthread_join(tid1, NULL);
    }
    return 0;
}

void *thread_fakt(void *argv) {
    int *num, count, fakt=1;
    num=(int*)argv;

    for(count=1; count<=*num; count++) {
        fakt*=count;
    }
    printf("Hasil %d! = %d \n",*num, fakt);
    pthread_exit(NULL);
}

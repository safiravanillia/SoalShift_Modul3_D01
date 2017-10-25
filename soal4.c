#include <stdio.h>
#include <string.h>
#include <pthread.h>

void * thread_fakt(void *);

int main() {
    int num,count,i;
    char run[13];
    pthread_t tid;
    scanf("%s", run);

    while(scanf("%d", &num) != EOF) {
    pthread_create(&tid,NULL,thread_fakt,(void *)&num);
    pthread_join(tid, NULL);
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

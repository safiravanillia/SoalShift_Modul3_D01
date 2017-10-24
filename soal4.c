#include <stdio.h>
#include <pthread.h>

void * thread_fakt(void *);

int main() {
    int num1,num2,num3,count;
    pthread_t tid1,tid2,tid3;
    printf("./faktorial ");
    scanf("%d %d %d",&num1, &num2,&num3);

    pthread_create(&tid1,NULL,thread_fakt,(void *)&num3);
    pthread_create(&tid2,NULL,thread_fakt,(void *)&num2);
    pthread_create(&tid3,NULL,thread_fakt,(void *)&num1);
   
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    return 0;
}

void *thread_fakt(void *argv) {
    int *num, count;int fakt=1;
    num=(int*)argv;

    for(count=1; count<=*num; count++) {
        fakt*=count;
    }
    printf("Hasil %d! = %d \n",*num, fakt);
    pthread_exit(NULL);
}

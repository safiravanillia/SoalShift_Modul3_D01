#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t tid1;
pthread_t tid2;
int status;
int nomor;
 
void* tulis(void *arg)
{
    status = 0;
 
    printf("Masukan nomor ");
    scanf("%d", &nomor);
 
    status = 1;
 
    return NULL;
}


void* baca(void *arg)
{
    while(status != 1)
    {

    }

    printf("Nomor %d\n", nomor);
}
 
int main(void)
{	
	char pemain1[100],pemain2[100];	
    int i=0;
    while(i<32){
	printf("masukan nama pemain 1 = ");
  	scanf("%s",pemain1);
	printf("masukan nama pemain 2 = ");
	scanf("%s",pemain2);
	

    pthread_create(&(tid1), NULL, &player1, void);
    pthread_create(&(tid2), NULL, &player2, NULL);
 
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 }
    return 0;
}

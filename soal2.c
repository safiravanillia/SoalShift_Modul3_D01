#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t tid1;
pthread_t tid2;
int status;
int nomor;
int kotakp1[16],kotakp2[16];
memset(kotakp1,0,sizeof(kotakp1));
memset(kotakp2,0,sizeof(kotakp2));

void* player1(void *arg)
{
    status = 0;
 
   //program
    status = 1;
 
    return NULL;a
}


void* player2(void *arg)
{
    while(status = 0){}
 //program
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
	prinf("\n");
	system("clear");
	printf("selamat datang pemain1 %s\nselamat datang pemain2%s\n",pemain1,pemain2);

    pthread_create(&(tid1), NULL, &player1, (void*)pemain1);
    pthread_create(&(tid2), NULL, &player2, (void*)pemain2);
 
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 }
    return 0;
}

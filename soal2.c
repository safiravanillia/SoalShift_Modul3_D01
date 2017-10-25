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
 

void* player1(void *arg)
{int inisial1=0;
    status = 0;
	for(int i=0;i<16;i++){
		printf("%d",kotakp1[i]);		
		}
 	printf("player1's turn");
	printf("plant a MINE, in hole number = ");
	
   //program
     
    status = 1;
 
    return NULL;
}


void* player2(void *arg)
{int inisial2=0;
    while(status = 0){}
 //program
}
 
int main(void)
{	
	char pemain1[100],pemain2[100];	
	memset(kotakp1,0,sizeof(kotakp1));
	memset(kotakp2,0,sizeof(kotakp2));
    int i=0;
    while(1){
	printf("masukan nama pemain 1 = ");
  	scanf("%s",pemain1);
	printf("masukan nama pemain 2 = ");
	scanf("%s",pemain2);
	printf("\n");
	system("clear");
	printf("selamat datang pemain1 %s\nselamat datang pemain2%s\n",pemain1,pemain2);

    pthread_create(&(tid1), NULL, &player1, (void*)pemain1);
    pthread_create(&(tid2), NULL, &player2, (void*)pemain2);
 
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 }
    return 0;
}

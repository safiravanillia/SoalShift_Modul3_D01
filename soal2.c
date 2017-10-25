#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t tid1;
pthread_t tid2;
int status=0,a,b;
int nomor;
int kotakp1[16],kotakp2[16];
char pemain1[100],pemain2[100];	
int inisial1,inisial2;
void* player1(void *arg)
{ 
    if(status == 0){
	printf("selamat datang pemain1 %s\nselamat datang pemain2 %s\n-----------------------------------\n",pemain1,pemain2);
	/*printf("%s's as player1 turn\nthis is you land mine\n",pemain1);
	for(int i=0;i<16;i++){
		printf("%d ",kotakp1[i]);		
		}
	printf("\nplant a MINE, in hole number = ");
	scanf("%d", &inisial1);
	kotakp1[inisial1]=1;
   //program
     system("clear");*/
	printf("player1 = ");
	scanf("%d",&a);
	printf("huuhuhuh\n");
    status = 1;
 }
    return NULL;
}


void* player2(void *arg)
{
    

	if(status==1){
	printf("selamat datang pemain1 %s\nselamat datang pemain2 %s\n-----------------------------------\n",pemain1,pemain2);
	printf("player2 = ");
	scanf("%d",&b);
	printf("hehe\n");
	/*printf("%s's as player2 turn\nthis is you land mine\n",pemain2);
	for(int i=0;i<16;i++){
		printf("%d ",kotakp2[i]);		
		}
	printf("\nplant a MINE, in hole number = ");
	scanf("%d", &inisial2);
	kotakp2[inisial2]=1;*/
	status=0;
	}
 
}
 
int main(void)
{	
	 
	memset(kotakp1,0,sizeof(kotakp1));
	memset(kotakp2,0,sizeof(kotakp2));
    int i=0;

	printf("masukan nama pemain 1 = ");
  	scanf("%s",pemain1);
	printf("masukan nama pemain 2 = ");
	scanf("%s",pemain2);
	printf("\n");
    while(1){	 
	
	 

    pthread_create(&(tid1), NULL, &player1, (void*)pemain1);
    pthread_create(&(tid2), NULL, &player2, (void*)pemain2);
 pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
     
 }

    return 0;
}

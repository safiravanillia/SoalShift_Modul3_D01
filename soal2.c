#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t tid1;
pthread_t tid2;
int status=0,a,b;
int nomor;
int kotakp1[16],kotakp2[16],poin1=0,poin2=0;
char pemain1[100],pemain2[100];	
int inisial1,inisial2;
void* player1(void *arg)
{ 
    if(status == 0){
	int bnyk1;
	printf("%s's turn as player1  \nthis is you land mine\n",pemain1);
	for(int i=0;i<16;i++){
		printf("%d ",kotakp1[i]);		
		}
	printf("\nhow much MINE yg pgn di tanem = ");
	scanf("%d",&bnyk1);
	printf("\nplant a MINE, in hole number = ");
	for(int a=1;a<=bnyk1;a++){
		scanf("%d", &inisial1);
		kotakp1[inisial1]=1;	
	} 
	printf("now this is your land mine \n");
	for(int i=0;i<16;i++){
		printf("%d ",kotakp1[i]);		
		}
	printf("\n---------------------------------\n");
	printf("\n\n");
	 
    status = 1;
 }
    return NULL;
}


void* player2(void *arg)
{
    

	if(status==1){
//tebak bom
	int tebak2;
	printf("tebak 4 kotak milik player 1 yang tidak ada bombnya");
	for(int a=0;a<4;a++){	
		scanf("%d",&tebak2);
		if(kotakp1[tebak2]==1){
			poin1+=1;
			printf("terdapat bomb pada lubang ke %d",tebak2);		
		}
		else if(kotakp1[tebak2]==0){
			poin2+=1;
		}
	}
	












//untuk input bomb
	int bnyk2;
	printf("%s's turn as player2  \nthis is you land mine\n",pemain2);
	for(int i=0;i<16;i++){
		printf("%d ",kotakp2[i]);		
		}
	printf("\nhow much MINE yg pgn di tanem = ");
	scanf("%d",&bnyk2);
	printf("\nplant a MINE, in hole number = ");
	for(int a=1;a<=bnyk2;a++){
		scanf("%d", &inisial2);
		kotakp2[inisial2]=1;	
	} 
	printf("now this is your land mine \n");
	for(int i=0;i<16;i++){
		printf("%d ",kotakp2[i]);		
		}
	printf("\n---------------------------------\n");
	printf("\n\n"); 

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

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t tid1;
pthread_t tid2;
int status=0,a,b,n=0;
int nomor;
int kotakp1[16],kotakp2[16],poin1=0,poin2=0;
char pemain1[100],pemain2[100];	
int inisial1,inisial2;
void* player1(void *arg)
{ 
 
 
    if(status == 0){
//tebak
	if(n>0){//soalnya pertama kan kita masang bomb, bukan nebak
	printf("%s's turn as player1, poin = %d \n",pemain1,poin1);
	int tebak1;
	printf("tebak 4 kotak milik player 2 yang tidak ada bombnya = ");
	for(int a=0;a<4;a++){	
		scanf("%d",&tebak1);
		if(kotakp2[tebak1]==1){
			poin2+=1;
			printf("terdapat bomb pada lubang ke %d\n",tebak1);		
		}
		else if(kotakp2[tebak1]==0){
			poin1+=1;
			printf("tidak ada bomb pada lubang ke %d\n",tebak1);
		}
	}
	printf("total poin %s = %d \ntotal poin %s = %d\n",pemain1,poin1,pemain2,poin2);
	printf("\n---------------------------------\n");
	printf("\n\n");
}
//tanam
	int bnyk1;
	printf("this is %s's land mine\n",pemain1);
	for(int i=0;i<16;i++){
		printf("%d ",kotakp1[i]);		
		}
	printf("\nhow much MINE yg pgn di tanem = ");
	scanf("%d",&bnyk1);
	printf("plant a MINE, in hole number = ");
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
	 n++;
    status = 1;
 }
    return NULL;
}


void* player2(void *arg)
{
    

	if(status==1){
//tebak bom
	printf("%s's turn as player2,poin = %d  \n",pemain2,poin2);
	int tebak2;
	printf("tebak 4 kotak milik player 1 yang tidak ada bombnya = ");
	for(int a=0;a<4;a++){	
		scanf("%d",&tebak2);
		if(kotakp1[tebak2]==1){
			poin1+=1;
			printf("terdapat bomb pada lubang ke %d\n",tebak2);		
		}
		else if(kotakp1[tebak2]==0){
			poin2+=1;
			printf("tidak ada bomb pada lubang ke %d\n",tebak2);
		}
	}
	printf("total poin %s = %d \ntotal poin %s = %d\n",pemain1,poin1,pemain2,poin2);
	printf("\n---------------------------------\n");
	printf("\n\n");












//untuk input bomb
	int bnyk2;
	printf("this is %s's land mine\n",pemain2);
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

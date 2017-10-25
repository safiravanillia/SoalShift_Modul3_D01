#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_t tid[3];
int lohan,kepiting,is;

void* unggas(void *arg){
	unsigned long i = 0;
	pthread_t id = pthread_self();
	
	if(pthread_equal(id,tid[1])){
		if(strcmp((char*)arg,"lohan")==0){
			lohan+=10;
			if(lohan>100){
				printf("ikan lohan mati");
				exit(1);	
			}		
		}
		
		if(strcmp((char*)arg,"kepiting")==0){
			kepiting+=10;	
			if(kepiting>100){
				printf("kepiting mati");
				exit(1);			
			}	
		}
	}
return NULL;
}

void* cekk(void *arg){
	while(lohan>0 && kepiting>0){
		 
		printf("lohan = %d\n",lohan);
		printf("kepiting = %d\n",kepiting);
		if (lohan){
 			sleep(10);
			lohan-=15;
		}

		if (kepiting){
			sleep (20);
			kepiting-=10;
		}
		system("clear");
	}
printf("game over");
exit(1);
}

int main(){
char makan[100],hewan[100];
lohan =100;
kepiting=100;
int sekali=0;
printf("kolam ikan lohan dan kepiting\n1.input -makan kepiting- atau -makan lohan- atau -quit x- \ninput = ");
	while(1){ 
		if(sekali<1){
			is=pthread_create(&(tid[0]), NULL, &cekk, NULL);
			sekali++;
		} 
		 scanf("%s%s",makan,hewan);
		if(strcmp(makan,"makan")==0){
			is=pthread_create(&(tid[1]), NULL, &unggas, (void*)hewan);
			}	
	}
		pthread_join(tid[0],NULL);
   		pthread_join(tid[1],NULL);
}

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_t tid[5]; 


char str[10][100]={"MP4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};
int jml[10]={20,20,20,20,20,20},jumlahsenjata,a,senjatake;


void* addgun(void *arg){ 
	pthread_t id = pthread_self();
	if(pthread_equal(id,tid[0])){
		jml[senjatake]+=jumlahsenjata;
		printf("%s memiliki %d\n\n", str[senjatake],jml[senjatake]);
	}
return NULL;
}

void* buygun(void *arg){ 
	pthread_t id = pthread_self();
	if(pthread_equal(id,tid[1])){
		if(jml[senjatake]-jumlahsenjata>=0){
			jml[senjatake]-=jumlahsenjata;
			printf("%s memiliki %d\n\n", str[senjatake],jml[senjatake]);
		}	
		else{printf("stok senjata hanya tinggal %d\n\n",jml[senjatake]);}
	}

return NULL;
}

 
void printstok(){
	for(int a=0;a<6;a++){
		if(jml[a]>0){
			printf("%s %d\n",str[a],jml[a]);					
		}
	}
}

void cekstok(char command[]){
	if(strcmp(command,"MP4A1")==0){senjatake=0;}
	if(strcmp(command,"PM2-V1")==0){senjatake=1;}	
	if(strcmp(command,"SPR-3")==0){senjatake=2;}
	if(strcmp(command,"SS2-V5")==0){senjatake=3;}
	if(strcmp(command,"SPG1-V3")==0){senjatake=4;}
	if(strcmp(command,"MINE")==0){senjatake=5;}
}

int main(){
char nama[100],command[100],here;
int jumlah[100],pilih ;
int sekali=0,is;
 
	while(1){ 
	here:
	//system("clear");
	printf("1.untuk penjual senjata \n2.untuk pembeli senjata\nmasukan angka = ");
		scanf("%d",&pilih);
		if(pilih==1){//penjual senjata, tambah dan cek
			printf("1. lihat senjata (-lihat stok-) \n2. tambah senjata (-nama jml-)\n3.menu utama (-out-)\n");
			scanf("%s%d",command,&jumlahsenjata);
				if(strcmp(command,"lihat")==0){ 
					printstok();
					 while ( getchar() != '\n');
				}
				
				else if((strcmp(command,"MP4A1")==0)||(strcmp(command,"PM2-V1")==0)||(strcmp(command,"SPR-3")==0)||(strcmp(command,"SS2-V5")==0)||(strcmp(command,"SPG1-V3")==0)||(strcmp(command,"MINE"))==0){ 
					cekstok(command);
					is=pthread_create(&(tid[0]), NULL, &addgun,NULL);
					pthread_join(tid[0],NULL);
					 while ( getchar() != '\n');
				}
				if(strcmp(command,"out")==0){ 
					goto here;
				}
		}

		if(pilih==2){//pembeli senjata
			printf("1. lihat senjata (-lihat stok-) \n2. beli senjata (-nama jml-)\n3.menu utama (-out-)\n");
			scanf("%s%d",command,&jumlahsenjata);
				if(strcmp(command,"lihat")==0){ 
					printstok();
				}
				else if((strcmp(command,"MP4A1")==0)||(strcmp(command,"PM2-V1")==0)||(strcmp(command,"SPR-3")==0)||(strcmp(command,"SS2-V5")==0)||(strcmp(command,"SPG1-V3")==0)||(strcmp(command,"MINE"))==0){ 
					cekstok(command); 
					is=pthread_create(&(tid[1]), NULL, &buygun,NULL);
					pthread_join(tid[1],NULL);
				}
				if(strcmp(command,"out")==0){ 
					goto here;
				}
		} 
		 
	}   
}


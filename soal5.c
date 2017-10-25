#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void *thread_cari(void *argv);

int main(){
   char run[7], cari[5];
   pthread_t tid;

   scanf("%s", run);
   while(scanf("%s", cari) != EOF) {
     pthread_create(&(tid),NULL,thread_cari,(void *)&cari);
     pthread_join(tid, NULL);
   }
   return 0;
}

void *thread_cari(void *argv) {
   char *cari[5];
   cari[5]=(char*)argv;

   FILE *fileIn;
   int count = 0;
   char temp[1000];

   fileIn = fopen("novel.txt", "r");

   while(fgets(temp, 1000, fileIn) != NULL) {
	if((strstr(temp, cari[5])) != NULL) {
		count++;
	}	
   }
   printf("%s : %d\n", cari[5], count);

   fclose(fileIn);
   return 0;
}

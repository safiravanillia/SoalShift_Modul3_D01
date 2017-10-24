#include<stdio.h>
#include<string.h>
#include<pthread.h>

void *thread_ifah(void *argv);
//void *thread_fina(void *argv);
//int status;

int main(){
   char run[6], fina[5], ifah[5];
   pthread_t tid1,tid2;
   scanf("%s %s %s", run, ifah, fina);

   pthread_create(&(tid1),NULL,thread_ifah,(void *)&ifah);
   //pthread_create(&(tid2),NULL,thread_fina,(void *)&fina);

   pthread_join(tid1, NULL);
   //pthread_join(tid2, NULL);
   return 0;
}

void *thread_ifah(void *argv) {
   //status = 0;
   char *ifah[5];
   ifah[5]=(char*)argv;
   
   FILE *fileIn;
   
   int count=0;
   char *line = NULL;
   size_t len = 0;
   ssize_t read;

   fileIn = fopen("novel.txt", "r");
   while((read = getline(&line, &len, fileIn)) != -1) {
     if (strstr(line, *ifah) != NULL) {
       count++;
     }
   }
   fclose(fileIn);

   printf("Ifah : %d\n", count);
   //status = 1;
   //return NULL;
}

/* while(status!=1)
   {
	
   }
   char *fina[5];
   fina[5]=(char*)argv;
   
   FILE *fileIn;
   
   int count=0;
   char *line = NULL;
   size_t len = 0;
   ssize_t read;

   fileIn = fopen("/home/safiravanillia/novel.txt", "r");
   while((read = getline(&line, &len, fileIn)) != -1) {
     if (strstr(line, *fina) != NULL) {
       count++;
     }
   fclose(fileIn);

   printf("Fina : %d\n", count);
   }
}*/
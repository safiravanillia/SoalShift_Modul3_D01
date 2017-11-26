#include<stdio.h>   
#include<stdlib.h>
int main(int argc, char *argv[])
{
  int i;

  if(argc < 2){
    printf("Usage: rm files...\n"); 
  }

  for(i = 1; i < argc; i++){
	if (remove(argv[i]) == 0){
		 printf("Deleted successfully");}
	 else{
     		 printf("Unable to delete the file");}
 
      break;
    } 
 
}


 

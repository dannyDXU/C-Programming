
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int *p;
	int* array[20];
	int value;

   setbuf(stdout, NULL);
   for(int i = 0; i < 20; i++) {
   p = (int*) malloc(sizeof(int)*30);
   if(p == NULL) {
	   printf("unsuccessful");
	   exit(1);
   }
   array[i] = p;
  }

   printf("Hello world! I have created a dynamic array of 100 integers!\n");


   value = 0;
   for(int j = 0; j < 20; j++) {
	   for (int k = 0; k < 30; k++) {
		   array[j][k] = value + j;
		   printf("%3d", array[j][k]);
		   value++;
	   }
	   printf("\n");
	   value = 0;
   }


	for(int j = 0; j < 20; j++) {
   	  free(array[j]);
   }
   free(p);
   return 0;
}


#include <stdio.h>
#include <stdlib.h>

void copy(FILE *inputFile, FILE *inputNewFile);
int main(int argc, char * argv[]) {
	FILE *inputFile, *inputNewFile;
    inputFile = fopen("C:/Users/Public/example/numberss.txt", "r");
    inputNewFile = fopen("C:/Users/Public/example/numbersss.txt", "w");

    if(inputFile == NULL) {
    	printf("Failed\n");
    	exit(1);
    }

    if(inputNewFile == NULL) {
       	printf("Failed\n");
       	exit(1);
       }

   copy(inputFile, inputNewFile);

      fclose(inputFile);
      fclose(inputNewFile);


    return 0;
}
void copy(FILE *inputFile, FILE *inputNewFile){
	   int numConversion;
	   char ch;
	   numConversion = fscanf(inputFile, "%c", &ch);
	     while(numConversion == 1) {
	     	fprintf(inputNewFile, "%c", ch);
	     	numConversion = fscanf(inputFile, "%c", &ch );
	     }
 }





#define N 8

#include <stdio.h>
#include <stdlib.h>
int matrix[N][N];

int valid( int i );
int putall( int id );
void print_matrix();
int main(int argc, char* argv[]) {

	//putall(0);
	matrix[0][4]=1;
	matrix[0][3]=1;
	print_matrix();

	printf("%c",valid(8));
	print_matrix();

	return 0;
}

  int valid( int i ){

  int row = i/N;
  int column = i%N;
  int rowbeginning = 0;
  int columnbeginning = 0;
  int rowtemp = row;
  int columntemp = column;



 for (int i = 0; i < N; i++)  {				// check to see if there is queen on column
  	  if ( (matrix[rowbeginning][column] == 1) && (matrix[row][column] != 1)) {
 	 	 return 0;
  	  }
  	  rowbeginning ++;
  }


  for (int i = 0; i < N; i++) {				// check to see if there is queen on row
	  if( (matrix[row][columnbeginning] == 1) && (matrix[row][column] != 1)) {
	  	  return 0;
	  }
	  columnbeginning ++;
  }



  if (row > 0) {		//Check left up diagonal
	  while (rowtemp != 0) {
		  rowtemp --;
		  columntemp --;
		  if (matrix[rowtemp][columntemp] == 1 && (matrix[row][column] != 1)) {
			  return 0;
		  }
	  }
  }

  rowtemp = row;
  columntemp = column;

  if (row > 0) {		//Check right up diagonal
	  while(rowtemp != 0) {
		  rowtemp --;
		  columntemp ++;
		  if (matrix[rowtemp][columntemp] == 1 && (matrix[row][column] != 1)) {
		 			  return 0;
		  }
	  }
  }

  rowtemp = row;
  columntemp = column;

  if (row < 7) {		//Check left down diagonal
	  while(rowtemp != 7) {
		  rowtemp ++;
		  columntemp--;
		  if(matrix[rowtemp][columntemp] == 1 && (matrix[row][column] != 1)) {
			  return 0;
		  }
	  }
  }

  rowtemp = row;
  columntemp = column;

    if (row < 7) {		//Check right down diagonal
  	  while(rowtemp != 7) {
  		  rowtemp ++;
  		  columntemp ++;
  		  if(matrix[rowtemp][columntemp] == 1 && (matrix[row][column] != 1)) {
  			  return 0;
  		  }
  	  }
    }

    return 1;




  }

  // Convert grid position i on the NxN board to row x and column y
  // Check the current queen in row x and column y is not in the same row, column or diagonal as another queen
  // If valid, return 1 else return 0

  // Write your code here...


int putall( int id ){ /* id: index for the current queen */
	for ( int i = 0; i < N ; i++ ){
        if( valid(id) ){ /* If current position is a valid one */
        	matrix[id/8][id%8] = 1;
             if( (id/8) == N ){  /* If this is the last one to place */
            	return 1;
            } else{

            		if(putall((id/8) + 1)) {
            			return 1;
            		}

            		matrix[id/8][id%8] = 0;
            		}

            	// Calculate the start_position for next queen.
                // Insert your code below...
            }

        }
	return 0;
    }




    void print_matrix() {
    	int i,j;
    	for ( i = 0 ; i < N ; i++ ){
    		for( j = 0 ; j < N ; j++ ){
    			printf( "%d ", matrix[i][j]);
    		}
    		printf( "\n" );
    	}
    	printf( "\n" );
    }

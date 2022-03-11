//Danny Xu

#define N 8

#include <stdio.h>
#include <stdlib.h>
int matrix[N][N];
int valid( int i );
void putall( int id );
void print_matrix();
int main(int argc, char* argv[]) {


	putall(0);
	return 0;
}

  int valid( int i ){

  int row = i/N;
  int column = i%N;
  int rowbeginning = 0;
  int columnbeginning = 0;
  int rowtemp = row;
  int columntemp = column;
  int maxrow = abs(row - column);
  int maxcolumn = (row + column);

 for (int i = 0; i < row; i++)  {				// check to see if there is queen on column
  	  if ( (matrix[rowbeginning][column] == 1)) {
 	 	 return 0;
  	  }
  	  rowbeginning ++;
  }

 for (int i = row + 1 ; i < N; i++) {
	 if ( (matrix[rowbeginning][column] == 1)) {
		 return 0;
	 }
	 rowbeginning ++;
 }


  for (int i = 0; i < column; i++) {				// check to see if there is queen on row
	  if( (matrix[row][columnbeginning] == 1)) {
	  	  return 0;
	  }
	  columnbeginning ++;
  }

  for (int i = column + 1; i < N; i++) {
  	  if( (matrix[row][columnbeginning] == 1)) {
  	  	  return 0;
  	  }
  	  columnbeginning ++;
    }


  while (rowtemp != maxrow) {			// left up diagonal
	  rowtemp --;
	  columntemp--;
	  if (matrix[rowtemp][columntemp] == 1) {
	  			  return 0;
	  }
  }

  rowtemp = row;
  columntemp = column;

  while (columntemp != maxcolumn) {			// right down diagonal
	  rowtemp ++;
	  columntemp ++;
	    if(matrix[rowtemp][columntemp] == 1) {
	    			  return 0;
	    		  }
  }

  rowtemp = row;
   columntemp = column;

  while (rowtemp != maxrow && columntemp != maxcolumn) {   // right up diagonal
	  rowtemp --;
	  columntemp ++;
	  if(matrix[rowtemp][columntemp] == 1) {
	  	    			  return 0;
	  	      }
  }

  rowtemp = row;
   columntemp = column;

  while (rowtemp != maxcolumn && columntemp != maxrow) {   // left down diagonal
	  rowtemp ++;
	  columntemp--;
	  if(matrix[rowtemp][columntemp] == 1) {
	  	  	  return 0;
	  	  	      }
  }
/*
 		//Check left up diagonal
	  while (columntemp != 0 && rowtemp != 0) {
		  rowtemp --;
		  columntemp --;
		  if (matrix[rowtemp][columntemp] == 1) {
			  return 0;
		  }
	  }




  rowtemp = row;
  columntemp = column;

  		//Check right up diagonal
	  while(columntemp != 7 && rowtemp != 0) {
		  rowtemp --;
		  columntemp ++;
		  if (matrix[rowtemp][columntemp] == 1) {
		 			  return 0;
		  }
	  }


  rowtemp = row;
  columntemp = column;

  		//Check left down diagonal
	  while(columntemp != 0 && rowtemp != 7) {
		  rowtemp ++;
		  columntemp--;
		  if(matrix[rowtemp][columntemp] == 1) {
			  return 0;
		  }
	  }


  rowtemp = row;
  columntemp = column;

    		//Check right down diagonal
  	  while(columntemp != 7 && rowtemp != 7) {
  		  rowtemp ++;
  		  columntemp ++;
  		  if(matrix[rowtemp][columntemp] == 1) {
  			  return 0;
  		  }
  	  }



*/

return 1;


  }




void putall( int id )
{ /* id: index for the current queen */
    for ( int i = 0/* Insert start_position of id */; i < N*N ; i++ ){
        if( valid(i) ){ /* If current position is a valid one */
            matrix[i/N][i%N] = 1;
            if( id == N-1 )
            {  /* If this is the last one to place */
                print_matrix();
                //find a solution and output result
            }
            else
            {
                 putall(id + 1);
                 matrix[i/N][i%N] = 0;
                	// Calculate the start_position for next queen
                // Insert your code below...
            }
        }
    }
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

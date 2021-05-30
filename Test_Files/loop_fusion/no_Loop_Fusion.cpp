#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int ** Fusion (int ** MatrixA, int ** MatrixB, int ** MatrixC, int ** MatrixD, long size)
{ 	
	for ( long j= 0 ; j < size ; j++){
		for(long i=0;i <size;i++){ 
			MatrixB[i][j]=2*MatrixA[i][j];
		}
	}
	for ( long j= 0 ; j < size ; j++){
		for(long i=0;i <size;i++){ 
			MatrixC[i][j]=MatrixB[i][j]+MatrixD[i][j];
		}
	}
	return MatrixC;
}

int main() 
{
	int ** MatrixA = (int **)calloc (1024,sizeof(int*));
	int ** MatrixB = (int **)calloc (1024,sizeof(int*));
	int ** MatrixC = (int **)calloc (1024,sizeof(int*));
	int ** MatrixD = (int **)calloc (1024,sizeof(int*));

	for ( int i = 0 ; i  < 1024 ; i ++ )
	{
		MatrixA[i] = (int *) calloc (1024,sizeof(int*));
		MatrixB[i] = (int *) calloc (1024,sizeof(int*));
		MatrixC[i] = (int *) calloc (1024,sizeof(int*));
		MatrixD[i] = (int *) calloc (1024,sizeof(int*));
		for ( int j = 0 ; j  < 1024 ; j ++ ){
			MatrixA[i][j] = i;
			MatrixB[i][j] = i;
			MatrixC[i][j] = i;
			MatrixD[i][j] = i;
		}
	}
	Fusion(MatrixA,MatrixB,MatrixC,MatrixD,1024);
	free (MatrixA);
	free (MatrixB);
	free (MatrixC);
	free (MatrixD);
	return 0;
}

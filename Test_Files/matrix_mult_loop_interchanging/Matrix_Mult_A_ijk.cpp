#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int ** Matrix_Mult (int ** MatrixA,int ** MatrixB,int ** MatrixC,long size)
{
	int sum;
	for(long i=0;i <size;i++) {
		for(long j=0;j <size;j++) {
			sum=0;
			for(long k=0;k <size;k++) {
				sum+=MatrixA[i][k]*MatrixB[k][j];
			}
			MatrixC[i][j]=sum;
		}
	}
	return MatrixC;
}

int main() 
{
	int size=100;
	int ** MatrixA = (int **)calloc (size,sizeof(int*));
	int ** MatrixB = (int **)calloc (size,sizeof(int*));
	int ** MatrixC = (int **)calloc (size,sizeof(int*));

	for ( int i = 0 ; i  < size ; i ++ )
	{
		MatrixA[i] = (int *) calloc (size,sizeof(int*));
		MatrixB[i] = (int *) calloc (size,sizeof(int*));
		MatrixC[i] = (int *) calloc (size,sizeof(int*));
		for ( int j = 0 ; j  < size ; j ++ ){
			MatrixA[i][j] = i;
			MatrixB[i][j] = i;
			MatrixC[i][j] = i;
		}
	}

	Matrix_Mult(MatrixA,MatrixB,MatrixC,size);
	free (MatrixA);
	free (MatrixB);
	free (MatrixC);
	return 0;
}

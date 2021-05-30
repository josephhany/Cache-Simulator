#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

long row_sum (int ** array, long size)
{ 
	long s = 0;
	
	for(long i=0;i <size;i++) {
		for ( long j= 0 ; j < size ; j++){
			s += array[i][j]; 
		}
	}
	return s;
}

int main() 
{
	int size=2048;
	int ** array = (int **)calloc (size,sizeof(int*));
	for ( int i = 0 ; i  < size ; i ++ )
	{
		array[i] = (int *) calloc (size,sizeof(int*));
		for ( int j = 0 ; j  < size ; j ++ ) array[i][j] = i;
	}
	row_sum(array,size);
	free (array);
	return 0;
}

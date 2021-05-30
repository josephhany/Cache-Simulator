#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

long perform_operation_using_key_to_search (int * keys,int * values, long size)
{ 
	long s = 0;
	
	for(long i=0;i <size;i++) {
			if(i%2 && keys[i]%3)s += values[i]; 
	}
	return s;
}

int main() 
{
	int size=1024;

	int * keys = (int *)calloc (size,sizeof(int));
	int * values = (int *)calloc (size,sizeof(int));

	for ( int i = 0 ; i  < size ; i ++ ){
		values[i] = size-i;		
	}
	for ( int i = 0 ; i  < size ; i ++ ){	
		keys[i] = i;
	}

	perform_operation_using_key_to_search(keys,values,size);
	
	free (values);
	free (keys);

	return 0;
}

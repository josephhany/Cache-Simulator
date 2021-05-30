#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct merged_elements {
	int keys;
	int values;
};

long perform_operation_using_key_to_search (struct merged_elements * merged, long size)
{ 
	long s = 0;
	
	for(long i=0;i <size;i++) {
			if(i%2 && (merged[i].keys) %3)s += merged[i].values; 
	}
	return s;
}

int main() 
{
	int size=1024;

	struct merged_elements * merged = (struct merged_elements *)calloc (size,sizeof(struct merged_elements));

	for ( int i = 0 ; i  < size ; i ++ ){
		merged[i].values = size-i;		
	}
	for ( int i = 0 ; i  < size ; i ++ ){	
		merged[i].keys = i;
	}

	perform_operation_using_key_to_search(merged,size);
	
	free (merged);

	return 0;
}

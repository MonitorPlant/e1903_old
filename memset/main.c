#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int* test;
	printf( "%u\n", sizeof( *test ) );
	test = (int *)malloc( sizeof( int * ) );
	test = (int *)malloc( sizeof( int * ) );
	test = (int *)malloc( sizeof( int * ) );
	
	printf( "%u\n", sizeof( *test ) );
	free( test );
	
	printf( "%u\n", sizeof( *test ) );
	
	return 0;
}

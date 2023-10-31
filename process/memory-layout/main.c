#include <stdio.h>
#include <stdlib.h>

char buf[1024];						/* Uninitialized data segment */
int primes[] = {1, 2, 3, 4, 5}; 	/* Initialized data segment */

void hello(int x)					/* Allocate stack for hello() function */
{
	int result; 				
}

void main(int argc, char *argv[])
{
	static int key = 1;				/* Initialized data segment */
	static char buf[1024];			/* Uninitialized data segment */
	char *p;						/* Stack frame of main() function */
	p = malloc(1024);				/* Heap segment */
}



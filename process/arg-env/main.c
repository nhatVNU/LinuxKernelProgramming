#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]){
	int i;
	printf("Number of arguments: %d\n", argc);
	for(int i = 0; i < argc; i++){
		printf("argc[%d]: %s\n", i, argv[i]);
	}
	
}

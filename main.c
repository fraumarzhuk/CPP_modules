#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	if (argc != 2)
		printf("error\n");
	int i = 1;
	while (i < argc) {
		printf("arg: %d\n", atoi(argv[i]));
		i++;
	}
	return 0;
}
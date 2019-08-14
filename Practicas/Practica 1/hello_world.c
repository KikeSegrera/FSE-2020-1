#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	//printf("Hello world!\n");

	int num = atoi(argv[1]);

	int i,h = 31;
	for (i = 1; i <= num; i++){
		h++;
		if(h > 37)
			h = 31;
		printf("\033[%d;1m#%d FSE2020-1 MARTINEZ ENRIQUE\033[0m\n",h,i);
	}
	
	return 0;
}

#include <stdio.h>
#include <unistd.h>

//int fflush(FILE *fp);


int main(void){
	
	printf("hello");
	printf("world\n");
	//fflush(stdout);//
	fflush(NULL);//

	_exit(1);
}

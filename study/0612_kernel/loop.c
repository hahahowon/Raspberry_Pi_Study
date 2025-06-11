#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigHdl(int no){
	printf("%d\n", no);
}

int main(int argc, char **argv){
	int i;
	signal(SIGINT, sigHdl);
	/*1초마다 0부터 숫자를 증가하며 출력*/
	for(i=0;;i++){
		printf("%10d\r", i);
		fflush(NULL);
		sleep(1);
	}
	return 0;

}



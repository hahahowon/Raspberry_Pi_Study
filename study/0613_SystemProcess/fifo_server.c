#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#define FIFOFILE 		"fifo"

int main(int argc, char **argv){
	int n, fd;
	char buf[BUFSIZ];

	unlink(FIFOFILE); // 기존 fifo 파일 삭제

	if(mkfifo(FIFOFILE, 0666)<0){
		perror("mkfifo()");
		return -1;
	}

	if((fd = open(FIFOFILE, O_RDONLY))<0){
		perror("open()");
		return -1;
	}

	while((n = read(fd, buf, sizeof(buf)))>0){
			printf("%s",buf);
			memset(buf, '\0',BUFSIZ);
		//	buf[n] = '\0';
	}
	close(fd);
	return 0;
}



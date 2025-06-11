#include <stdio.h>

int main(int argc, char **argv)
{
	int n;
	FILE *in, *out;
	char buf[BUFSIZ];

	//명령행 인수로 복사할 파일명이 없는 경우에 에러를 출력하고 종료
	if(argc != 3){
		fprintf(stderr, "Usage : fcopy file file2\n");
		return -1;
	}

	//복사의 원본이 되는 파일을 읽기 모드로 연다
	if((in =fopen(argv[1], "r")) ==NULL){
		perror(argv[1]);
		return -1;
	}

	if ((out = fopen(argv[2], "w")) ==NULL){
		perror(argv[2]);
		return 0;
	}


	while ((n=fread(buf, sizeof(char), BUFSIZ, in))>0)
		fwrite(buf, sizeof(char), n, out);

	fclose(out);
	fclose(in);

	return 0;
}


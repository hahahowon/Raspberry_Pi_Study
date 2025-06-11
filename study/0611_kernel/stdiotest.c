#include <stdio.h>

int main(void){
	char str[BUFSIZ], out[BUFSIZ];
	scanf("%s", str);
	printf("1 : %s\n", str);

	sprintf(out, "2: %s", str);
	//out 문자열 출력에 2: %s(str)저장
	perror(out);
	//에러 메세지는 위 에 저장
	return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
  //close(STDIN_FILENO);
  int fd1, fd2;
  char str[BUFSIZ];
  int n = read(0, str, BUFSIZ);  //scanf("%d", &n);
  write(1, str, n);//printf("Hello, world(%s)\n", str);
  fd1 = open("sample1.txt", O_WRONLY | O_CREAT);
  fd2 = open("sample2.txt", O_WRONLY | O_CREAT);
  printf("%d %d\n", fd1, fd2);
  close(fd1);
  close(fd2);

  return 0;
}


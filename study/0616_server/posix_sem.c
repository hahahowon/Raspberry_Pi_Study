#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

static int cnt = 0;
sem_t *sem;


void p() //세마포어 p 연산
{
	cnt--;
	sem_post(sem);
}


void v() //세마포어 v연산
{
	cnt++;
	sem_wait(sem);
}


int main(int argc, char **argv)
{
	const char*name = "posix_sem";
	unsigned int value = 8;

	sem = sem_open(name, O_CREAT, S_IRUSR | S_IWUSR, value);

	while(1){
		if(cnt>=8){
			p();
			printf("decrease : %d\n", cnt);
			break;
		}else {
			v();
			printf("increase : %d\n", cnt);
			usleep(100);
		}
	}

	sem_close(sem);
	printf("sem_destroy return value : %d\n", sem_destroy(sem));

	sem_unlink(name);


	
	return 0;
}






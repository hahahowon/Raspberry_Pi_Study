#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(int argc, char* argv)
{
    int n, in, out;
    char buf[1024];
    //명령행 인수로 복사할 파일명 없는경우 에러 출력 and 종료
    if(argc < 3){
        write(2, "Usage: copy file1 file2\n", 25); //stderr: 에러 출력
        //write(int fd, const void *buf, size_t count);
        //1: int fd          = 파일 디스크럽터 2번 사용(stderr: 에러 출력), 
        //2: const void *buf = 버퍼에 "Usage: copy file1 file2\n" 문자열을 출력, 
        //3. size_t count    = 한 번에 쓸 데이터의 최대 바이트 수
        return -1; //에러 코드 반환
    }
    //복사의 원본이 되는 파일을 읽기 모드로 연다
    if((in = open(argv[1], O_RONLY)) < 0){
        //in = open(const char *pathname, int flags, mode_t mode);
        //1: const char *pathname = 복사할 원본 파일명
        //2: int flags            = O_RDONLY: 읽기 전용 모드로 파일 열기
        //3: mode_t mode         = 파일 모드(생략 가능, 일반적으로 0)
        perror(argv[1]);
        return -1; //파일 열기 실패시 에러 코드 반환
    }
    //복사할 결과 파일을 쓰기모드(새로운 파일 생성 | 기존에 파일 내용 지움)로 연다
    if ((out =open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, SIRUSR|S_IWUSR))<0){
        //out = open(const char *pathname, int flags, mode_t mode);
        //1: const char *pathname = 복사할 결과 파일명 
        //2: int flags :플래그 설정
        //    O_WRONLY: 쓰기 전용 모드
        //    O_CREAT: 파일이 없으면 생성 
        //    O_TRUNC: 파일이 존재하면 내용을 지움
        //3: mode_t mode   = S_IRUSR | S_IWUSR: 사용자 읽기 및 쓰기 권한 설정
        //S_IRUSR: 사용자 읽기 권한, 
        //S_IWUSR: 사용자 쓰기 권한
        //
        perror(argv[2]);
        return -1;
    }
    //원본 파일의 내용을 읽어서 복사할 파일에 쓴다
    while((n = read(in, buf, sizeof(buf)))>0)
        write(out, buf, n);

    //열린 파일을 닫는다

    close(out);
    close(in);
    return 0;

    //프로그램 정상 종료시 0 반환
    return 0;
}

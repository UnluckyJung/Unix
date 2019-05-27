#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/resource.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <signal.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>


#define CODE200 200
#define CODE404 404

#define PHRASE200 "OK"
#define PHRASE404 "FILE NOT FOUND"

char path[] = "/home/201414840/html";

int log_fd;
//한글주석 쓰게 utf-8형식으로 변환함
int main(int argc, char *argv[])
{
	struct sockaddr_in s_addr, c_addr;
	int s_sock, c_sock;
	int len, len_out;
	unsigned short port;
	int status;
	struct rlimit resourceLimit;
	int i;

	int pid;

	//굳이 필요 없는 부분일듯 
	if (argc != 2)
	{
		printf("usage: webServer port_number\n");
		return -1;
	}


	/*
	if (fork() != 0)	//이부분이 백그라운드에서 돌아가게 한부분.
		return 0;	// parent return to shell
	*/


	//이 부분들이 없으면 , 작업도중에 엑박남.
	(void)signal(SIGCLD, SIG_IGN);	// ignore child death
	(void)signal(SIGHUP, SIG_IGN);	// ignore terminal hangup



	/* 이거 무슨 작동인지 모르겠음.
	resourceLimit.rlim_max = 0;
	status = getrlimit(RLIMIT_NOFILE, &resourceLimit);
	for (i = 0; i < resourceLimit.rlim_max; i++)
	{
		close(i);
	}
	*/


	if ((s_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		//소켓을 만든다. (서버를 만들것.)
		// 소켓종류(INET) / 통신방식 / 프로토콜
		perror("socket");
		exit(1);
	}

	//bind를 하기위한 sin 세팅
	//소켓 주소 구조체를 생성하는 과정.
	memset(&s_addr, 0, sizeof(s_addr));
	s_addr.sin_family = AF_INET;
	s_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
	s_addr.sin_port = htons(atoi(argv[1]));
	//만약 서버에 네트워크 카드가 여러개 있다면?
	//1.1.1.1 이런식으로 지명해주는데, 모두가 다 받는다는 가정은 0.0.0.0으로 하는거다.


	if (bind(s_sock, (struct sockaddr *)&s_addr, sizeof(s_addr))) { 	//bind를 함. 소켓을 IP주소와 결합하는것.
		perror("bind");
		exit(1);
	}


	if (listen(s_sock, 10)) {	//클라이언트 접속 요청을 대기한다.
		perror("listen");
		exit(1);
	}



	while (1)
	{
		len = sizeof(c_addr);

		if ((c_sock = accept(s_sock, (struct sockaddr *)&c_addr, &len)) == -1) {
			//클라이언트와 연결하는 과정 = 클라이언트 접속.
			//accept를 기다린다.
			//connect가 될떄까지 기다린다.
			//connect가 되면 리턴되어짐.
			perror("accept");
			exit(1);
		}
		int optvalue = 1;
		setsockopt(c_sock, SOL_SOCKET, SO_REUSEADDR, &optvalue, sizeof(optvalue));	//소켓 초기화 도구

		switch (fork())
		{
		case 0:
			//함수 부르는 시간도 아까워서 여기다 다 때려넣음

			close(s_sock);
			char sndBuf[BUFSIZ + 1], rcvBuf[BUFSIZ + 1];
			char uri[100], c_type[20];;
			int len;

			int len_out;
			int n, i;
			char *p;
			char method[10], f_name[20];
			char phrase[20] = "OK";

			int code = 200;
			int fd;			// file discriptor

			char file_name[20];
			char ext[20];

			struct stat sbuf;

			int log_fd;
			char address_log[BUFSIZ];


			struct
			{
				char *ext;
				char *filetype;
			} extensions[] =
			{
				{
				"gif", "image/gif"},
				{
				"jpg", "image/jpeg"},
				{
				"jpeg", "image/jpeg"},
				{
				"png", "image/png"},
				{
				"zip", "image/zip"},
				{
				"gz", "image/gz"},
				{
				"tar", "image/tar"},
				{
				"htm", "text/html"},
				{
				"html", "text/html"},
				{
			0, 0} };

			memset(rcvBuf, 0, sizeof(rcvBuf));

			int num = 1;

			n = read(c_sock, rcvBuf, BUFSIZ);


			p = strtok(rcvBuf, " ");
			p = strtok(NULL, " ");

			if (!strcmp(p, "/"))
				sprintf(uri, "%s/index.html", path);	//경로를 이런식으로 넘겨야 했네..
			else
				sprintf(uri, "%s%s", path, p);




			strcpy(c_type, "text/plain");
			for (i = 0; extensions[i].ext != 0; i++)	//이 for문 이해못함.
			{
				len = strlen(extensions[i].ext);
				if (!strncmp(uri + strlen(uri) - len, extensions[i].ext, len))
				{
					strcpy(c_type, extensions[i].filetype);
					break;
				}
			}


			// 404 오류메시지 띄워주는거 같은데. 나중에 제거해도 상관없을것으로 보임.
			if ((fd = open(uri, O_RDONLY)) < 0)
			{
				code = CODE404;
				strcpy(phrase, PHRASE404);
			}

			p = strtok(NULL, "\r\n ");	// version

			// send Header
			// http 형식을 보내주는것.
			sprintf(sndBuf, "HTTP/2.0 %d %s\r\n", code, phrase);
			n = write(c_sock, sndBuf, strlen(sndBuf));

			sprintf(sndBuf, "content-type: %s\r\n\r\n", c_type);
			n = write(c_sock, sndBuf, strlen(sndBuf));


			int size = 0;
			if (fd >= 0)
			{
				while ((n = read(fd, rcvBuf, BUFSIZ)) > 0)
				{
					write(c_sock, rcvBuf, n);
					//size++;
				}
			}


			//저수준 파일 입출력을 이용한 log file 생성.

			struct stat file_info;	//파일크기를 측정하기위한 stat 구조체
			stat(uri, &file_info);



			sprintf(address_log, "%s %s %d \n", inet_ntoa(c_addr.sin_addr), uri, (int)file_info.st_size);

			mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

			log_fd = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);	
			if (log_fd == -1) {
				perror("Open log.txt");
				exit(1);
			}
			write(log_fd, address_log, strlen(address_log));
			close(log_fd);


			close(c_sock);
			exit(-1);

		default:
			close(c_sock);
		}

	}
}
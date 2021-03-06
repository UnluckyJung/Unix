﻿#include <stdio.h>
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


char path[] = "/home/201414840/html";

//한글주석 쓰게 utf-8형식으로 변환함
int main(int argc, char *argv[])
{
	struct sockaddr_in sin, cli;
	int sd, ns;
	int len;
	int i;

	//굳이 필요 없는 부분, 일단 놔둠.
	if (argc != 2)
	{
		printf("usage: webServer port_number\n");
		return -1;
	}


	//이 부분들이 없으면 , 작업도중에 엑박남.
	(void)signal(SIGCLD, SIG_IGN);	
	(void)signal(SIGHUP, SIG_IGN);	




	if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		//소켓을 만든다. (서버를 만들것.)
		// 소켓종류(INET) / 통신방식 / 프로토콜
		perror("socket");
		exit(1);
	}

	//bind를 하기위한 sin 세팅
	//소켓 주소 구조체를 생성하는 과정.
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr("0.0.0.0");
	sin.sin_port = htons(atoi(argv[1]));
	//만약 서버에 네트워크 카드가 여러개 있다면?
	//1.1.1.1 이런식으로 지명해주는데, 모두가 다 받는다는 가정은 0.0.0.0으로 하는거다.


	if (bind(sd, (struct sockaddr *)&sin, sizeof(sin))) { 	//bind를 함. 소켓을 IP주소와 결합하는것.
		perror("bind");
		exit(1);
	}


	if (listen(sd, 10)) {	//클라이언트 접속 요청을 대기한다.
		perror("listen");
		exit(1);
	}



	while (1)
	{
		len = sizeof(cli);

		if ((ns = accept(sd, (struct sockaddr *)&cli, &len)) == -1) {
			//클라이언트와 연결하는 과정 = 클라이언트 접속.
			//accept를 기다린다.
			//connect가 될떄까지 기다린다.
			//connect가 되면 리턴되어짐.
			perror("accept");
			exit(1);
		}
		int optvalue = 1;
		setsockopt(ns, SOL_SOCKET, SO_REUSEADDR, &optvalue, sizeof(optvalue));	//소켓 초기화 도구

		switch (fork())
		{
		case 0:

			//함수 부르는 시간도 아까워서 여기다 다 때려넣음

			close(sd);
			char Send_Buf[BUFSIZ + 1] = { 0, }, Receive_Buf[BUFSIZ + 1] = { 0, };
			char uri[100], content_type[20];
			int len;

			int n, i;
			char *p;

			int fd;	//파일 전송할때 필요한 변수.

			int fd_log;	//log 저장할때 저수준 파일입출력 open에 필요한 변수.
			char address_log[BUFSIZ];	//log 저장할 BUF


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


			n = read(ns, Receive_Buf, BUFSIZ);


			p = strtok(Receive_Buf, " ");
			p = strtok(NULL, " ");

			if (!strcmp(p, "/"))
				sprintf(uri, "%s/index.html", path);	//경로를 이런식으로 넘겨야 했네..
			else
				sprintf(uri, "%s%s", path, p);


			strcpy(content_type, "text/plain");

			for (i = 0; extensions[i].ext != 0; i++)	//이 for문 이해못함.
			{
				len = strlen(extensions[i].ext);
				if (!strncmp(uri + strlen(uri) - len, extensions[i].ext, len))
				{
					strcpy(content_type, extensions[i].filetype);
					break;
				}
			}

			
			
			//printf("%s\n", uri);
			//진짜 로그 다찍으면서 찾았다.

			fd = open(uri, O_RDONLY);

			//찾음 시발 favicon.ico 이 십새기 문제다.
			//path에 없는걸 존나찾고잇네
			//우리가 html 폴더안에 더 추가할건 아니니 그냥 이부분은 주석처리함.
			//근데 아직도 이해안가는게, log.txt파일이 생성된뒤(한번이라도 누가 서버에 접속한뒤)에는 오류가 안뜸.
			/*
			if(fd == -1)
			{
				perror("Open uri");
				exit(1);
			}
			*/
			

			p = strtok(NULL, "\r\n ");	



			// http 형식을 보내주는것.
			sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");
			n = write(ns, Send_Buf, strlen(Send_Buf));

			sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);
			n = write(ns, Send_Buf, strlen(Send_Buf));


			int size = 0;
			if (fd >= 0)
			{
				while ((n = read(fd, Receive_Buf, BUFSIZ)) > 0)
				{
					write(ns, Receive_Buf, n);
				}
			}


			//저수준 파일 입출력을 이용한 log file 생성.

			struct stat file_info;	//파일크기를 측정하기위한 stat 구조체
			stat(uri, &file_info);



			sprintf(address_log, "%s %s %d \n", inet_ntoa(cli.sin_addr), uri, (int)file_info.st_size);

			mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

			fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);	
			if (fd_log == -1) {
				perror("Open log.txt");
				exit(1);
			}
			write(fd_log, address_log, strlen(address_log));
			close(fd_log);


			close(ns);
			exit(-1);

		default:
			close(ns);
		}

	}

	return 0;
}
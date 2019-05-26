//Fork (server)

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
#include <signal.h>//이거 개 필수.


#define LOG 100
#define ERROR 200

#define CODE200 200
#define CODE404 404

#define PHRASE200 "OK"
#define PHRASE404 "FILE NOT FOUND"


char documentRoot[] = "/home/201414840/html";

//#define PORTNUM 13693
//포트번호 설정.

void do_web(int socket);
void web_log(int type, char s1[], char s2[], int n);


int main(int argc, char *argv[]) {
	char buf[256];
	struct sockaddr_in sin, cli;
	int sd, ns, clientlen = sizeof(cli);

	int forkcount = 0;

	if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		//소켓을 만든다. (서버를 만들것.)
		// 소켓종류(INET) / 통신방식 / 프로토콜
		perror("socket");
		exit(1);
	}


	(void)signal(SIGCLD, SIG_IGN);	// ignore child death
	(void)signal(SIGHUP, SIG_IGN);	// ignore terminal hangup
	//이거 없으면 안됨 , 갑자기 엑박남.

	//bind를 하기위한 sin 세팅
	//소켓 주소 구조체를 생성하는 과정.
	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(atoi(argv[1]));
	sin.sin_addr.s_addr = inet_addr("0.0.0.0");
	//만약 서버에 네트워크 카드가 여러개 있다면?
	//1.1.1.1 이런식으로 지명해주는데, 모두가 다 받는다는 가정은 0.0.0.0으로 하는거다.


	if (bind(sd, (struct sockaddr *)&sin, sizeof(sin))) { 	//bind를 함. 소켓을 IP주소와 결합하는것.
		perror("bind");
		exit(1);
	}


	if (listen(sd, 5)) {	//클라이언트 접속 요청을 대기한다.
		perror("listen");
		exit(1);
	}

	int optvalue = 1;
	int pid;



	while (1) {
		/*
		forkcount++;
		if (forkcount >= 50)
			system("killall a.out");
		*/
		setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &optvalue, sizeof(optvalue));

		if ((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1) {	//클라이언트와 연결하는 과정 = 클라이언트 접속.
	//accept를 기다린다.
	//connect가 될떄까지 기다린다.
	//connect가 되면 리턴되어짐.
			perror("accept");
			exit(1);
		}

		
		switch (fork()) {//fork하여 자식 프로세스 생성한다.
		case 0:
			printf("New client %s is come\n", inet_ntoa(cli.sin_addr));

			close(sd);
			do_web(ns);


		}
		//close(ns);	//부모쪽에서는 ns를 닫아버림.

		
	}
	return 0;
}


void web_log(int type, char s1[], char s2[], int n)
{

	int log_fd;
	char buf[BUFSIZ];

	if (type == LOG)
	{
		sprintf(buf, "STATUS %s %s %d\n", s1, s2, n);
	}
	else if (type == ERROR)
	{
		sprintf(buf, "ERROR %s %s %d\n", s1, s2, n);
	}

	if ((log_fd = open("web.log", O_CREAT | O_WRONLY | O_APPEND, 0644)) >= 0)
	{
		write(log_fd, buf, strlen(buf));
		close(log_fd);
	}

	if (type == ERROR)
		exit(-1);

}



void do_web(int c_sock)
{
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
	if ((n = read(c_sock, rcvBuf, BUFSIZ)) <= 0)
		web_log(ERROR, "ERROR", "can not receive data from web browser", n);

	web_log(LOG, "REQUEST", rcvBuf, n);

	p = strtok(rcvBuf, " ");
	if (strcmp(p, "GET") && strcmp(p, "get"))
		web_log(ERROR, "ERROR", "Only get method can support", 0);

	p = strtok(NULL, " ");
	if (!strcmp(p, "/"))
		sprintf(uri, "%s/index.html", documentRoot);	//경로를 이런식으로 넘겨야 했네..
	else
		sprintf(uri, "%s%s", documentRoot, p);

	strcpy(c_type, "text/plain");
	for (i = 0; extensions[i].ext != 0; i++)
	{
		len = strlen(extensions[i].ext);
		if (!strncmp(uri + strlen(uri) - len, extensions[i].ext, len))
		{
			strcpy(c_type, extensions[i].filetype);
			break;
		}
	}

	if ((fd = open(uri, O_RDONLY)) < 0)
	{
		code = CODE404;
		strcpy(phrase, PHRASE404);
	}

	p = strtok(NULL, "\r\n ");	// version

	// send Header
	sprintf(sndBuf, "HTTP/2.0 %d %s\r\n", code, phrase);
	n = write(c_sock, sndBuf, strlen(sndBuf));
	web_log(LOG, "RESPONSE", sndBuf, getpid());

	sprintf(sndBuf, "content-type: %s\r\n\r\n", c_type);
	n = write(c_sock, sndBuf, strlen(sndBuf));
	web_log(LOG, "RESPONSE", sndBuf, getpid());

	if (fd >= 0)
	{
		while ((n = read(fd, rcvBuf, BUFSIZ)) > 0)
		{
			write(c_sock, rcvBuf, n);
		}
	}

	close(c_sock);
	exit(-1);
}

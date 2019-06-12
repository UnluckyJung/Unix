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



//한글주석 쓰게 utf-8형식으로 변환함
int main(int argc, char *argv[])
{

	char HTTP_send_buf[256] = "HTTP/2.0 200 OK\r\n";	//http 헤더 선언.

	char path[256];	//경로를 저장해둘 배열
	getcwd(path, 255);	//현재 경로를 받아서 path에 넣는다.
	//sprintf(path, "%s/%s", path, "example");	//현재 위치의 example에 접근해야하니 path에 이어 붙임.
	sprintf(path, "%s%s", path, argv[1]);	//현재 위치의 example에 접근해야하니 path에 이어 붙임.


	struct sockaddr_in sin, cli;	//소켓 통신을 위한 변수.
	int sd, ns;	//서버와 클라의 소켓을 위한 변수.
	int len;	//길이를 저장할 변수.
	int i;


	char *findnum1;	//cgi에서 사용될 포인터
	char *findnum2;	//cgi에서 사용될 포인터
	char numarr[10] = { 0, };	//cgi에서 사용될 배열, 첫번째 숫자를 저장해두는 공간.
	char numarr2[10] = { 0, };	//cgi에서 사용될 배열, 두번째 숫자를 저장해두는 공간.
	char numcheck[10] = { 0, };	//cgi에서 사용될 배열, 숫자인지를 확일할떄 사용될 예정.
	int size = 0;

	int n;
	char *p;	//클라이 언트에게 요청받은 부분에서 자른부분을 이용한 변수.

	int fd;	//파일 전송할때 필요한 변수.

	int fd_log;	//log 저장할때 저수준 파일입출력 open에 필요한 변수.
	char address_log[BUFSIZ];	//log 저장할 BUF

	long long num1;	//cgi에서 샤용될 숫자를 저장할 공간.
	long long num2;	
	long long result;



	/*
	if (argc != 2)
	{
		printf("Please enter portnum\n");
		return -1;
	}
	*/

	if (access("./log.txt", 0) == 0)	//log.txt가 있으면,
		system("rm log.txt");	//log.txt 삭제하고 시작.

	//반복 작업시 화면이 엑박 뜨는것을 방지하기 위한 도구.
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
	sin.sin_port = htons(atoi(argv[2]));
	//만약 서버에 네트워크 카드가 여러개 있다면?
	//1.1.1.1 이런식으로 지명해주는데, 모두가 다 받는다는 가정은 0.0.0.0으로 하는거다.


	if (bind(sd, (struct sockaddr *)&sin, sizeof(sin))) { 	//bind를 함. 소켓을 IP주소와 결합하는것.
		perror("bind");
		exit(1);
	}


	if (listen(sd, 200)) {	//클라이언트 접속 요청을 대기한다.
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


		switch (fork())	//accept가 되엇을경우 fork를 시작함.
		{
		case 0:

			//fork가 정상적으로 실행되었을경우.

			close(sd);	//서버측의 sd를 닫는다.
			char Send_Buf[BUFSIZ + 1] = { 0, }, Receive_Buf[BUFSIZ + 1] = { 0, };	//보내기, 받기 할 BUf 선언.
			char uri[100], content_type[20] = { 0, };	//uri와 content의 타비을 저장할 배열.



			struct //파일타입을 확인하기 위한 구조체
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
				"htm", "text/html"},
				{
				"html", "text/html"},
				{
			0, 0} };


			n = read(ns, Receive_Buf, BUFSIZ);	//클라리언트가 무엇을 요청하는지 받아서 Receive_Buf에 넣는다.



			p = strtok(Receive_Buf, " ");	//빈공간을 기준으로, 받은 요청을 잘라서 포인터에 넣는다.
			p = strtok(NULL, " ");	


			//if ((findnum1 = strstr(p, "total.cgi?from=")) != NULL) {

			if (!(strcmp(p, "/images")))	//images
			{
				char NOTFOUND[20] = "Not found";	//Not found를 보내기 위한 작업.

				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n"

					"Content-Type: text/html\r\n"

					"\r\n"

					"%s\r\n", 200, "OK", NOTFOUND);

				write(ns, Send_Buf, strlen(Send_Buf));




				//============NOT FOUND 로그 찍기 구현.================



				sprintf(path, "%s/%s", path, NOTFOUND);	//Not found 로그를 찍기위한 path 세팅


				sprintf(address_log, "%s %s %d \n", inet_ntoa(cli.sin_addr), path, (int)strlen(NOTFOUND));
				//접속 IP, 요청 경로, NOTFOUND의 문자열 길이를 addrss_log에 넣음.

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644으로 설정

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);	//로그를 기록할 log.txt를 생성하거나 연다.
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);

				//============NOT FOUND 로그 찍기 구현.================

				close(ns);
				return 0;

			}



			//==================cgi start ==========================


			if ((findnum1 = strstr(p, "total.cgi?from=")) != NULL) {
				sprintf(numarr, "%c", *(findnum1 + 15));	//total.cgi?from= (15개) 다음부터를 숫자로 인식.

				for (int i = 16; i <= 25; i++) {	//두번째 자릿수 확인 13이면 1다음인 3을확인
					sprintf(numcheck, "%c", *(findnum1 + i));	//숫자인지 체크하기위한 numcheck에 해당 값을 넣음(숫자던,아니던 다들어감)
					if (strncmp("&", numcheck, 1) == 0)	//들어간것이 &라면? 숫자가 아님.
						break;	//for문 끝
					sprintf(numarr, "%s%c", numarr, *(findnum1 + i));	//숫자라면 문자열 뒤(1)에 해당 숫자(3)를 붙여넣음  문자열 13완성.
				}

				if ((findnum2 = strstr(p, "to=")) != NULL) {	//to=를 찾은 부분의 포인터를 리턴함.
					sprintf(numarr2, "%c", *(findnum2 + 3));	//to=(3개) 다음부터를 숫자로 인식



					for (int i = 4; i <= 10; i++) {	//to=이 3개라서 4부터 for문 시작
						sprintf(numcheck, "%c", *(findnum2 + i));	//숫자인지 체크하기위한 numcheck2에 해당 값을 넣음(숫자던,아니던 다들어감)
						if (numcheck[0] < 48 || numcheck[0]>57)	//들어간값이 숫자 아스키코드 범위 내인지 확인함.
							break;	//아니라면 스톱
						sprintf(numarr2, "%s%c", numarr2, *(findnum2 + i));	//맞다면, 숫자문자열 뒤에 해당문자를 이어 붙임.
					}

				}

				num1 = atoll(numarr);	//문자열을 정수로 변환
				num2 = atoll(numarr2);
				result = (num2*(num2 + 1) / 2 - (num1 - 1) * (num1) / 2);	//들어온 숫자들의 합을 계산


				char result_char[50] = { 0, };	//결과를 저장할 배열.
				sprintf(result_char, "%lld", result);	//결과를 문자열로 변경함.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n"	//클라이언트에게 헤더, 컨텐츠 타입, 결과값을 전송함.

					"Content-Type: text	/html\r\n"

					"\r\n"

					"%s\r\n", 200, "OK", result_char);	

				write(ns, Send_Buf, strlen(Send_Buf));


				//============로그 찍기 구현.================


				sprintf(uri, "%s%s", path, p);	//uri에 요청받는 모든 경로를 넣음.

				sprintf(address_log, "%s %s %d \n", inet_ntoa(cli.sin_addr), uri, (int)strlen(result_char));
				//접속자 IP, 요청받는것, 요청받는것의 길이. 여기서 strlen을 사용한 이유는 예를들어 "12" 즉 2자리인경우 2byte를 보내기 위해서 사용.



				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644로 설정.

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);	//log.txt파일을 생성, 혹은 연다.
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));	//log파일을 기록한다.
				close(fd_log);	//log파일을 닫는다.

				//============로그 찍기 구현.================

				close(ns);	//클라이언트쪽의 소켓을 닫는다.
				return 0;

			}

			//==================cgi end ==========================



			if (!strcmp(p, "/"))	//만약 /가 없는경우, 즉 요청받는 파일이 없는경우?
				sprintf(uri, "%s/index.html", path);	//index.html을 uri에 넣는다.
			else
				sprintf(uri, "%s%s", path, p);	//uri에 요청받는 모든 경로를 넣음.

			//memcpy strcpy 속도비교용
			memcpy(content_type, "text/plain", 11);
			//strcpy(content_type, "text/plain");

			for (i = 0; extensions[i].ext != 0; i++)		//요청받는것이 어느 파일타입인지 확인하기 위한 for문.
			{
				len = strlen(extensions[i].ext);
				if (!strncmp(uri + strlen(uri) - len, extensions[i].ext, len))
				{
					strcpy(content_type, extensions[i].filetype);
					break;
				}
			}


			fd = open(uri, O_RDONLY);	//요청받는것의 위치의 파일을 연다.


			if (fd == -1)	//만약 없다면?
			{
				char NOTFOUND[20] = "Not found";	//Not found를 보내기 위한 작업.

				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n"

					"Content-Type: text/html\r\n"

					"\r\n"

					"%s\r\n", 200, "OK", NOTFOUND);	

				write(ns, Send_Buf, strlen(Send_Buf));




				//============NOT FOUND 로그 찍기 구현.================



				sprintf(path, "%s/%s", path, NOTFOUND);	//Not found 로그를 찍기위한 path 세팅


				sprintf(address_log, "%s %s %d \n", inet_ntoa(cli.sin_addr), path, (int)strlen(NOTFOUND));
				//접속 IP, 요청 경로, NOTFOUND의 문자열 길이를 addrss_log에 넣음.

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644으로 설정

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);	//로그를 기록할 log.txt를 생성하거나 연다.
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);

				//============NOT FOUND 로그 찍기 구현.================

				close(ns);
				return 0;

			}


			//==========cgi도 아니고, NOT FOUND도 아닌경우=================
			p = strtok(NULL, "\r\n ");


			// http 형식을 보내주는것.
			//sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");
			n = write(ns, HTTP_send_buf, strlen(HTTP_send_buf));	//앞에 선언했언 HTTP를 보냄.

			sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//content_type을 명시해서 보내줌.
			n = write(ns, Send_Buf, strlen(Send_Buf));


			if (fd >= 0)	//경로의 파일이 존재하는경우?
			{
				while ((n = read(fd, Receive_Buf, BUFSIZ)) > 0)	//fd에서 BUFSIZ만큼 계속 읽어서 Receive_BUF에 넣은다음에
				{
					write(ns, Receive_Buf, n);	//그것을 클라이언트에게 전송해준다.
				}
			}








			//저수준 파일 입출력을 이용한 log file 생성.

			struct stat file_info;	//파일크기를 측정하기위한 stat 구조체
			stat(uri, &file_info);


			//memcpy strcat 속도 측정
			//memcpy(address_log, inet_ntoa(cli.sin_addr), sizeof(inet_ntoa(cli.sin_addr)));
			//strcpy(address_log, inet_ntoa(cli.sin_addr));
			//strcat(address_log, " ");
			//strcat(address_log, uri);
			//sprintf(address_log, "%s %d\n", address_log, (int)file_info.st_size);

			//위에꺼하니 더느려짐

			sprintf(address_log, "%s %s %d \n", inet_ntoa(cli.sin_addr), uri, (int)file_info.st_size);
			//접속 IP, 요청 경로, NOTFOUND의 파일 크기를 addrss_log에 넣음.

			mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

			fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);	//log.txt파일을 연다.
			if (fd_log == -1) {
				perror("Open log.txt");
				exit(1);
			}
			write(fd_log, address_log, strlen(address_log));	//로그를 기록한다.
			close(fd_log);


			close(ns);
			exit(-1);

		default:
			close(ns);
		}

	}

	return 0;
}
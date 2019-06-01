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


//char path[] = "/home/201414840/html";



//한글주석 쓰게 utf-8형식으로 변환함
int main(int argc, char *argv[])
{

	char HTTP_send_buf[256] = "HTTP/2.0 200 OK\r\n";

	char path[256];
	getcwd(path, 255);
	sprintf(path, "%s/%s", path, "example");

	struct sockaddr_in sin, cli;
	int sd, ns;
	int len;
	int i;


	char *findnum1;
	char *findnum2;
	char numarr[10] = { 0, };
	char numarr2[10] = { 0, };
	char numcheck[10] = { 0, };
	int size = 0;

	int n;
	char *p;

	int fd;	//파일 전송할때 필요한 변수.

	int fd_log;	//log 저장할때 저수준 파일입출력 open에 필요한 변수.
	char address_log[BUFSIZ];	//log 저장할 BUF

	long long num1;
	long long num2;
	long long result;



	//굳이 필요 없는 부분, 일단 놔둠.
	if (argc != 2)
	{
		printf("Please enter portnum\n");
		return -1;
	}

	if (access("./log.txt", 0) == 0)
		system("rm log.txt");	//log.txt 삭제하고 시작.

		//이 부분들이 없으면 , 작업도중에 엑박남.
	(void)signal(SIGCLD, SIG_IGN);
	(void)signal(SIGHUP, SIG_IGN);




	if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		//소켓을 만든다. (서버를 만들것.)
		// 소켓종류(INET) / 통신방식 / 프로토콜
		perror("socket");
		exit(1);
	}

	int optvalue = 1;
	setsockopt(ns, SOL_SOCKET, SO_REUSEADDR, &optvalue, sizeof(optvalue));	//소켓 초기화 도구

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


	if (listen(sd, 20)) {	//클라이언트 접속 요청을 대기한다.
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


		switch (fork())
		{
		case 0:

			//함수 부르는 시간도 아까워서 여기다 다 때려넣음

			close(sd);
			char Send_Buf[BUFSIZ + 1] = { 0, }, Receive_Buf[BUFSIZ + 1] = { 0, };
			char uri[100], content_type[20] = { 0, };



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
				"htm", "text/html"},
				{
				"html", "text/html"},
				{
			0, 0} };


			n = read(ns, Receive_Buf, BUFSIZ);	//클라리언트가 무엇을 요청하는지 받아서 Receive_Buf에 넣는다.



			p = strtok(Receive_Buf, " ");
			p = strtok(NULL, " ");




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

				num1 = atoll(numarr);	//범위 때문에 longlong으로 변환했다.
				num2 = atoll(numarr2);
				result = (num2*(num2 + 1) / 2 - (num1 - 1) * (num1) / 2);

				//printf("%lld ~ %lld = %lld\n", num1, num2, result);
				//이거 계산할때마다 숫자 깎이나 확인할때 용도로 사용했었음.

				char result_char[50] = { 0, };
				sprintf(result_char, "%lld", result);


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n"

					"Content-Type: text	/html\r\n"

					"\r\n"

					"%s\r\n", 200, "OK", result_char);	//이거 200메시지를 보내줬어야함.

				write(ns, Send_Buf, strlen(Send_Buf));




				//============로그 찍기 구현.================


				sprintf(uri, "%s%s", path, p);	//uri에 요청받는 모든 경로를 넣음.

				sprintf(address_log, "%s %s %d \n", inet_ntoa(cli.sin_addr), uri, (int)strlen(result_char));



				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);

				//============로그 찍기 구현.================

				close(ns);
				return 0;

			}

			//==================cgi end ==========================



			if (!strcmp(p, "/"))
				sprintf(uri, "%s/index.html", path);	//경로 넘기기.
			else
				sprintf(uri, "%s%s", path, p);	//uri에 요청받는 모든 경로를 넣음.

			//memcpy strcpy 속도비교용
			memcpy(content_type, "text/plain", sizeof("text/plain"));
			//strcpy(content_type, "text/plain");

			for (i = 0; extensions[i].ext != 0; i++)	
			{
				len = strlen(extensions[i].ext);
				if (!strncmp(uri + strlen(uri) - len, extensions[i].ext, len))
				{
					strcpy(content_type, extensions[i].filetype);
					break;
				}
			}



			//printf("%s\n", uri);


			fd = open(uri, O_RDONLY);	//배열을 이용할꺼면, uri로 가서 open하는것이 아닌, 원하는것이 해당 배열 목록에 있는지를 확인하고 그것을 보내줘야한다.






			if (fd == -1)	//이부분 조건도 바꿔야함. 요청하는것이 배열 목록중에 있는지를 확인하고 없는경우
			{
				char NOTFOUND[20] = "Not found";

				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n"

					"Content-Type: text/html\r\n"

					"\r\n"

					"%s\r\n", 200, "OK", NOTFOUND);	//이거 200메시지를 보내줬어야함.

				write(ns, Send_Buf, strlen(Send_Buf));




				//============NOT FOUND 로그 찍기 구현.================



				sprintf(path, "%s/%s", path, NOTFOUND);	//home/201414840/html/Not Found 이런식으로 보낼테니 path에서 작업.


				sprintf(address_log, "%s %s %d \n", inet_ntoa(cli.sin_addr), path, (int)strlen(NOTFOUND));

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
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



			p = strtok(NULL, "\r\n ");


			// http 형식을 보내주는것.
			//sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");
			n = write(ns, HTTP_send_buf, strlen(HTTP_send_buf));	//앞에 선언했언 HTTP를 보냄.

			sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);
			n = write(ns, Send_Buf, strlen(Send_Buf));


			if (fd >= 0)	//fd가 있는경우에 돌아가는 작업이다. 이것도 요청하는게 배열 목록중에 있는경우, 돌아가는것으로 바꿔야한다.
			{
				while ((n = read(fd, Receive_Buf, BUFSIZ)) > 0)	//fd에서 BUFSIZ만큼 계속 읽어서 Receive_BUF에 넣은다음에
				{
					write(ns, Receive_Buf, n);	//그것을 클라이언트에게 전송해주는데 이것도 바꿔야함. (여기서 n은 실제로 읽어온 byte의 수)
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
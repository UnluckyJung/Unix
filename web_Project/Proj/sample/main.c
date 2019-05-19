//TCP (server)

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<inttypes.h>
#include<sys/un.h>
#include<unistd.h>
#include<time.h>

#define PORTNUM 13693
//포트번호 설정.

int main(void) {


	char buf[8000];

	char line[100];
	//html 파일을 읽어올 버퍼

	char htmldata[8000];
	//html 정보를 담을곳

	char httpdata[8000] = "HTTP/2.0 200 OK\r\n\n";
	//유저에게 넘길 데이터
	//이때 http/1.1과 같이 http 버전을 설정해줘야한다.


	FILE *htmlfp = fopen("../html/home.htm", "r");
	//home.html 를 가르키는  파일 포인터를 만든다.

	while (fgets(line, sizeof(line), htmlfp) != 0) {
		strcat(htmldata, line);
	}
	//html의 데이터를htmldata에 넣는작업

	strcat(httpdata, htmldata);
	//httpdata에 htmldata를 이어붙인다.
	//HTTP/1.1 200 OK\r\n\n(htmldata)

	sprintf(buf, "%s", httpdata);
	//httpdata 전부를 buf에 넣는다.


	struct sockaddr_in sin, cli;	//인터넷 소켓의 주소 구조체 생성.
	int sd, ns, clientlen = sizeof(cli);


	//srand(time(NULL));

	if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		//소켓을 만든다. (서버를 만들것.)
		// 소켓종류(INET) / 통신방식 / 프로토콜
		perror("socket");
		exit(1);
	}

	//bind를 하기위한 sin 세팅
	//소켓 주소 구조체를 생성하는 과정.
	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM);
	sin.sin_addr.s_addr = inet_addr("0.0.0.0");	//net_addr은 문자열 형태의 IP주소를 숫자형태로 변환하는것.
	//만약 서버에 네트워크 카드가 여러개 있다면?
	//1.1.1.1 이런식으로 지명해주는데, 모두가 다 받는다는 가정은 0.0.0.0으로 하는거다.


	if (bind(sd, (struct sockaddr *)&sin, sizeof(sin))) { 	//bind를 함. 소켓을 IP주소와 결합하는것.
		perror("bind");
		exit(1);
	}


	printf("Waiting clinet...\n");


	if (listen(sd, 5)) {	//클라이언트 접속 요청을 대기한다.
		//5는 최대 허용 클라이언트가 5개라는 이야기.
		perror("listen");
		exit(1);
	}

	/*sprintf(buf, "HTTP/2.0\r\n"


				"Content-Type: text/html\r\n"

				"\r\n"

				"sample HTTP server\r\n");
	*/

	for (;;) {
		if ((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1) {	//클라이언트와 연결하는 과정.
												//cli에 접속을 요청한 클라이언트의 IP 정보가 있음.
			//accept를 기다린다.
			//connect가 될떄까지 기다린다.
			//connect가 되면 리턴되어짐.
			perror("accept");
			exit(1);
		}

		if (send(ns, buf, strlen(buf) + 1, 0) == -1) {	//클라이언트(ns)로 데이터 보내기
			perror("send");
			exit(1);
		}
		close(ns);
	}

	//sleep(10);
	//while(1){}




	//close(ns);
	close(sd);
	return 0;
}




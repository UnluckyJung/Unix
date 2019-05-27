//Thread (server)

#include<stdio.h>
#include<stdlib.h>

#include<fcntl.h>

#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<sys/resource.h>
#include<sys/stat.h>



#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<inttypes.h>
#include<signal.h>


#include<unistd.h>
#include<pthread.h>	//스레드를 위한 헤더.

#define PORTNUM 13693

char documentRoot[] = "/home/201414840/html";

/*
void *sender(void *arg) {
	char buf[256];
	int *ns = (int *)arg;

	strcpy(buf, "Welcome to Server");
	if (send(*ns, buf, strlen(buf) + 1, 0) == -1) {
		// buf를 Client(ns)에게 send한다.
		perror("send");
		exit(1);
	}
	if (recv(*ns, buf, sizeof(buf), 0) == -1) {
	//Client(ns)로부터 메시지를 받아 buf에 넣는다.
		perror("recv");
		exit(1);
	}
	printf("** From Client : %s\n", buf);
	close(*ns);
	free(ns);
	return NULL;
}

*/

void *web(void *arg) {
	printf("web is working\n");

	char send_buf[256];
	char receive_buf[256];

	char path[100], c_type[20];	//c_type이 뭔지 모르겠음.

	int len;
	int len_out;
	int n, i;
	char *p;
	char method[10], f_name[20];
	//char phrase[20] = "OK";

	int code = 200;	//html 양식을 위한 code 번호.
	int fd;

	char file_name[20];
	char ext[20];

	int *ns = (int *)arg;


	struct stat sbuf;

	struct
	{
		char *ext;	//ext가 무슨 역할인지 모르겠음.
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


	printf("Define is working\n");


	read(*ns, receive_buf, BUFSIZ);
	/*
	if (recv(*ns, receive_buf, sizeof(receive_buf), 0) == -1) {
		//Client(ns)로부터 메시지를 받아 buf에 넣는다.
		perror("recv");
		exit(1);
	}
	*/

	printf("First recv is working\n");

	p = strtok(receive_buf, " ");
	p = strtok(NULL, " ");	//공백나오면 자른다.
	printf("strtok is working\n");

	if (!strcmp(p, "/"))	//잘라낸 부분이 /이 아닐경우 = 즉 default일경우.
		sprintf(path, "%s/index.html", documentRoot);	//경로를 이런식으로 넘겨야 했네..
	else
		sprintf(path, "%s%s", documentRoot, p);

	printf("sprintf is working\n");


	//나 이부분이 뭐하는건지 모르겠음.
	strcpy(c_type, "text/plain");
	for (i = 0; extensions[i].ext != 0; i++)
	{
		len = strlen(extensions[i].ext);
		if (!strncmp(path + strlen(path) - len, extensions[i].ext, len))
		{
			strcpy(c_type, extensions[i].filetype);
			break;
		}
	}
	//나 이부분이 뭐하는건지 모르겠음.



	fd = open(path, O_RDONLY);

	if (fd == -1) {
		perror("HTML FILE");
		exit(1);
	}

	p = strtok(NULL, "\r\n ");	// version

	sprintf(send_buf, "HTTP/2.0 %d %s\r\n", code, "OK");
	write(*ns, send_buf, strlen(send_buf));

	/*
	if (send(*ns, send_buf, strlen(send_buf) + 1, 0) == -1) {
		// buf를 Client(ns)에게 send한다.
		perror("send");
		exit(1);
	}
	*/



	sprintf(send_buf, "content-type: %s\r\n\r\n", c_type);
	write(*ns, send_buf, strlen(send_buf));


	/*
	if (send(*ns, send_buf, strlen(send_buf) + 1, 0) == -1) {
		// buf를 Client(ns)에게 send한다.
		perror("send");
		exit(1);
	}
	*/

	if (fd >= 0)
	{
		while ((*ns = read(fd, receive_buf, BUFSIZ)) > 0)
		{
			write(*ns, receive_buf, n);
		}
	}




	/*
	//strcpy(buf, "Welcome to Server");
	if (send(*ns, buf, strlen(buf) + 1, 0) == -1) {
		// buf를 Client(ns)에게 send한다.
		perror("send");
		exit(1);
	}
	if (recv(*ns, buf, sizeof(buf), 0) == -1) {
		//Client(ns)로부터 메시지를 받아 buf에 넣는다.
		perror("recv");
		exit(1);
	}
	printf("** From Client : %s\n", buf);


	*/


	close(*ns);
	free(ns);
	return NULL;
}


/*
void web_log(int type, char s1[], char s2[], int n)
{
	int log_fd;
	char buf[BUFSIZ];

	if (type == LOG)
	{
		sprintf(buf, "%s %s %d\n", s1, s2, n);
	}



	if ((log_fd = open("web.log", O_CREAT | O_WRONLY | O_APPEND, 0644)) >= 0)
	{
		write(log_fd, buf, strlen(buf));
		close(log_fd);
	}

	if (type == ERROR)
		exit(-1);

}
*/













int main(int argc, char *argv[]) {
	pthread_t tid;
	char buf[256];
	struct sockaddr_in sin, cli;
	int sd, Clientlen = sizeof(cli);
	int *ns;


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

	printf("before while is ok\n");
	while (1) {
		ns = (int *)malloc(sizeof(int));	//ns를 동적 할당해줌.
		if ((*ns = accept(sd, (struct sockaddr *)&cli, &Clientlen)) == -1) {
			//클라이언트와 연결하는 과정 = 클라이언트 접속.
			//accept를 기다린다.
			//connect가 될떄까지 기다린다.
			//connect가 되면 리턴되어짐.
			perror("accept");
			exit(1);
		}


		int optvalue = 1;
		setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &optvalue, sizeof(optvalue));


		pthread_create(&tid, NULL, web, ns);
		printf("thread_create is ok\n");

		//thread를 실행하면서, 넘기는 data는 ns로 준다.

	}

	return 0;
}


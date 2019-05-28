#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main() {

	char buf[256];
	sprintf(buf, "HTTP/2.0\r\n"

		"Content-Type: text/html\r\n"
		"\r\n"
		"sample HTTP server\r\n");

	printf("%s\n", buf);
}
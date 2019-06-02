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

	char path[256];
	getcwd(path, 255);
	sprintf(path, "%s/%s", path, "example");

	struct sockaddr_in sin, cli;
	int sd, ns;
	int len;
	int i;

	//======for banner1.jpg===============

	char banner1_Buf[13000] = { 0 };
	char banner1_path[256] = { 0, };
	sprintf(banner1_path, "%s%s", path, "/banner1.jpg");
	int banner1_fd;
	int banner1_size;

	banner1_fd = open(banner1_path, O_RDONLY);
	banner1_size = read(banner1_fd, banner1_Buf, 13000);	//banner1_Buf에다가 banner1.html의 data를 넣고, banner1_size에다가 banner1.html의 총 크기를 넣음

	struct stat banner1_info;	//파일크기를 측정하기위한 stat 구조체

	stat(banner1_path, &banner1_info);
	sprintf(banner1_path, "%s %d", banner1_path, (int)banner1_info.st_size);	//banner1_path에다가 경로 + banner1 파일크기로 배열에 넣음.


	//======for banner1.jpg===============	



	//======for banner2.jpg===============

	char banner2_Buf[9000] = { 0 };
	char banner2_path[256] = { 0, };
	sprintf(banner2_path, "%s%s", path, "/banner2.jpg");

	int banner2_fd;
	int banner2_size;

	banner2_fd = open(banner2_path, O_RDONLY);
	banner2_size = read(banner2_fd, banner2_Buf, 9000);	//banner2_Buf에다가 banner2.html의 data를 넣고, banner2_size에다가 banner2.html의 총 크기를 넣음

	struct stat banner2_info;	//파일크기를 측정하기위한 stat 구조체

	stat(banner2_path, &banner2_info);
	sprintf(banner2_path, "%s %d", banner2_path, (int)banner2_info.st_size);	//banner2_path에다가 경로 + banner2 파일크기로 배열에 넣음.


	//======for banner2.jpg===============	





	//======for banner3.jpg===============

	char banner3_Buf[18000] = { 0 };
	char banner3_path[256] = { 0, };
	sprintf(banner3_path, "%s%s", path, "/banner3.jpg");
	int banner3_fd;
	int banner3_size;

	banner3_fd = open(banner3_path, O_RDONLY);
	banner3_size = read(banner3_fd, banner3_Buf, 18000);	//banner3_Buf에다가 banner3.html의 data를 넣고, banner3_size에다가 banner3.html의 총 크기를 넣음

	struct stat banner3_info;	//파일크기를 측정하기위한 stat 구조체

	stat(banner3_path, &banner3_info);
	sprintf(banner3_path, "%s %d", banner3_path, (int)banner3_info.st_size);	//banner3_path에다가 경로 + banner3 파일크기로 배열에 넣음.


	//======for banner3.jpg===============	


	//======for bullet1.jpg===============

	char bullet1_Buf[1000] = { 0 };
	char bullet1_path[256] = { 0, };
	sprintf(bullet1_path, "%s%s", path, "/bullet1.jpg");
	int bullet1_fd;
	int bullet1_size;

	bullet1_fd = open(bullet1_path, O_RDONLY);
	bullet1_size = read(bullet1_fd, bullet1_Buf, 1000);	//bullet1_Buf에다가 bullet1.html의 data를 넣고, bullet1_size에다가 bullet1.html의 총 크기를 넣음

	struct stat bullet1_info;	//파일크기를 측정하기위한 stat 구조체

	stat(bullet1_path, &bullet1_info);
	sprintf(bullet1_path, "%s %d", bullet1_path, (int)bullet1_info.st_size);	//bullet1_path에다가 경로 + bullet1 파일크기로 배열에 넣음.


	//======for bullet1.jpg===============	


	//======for bullet2.jpg===============

	char bullet2_Buf[1000] = { 0 };
	char bullet2_path[256] = { 0, };
	sprintf(bullet2_path, "%s%s", path, "/bullet2.jpg");
	int bullet2_fd;
	int bullet2_size;

	bullet2_fd = open(bullet2_path, O_RDONLY);
	bullet2_size = read(bullet2_fd, bullet2_Buf, 1000);	//bullet2_Buf에다가 bullet2.html의 data를 넣고, bullet2_size에다가 bullet2.html의 총 크기를 넣음

	struct stat bullet2_info;	//파일크기를 측정하기위한 stat 구조체

	stat(bullet2_path, &bullet2_info);
	sprintf(bullet2_path, "%s %d", bullet2_path, (int)bullet2_info.st_size);	//bullet2_path에다가 경로 + bullet2 파일크기로 배열에 넣음.


	//======for bullet2.jpg===============	

	//======for bullet3.jpg===============

	char bullet3_Buf[1000] = { 0 };
	char bullet3_path[256] = { 0, };
	sprintf(bullet3_path, "%s%s", path, "/bullet3.jpg");
	int bullet3_fd;
	int bullet3_size;

	bullet3_fd = open(bullet3_path, O_RDONLY);
	bullet3_size = read(bullet3_fd, bullet3_Buf, 1000);	//bullet3_Buf에다가 bullet3.html의 data를 넣고, bullet3_size에다가 bullet3.html의 총 크기를 넣음

	struct stat bullet3_info;	//파일크기를 측정하기위한 stat 구조체

	stat(bullet3_path, &bullet3_info);
	sprintf(bullet3_path, "%s %d", bullet3_path, (int)bullet3_info.st_size);	//bullet3_path에다가 경로 + bullet3 파일크기로 배열에 넣음.


	//======for bullet3.jpg===============	





	//=======================================================jpg end=======================================================


	//======for contact.htm===============

	char contact_Buf[5000] = { 0 };
	char contact_path[256] = { 0, };
	sprintf(contact_path, "%s%s", path, "/contact.htm");
	int contact_fd;
	int contact_size;

	contact_fd = open(contact_path, O_RDONLY);
	contact_size = read(contact_fd, contact_Buf, 5000);	//contact_Buf에다가 contact.html의 data를 넣고, contact_size에다가 contact.html의 총 크기를 넣음

	struct stat contact_info;	//파일크기를 측정하기위한 stat 구조체

	stat(contact_path, &contact_info);
	sprintf(contact_path, "%s %d", contact_path, (int)contact_info.st_size);	//contact_path에다가 경로 + contact 파일크기로 배열에 넣음.


	//======for contact.html===============





	//======for home.htm===============

	char home_Buf[5000] = { 0 };
	char home_path[256] = { 0, };
	sprintf(home_path, "%s%s", path, "/home.htm");
	int home_fd;
	int home_size;

	home_fd = open(home_path, O_RDONLY);
	home_size = read(home_fd, home_Buf, 5000);	//home_Buf에다가 home.html의 data를 넣고, home_size에다가 home.html의 총 크기를 넣음

	struct stat home_info;	//파일크기를 측정하기위한 stat 구조체

	stat(home_path, &home_info);
	sprintf(home_path, "%s %d", home_path, (int)home_info.st_size);	//home_path에다가 경로 + home 파일크기로 배열에 넣음.


	//======for home.html===============	



	//======for icontact.htm===============

	char icontact_Buf[3000] = { 0 };
	char icontact_path[256] = { 0, };
	sprintf(icontact_path, "%s%s", path, "/icontact.htm");
	int icontact_fd;
	int icontact_size;

	icontact_fd = open(icontact_path, O_RDONLY);
	icontact_size = read(icontact_fd, icontact_Buf, 3000);	//icontact_Buf에다가 icontact.html의 data를 넣고, icontact_size에다가 icontact.html의 총 크기를 넣음

	struct stat icontact_info;	//파일크기를 측정하기위한 stat 구조체

	stat(icontact_path, &icontact_info);
	sprintf(icontact_path, "%s %d", icontact_path, (int)icontact_info.st_size);	//icontact_path에다가 경로 + icontact 파일크기로 배열에 넣음.


	//======for icontact.html===============


	//======for ilinks.htm===============

	char ilinks_Buf[4000] = { 0 };
	char ilinks_path[256] = { 0, };
	sprintf(ilinks_path, "%s%s", path, "/ilinks.htm");
	int ilinks_fd;
	int ilinks_size;

	ilinks_fd = open(ilinks_path, O_RDONLY);
	ilinks_size = read(ilinks_fd, ilinks_Buf, 4000);	//ilinks_Buf에다가 ilinks.html의 data를 넣고, ilinks_size에다가 ilinks.html의 총 크기를 넣음

	struct stat ilinks_info;	//파일크기를 측정하기위한 stat 구조체

	stat(ilinks_path, &ilinks_info);
	sprintf(ilinks_path, "%s %d", ilinks_path, (int)ilinks_info.st_size);	//ilinks_path에다가 경로 + ilinks 파일크기로 배열에 넣음.


	//======for ilinks.htm===============


	//======for index.html===============

	char index_Buf[5000] = { 0 };
	char index_path[256] = { 0, };
	sprintf(index_path, "%s%s", path, "/index.html");
	int index_fd;
	int index_size;

	index_fd = open(index_path, O_RDONLY);
	index_size = read(index_fd, index_Buf, 5000);	//index_Buf에다가 index.html의 data를 넣고, index_size에다가 index.html의 총 크기를 넣음

	struct stat index_info;	//파일크기를 측정하기위한 stat 구조체

	stat(index_path, &index_info);
	sprintf(index_path, "%s %d", index_path, (int)index_info.st_size);	//index_path에다가 경로 + index 파일크기로 배열에 넣음.


	//======for index.html===============


	//======for ishop.htm===============

	char ishop_Buf[7000] = { 0 };
	char ishop_path[256] = { 0, };
	sprintf(ishop_path, "%s%s", path, "/ishop.htm");
	int ishop_fd;
	int ishop_size;

	ishop_fd = open(ishop_path, O_RDONLY);
	ishop_size = read(ishop_fd, ishop_Buf, 7000);	//ishop_Buf에다가 ishop.html의 data를 넣고, ishop_size에다가 ishop.html의 총 크기를 넣음

	struct stat ishop_info;	//파일크기를 측정하기위한 stat 구조체

	stat(ishop_path, &ishop_info);
	sprintf(ishop_path, "%s %d", ishop_path, (int)ishop_info.st_size);	//ishop_path에다가 경로 + ishop 파일크기로 배열에 넣음.


	//======for ishop.html===============


	//======for links.htm===============

	char links_Buf[5000] = { 0 };
	char links_path[256] = { 0, };
	sprintf(links_path, "%s%s", path, "/links.htm");
	int links_fd;
	int links_size;

	links_fd = open(links_path, O_RDONLY);
	links_size = read(links_fd, links_Buf, 5000);	//links_Buf에다가 links.html의 data를 넣고, links_size에다가 links.html의 총 크기를 넣음

	struct stat links_info;	//파일크기를 측정하기위한 stat 구조체

	stat(links_path, &links_info);
	sprintf(links_path, "%s %d", links_path, (int)links_info.st_size);	//links_path에다가 경로 + links 파일크기로 배열에 넣음.


	//======for links.html===============


	//======for main.htm===============

	char main_Buf[10000] = { 0 };
	char main_path[256] = { 0, };
	sprintf(main_path, "%s%s", path, "/main.htm");
	int main_fd;
	int main_size;

	main_fd = open(main_path, O_RDONLY);
	main_size = read(main_fd, main_Buf, 10000);	//main_Buf에다가 main.html의 data를 넣고, main_size에다가 main.html의 총 크기를 넣음

	struct stat main_info;	//파일크기를 측정하기위한 stat 구조체

	stat(main_path, &main_info);
	sprintf(main_path, "%s %d", main_path, (int)main_info.st_size);	//main_path에다가 경로 + main 파일크기로 배열에 넣음.


	//======for main.html===============


	//======for shop.htm===============

	char shop_Buf[5000] = { 0 };
	char shop_path[256] = { 0, };
	sprintf(shop_path, "%s%s", path, "/shop.htm");
	int shop_fd;
	int shop_size;

	shop_fd = open(shop_path, O_RDONLY);
	shop_size = read(shop_fd, shop_Buf, 5000);	//shop_Buf에다가 shop.html의 data를 넣고, shop_size에다가 shop.html의 총 크기를 넣음

	struct stat shop_info;	//파일크기를 측정하기위한 stat 구조체

	stat(shop_path, &shop_info);
	sprintf(shop_path, "%s %d", shop_path, (int)shop_info.st_size);	//shop_path에다가 경로 + shop 파일크기로 배열에 넣음.


	//======for shop.html===============





	//=======================================================html end=======================================================

	//======for 05_01.gif===============

	char i05_01_Buf[17200] = { 0 };
	char i05_01_path[256] = { 0, };
	sprintf(i05_01_path, "%s%s", path, "/images/05_01.gif");
	int i05_01_fd;
	int i05_01_size;

	i05_01_fd = open(i05_01_path, O_RDONLY);
	i05_01_size = read(i05_01_fd, i05_01_Buf, 17200);	//05_01_Buf에다가 05_01.html의 data를 넣고, 05_01_size에다가 05_01.gif의 총 크기를 넣음

	struct stat i05_01_info;	//파일크기를 측정하기위한 stat 구조체

	stat(i05_01_path, &i05_01_info);
	sprintf(i05_01_path, "%s %d", i05_01_path, (int)i05_01_info.st_size);	//bac_04_path에다가 경로 + bac_04 파일크기로 배열에 넣음.


	//======for 05_01.gif===============


	//======for 05_02.gif===============

	char i05_02_Buf[150200] = { 0 };
	char i05_02_path[256] = { 0, };
	sprintf(i05_02_path, "%s%s", path, "/images/05_02.gif");
	int i05_02_fd;
	int i05_02_size;

	i05_02_fd = open(i05_02_path, O_RDONLY);
	i05_02_size = read(i05_02_fd, i05_02_Buf, 150200);	//i05_02_Buf에다가 i05_02.html의 data를 넣고, i05_02_size에다가 05_02.gif의 총 크기를 넣음

	struct stat i05_02_info;	//파일크기를 측정하기위한 stat 구조체

	stat(i05_02_path, &i05_02_info);
	sprintf(i05_02_path, "%s %d", i05_02_path, (int)i05_02_info.st_size);	//i05_02_path에다가 경로 + i05_02 파일크기로 배열에 넣음.


	//======for 05_02.gif===============


	//======for 05_03.gif===============

	char i05_03_Buf[28000] = { 0 };
	char i05_03_path[256] = { 0, };
	sprintf(i05_03_path, "%s%s", path, "/images/05_03.gif");
	int i05_03_fd;
	int i05_03_size;

	i05_03_fd = open(i05_03_path, O_RDONLY);
	i05_03_size = read(i05_03_fd, i05_03_Buf, 28000);	//i05_03_Buf에다가 i05_03.html의 data를 넣고, i05_03_size에다가 05_03.gif의 총 크기를 넣음

	struct stat i05_03_info;	//파일크기를 측정하기위한 stat 구조체

	stat(i05_03_path, &i05_03_info);
	sprintf(i05_03_path, "%s %d", i05_03_path, (int)i05_03_info.st_size);	//i05_03_path에다가 경로 + i05_03 파일크기로 배열에 넣음.


	//======for 05_03.gif===============


	//======for 05_04.gif===============

	char i05_04_Buf[8400] = { 0 };
	char i05_04_path[256] = { 0, };
	sprintf(i05_04_path, "%s%s", path, "/images/05_04.gif");
	int i05_04_fd;
	int i05_04_size;

	i05_04_fd = open(i05_04_path, O_RDONLY);
	i05_04_size = read(i05_04_fd, i05_04_Buf, 8400);	//i05_04_Buf에다가 i05_04.html의 data를 넣고, i05_04_size에다가 05_04.gif의 총 크기를 넣음

	struct stat i05_04_info;	//파일크기를 측정하기위한 stat 구조체

	stat(i05_04_path, &i05_04_info);
	sprintf(i05_04_path, "%s %d", i05_04_path, (int)i05_04_info.st_size);	//i05_04_path에다가 경로 + i05_04 파일크기로 배열에 넣음.


	//======for 05_04.gif===============


	//======for 05_04-05_07_over.gif===============

	//char i05_04-05_07_over_Buf[150000] = { 0 };	04-05같이 변수쓰면안됨.
	char i05_04_05_07_over_Buf[8200] = { 0 };
	char i05_04_05_07_over_path[256] = { 0, };
	sprintf(i05_04_05_07_over_path, "%s%s", path, "/images/05_04-05_07_over.gif");
	int i05_04_05_07_over_fd;
	int i05_04_05_07_over_size;

	i05_04_05_07_over_fd = open(i05_04_05_07_over_path, O_RDONLY);
	i05_04_05_07_over_size = read(i05_04_05_07_over_fd, i05_04_05_07_over_Buf, 8200);	//i05_04-05_07_over_Buf에다가 i05_04-05_07_over.html의 data를 넣고, i05_04-05_07_over_size에다가 05_04-05_07_over.gif의 총 크기를 넣음

	struct stat i05_04_05_07_over_info;	//파일크기를 측정하기위한 stat 구조체

	stat(i05_04_05_07_over_path, &i05_04_05_07_over_info);
	sprintf(i05_04_05_07_over_path, "%s %d", i05_04_05_07_over_path, (int)i05_04_05_07_over_info.st_size);	//i05_04-05_07_over_path에다가 경로 + i05_04-05_07_over 파일크기로 배열에 넣음.


	//======for 05_04-05_07_over.gif===============


	//======for 05_04-over.gif===============

	char i05_04_over_Buf[8200] = { 0 };
	char i05_04_over_path[256] = { 0, };
	sprintf(i05_04_over_path, "%s%s", path, "/images/05_04-over.gif");
	int i05_04_over_fd;
	int i05_04_over_size;

	i05_04_over_fd = open(i05_04_over_path, O_RDONLY);
	i05_04_over_size = read(i05_04_over_fd, i05_04_over_Buf, 8200);	//i05_04-over_Buf에다가 i05_04-over.html의 data를 넣고, i05_04-over_size에다가 05_04-over.gif의 총 크기를 넣음

	struct stat i05_04_over_info;	//파일크기를 측정하기위한 stat 구조체

	stat(i05_04_over_path, &i05_04_over_info);
	sprintf(i05_04_over_path, "%s %d", i05_04_over_path, (int)i05_04_over_info.st_size);	//i05_04-over_path에다가 경로 + i05_04-over 파일크기로 배열에 넣음.


	//======for 05_04-over.gif===============

	//======for 05_05.gif===============

	char i05_05_Buf[14200] = { 0 };
	char i05_05_path[256] = { 0, };
	sprintf(i05_05_path, "%s%s", path, "/images/05_05.gif");
	int i05_05_fd;
	int i05_05_size;

	i05_05_fd = open(i05_05_path, O_RDONLY);
	i05_05_size = read(i05_05_fd, i05_05_Buf, 14200);	//i05_05_Buf에다가 i05_05.html의 data를 넣고, i05_05_size에다가 05_05.gif의 총 크기를 넣음

	struct stat i05_05_info;	//파일크기를 측정하기위한 stat 구조체

	stat(i05_05_path, &i05_05_info);
	sprintf(i05_05_path, "%s %d", i05_05_path, (int)i05_05_info.st_size);	//i05_05_path에다가 경로 + i05_05 파일크기로 배열에 넣음.


	//======for 05_05.gif===============

	//======for 05_06.gif===============

	char i05_06_Buf[9200] = { 0 };
	char i05_06_path[256] = { 0, };
	sprintf(i05_06_path, "%s%s", path, "/images/05_06.gif");
	int i05_06_fd;
	int i05_06_size;

	i05_06_fd = open(i05_06_path, O_RDONLY);
	i05_06_size = read(i05_06_fd, i05_06_Buf, 9200);	//i05_06_Buf에다가 i05_06.html의 data를 넣고, i05_06_size에다가 05_06.gif의 총 크기를 넣음

	struct stat i05_06_info;	//파일크기를 측정하기위한 stat 구조체

	stat(i05_06_path, &i05_06_info);
	sprintf(i05_06_path, "%s %d", i05_06_path, (int)i05_06_info.st_size);	//i05_06_path에다가 경로 + i05_06 파일크기로 배열에 넣음.


	//======for 05_06.gif===============


	//======for 05_06-over.gif===============

	char i05_06_over_Buf[8500] = { 0 };
	char i05_06_over_path[256] = { 0, };
	sprintf(i05_06_over_path, "%s%s", path, "/images/05_06-over.gif");
	int i05_06_over_fd;
	int i05_06_over_size;

	i05_06_over_fd = open(i05_06_over_path, O_RDONLY);
	i05_06_over_size = read(i05_06_over_fd, i05_06_over_Buf, 8500);	//i05_06-over_Buf에다가 i05_06-over.html의 data를 넣고, i05_06-over_size에다가 05_06.gif의 총 크기를 넣음

	struct stat i05_06_over_info;	//파일크기를 측정하기위한 stat 구조체

	stat(i05_06_over_path, &i05_06_over_info);
	sprintf(i05_06_over_path, "%s %d", i05_06_over_path, (int)i05_06_over_info.st_size);	//i05_06-over_path에다가 경로 + i05_06-over 파일크기로 배열에 넣음.


	//======for 05_06.gif===============


	//======for 05_07.gif===============

	char i05_07_Buf[8600] = { 0 };
	char i05_07_path[256] = { 0, };
	sprintf(i05_07_path, "%s%s", path, "/images/05_07.gif");
	int i05_07_fd;
	int i05_07_size;

	i05_07_fd = open(i05_07_path, O_RDONLY);
	i05_07_size = read(i05_07_fd, i05_07_Buf, 8600);	//i05_07_Buf에다가 i05_07.html의 data를 넣고, i05_07_size에다가 05_07.gif의 총 크기를 넣음

	struct stat i05_07_info;	//파일크기를 측정하기위한 stat 구조체

	stat(i05_07_path, &i05_07_info);
	sprintf(i05_07_path, "%s %d", i05_07_path, (int)i05_07_info.st_size);	//i05_07_path에다가 경로 + i05_07 파일크기로 배열에 넣음.


	//======for 05_07.gif===============


	//======for 05_07-over.gif===============

	char i05_07_over_Buf[8500] = { 0 };
	char i05_07_over_path[256] = { 0, };
	sprintf(i05_07_over_path, "%s%s", path, "/images/05_07-over.gif");
	int i05_07_over_fd;
	int i05_07_over_size;

	i05_07_over_fd = open(i05_07_over_path, O_RDONLY);
	i05_07_over_size = read(i05_07_over_fd, i05_07_over_Buf, 8500);	//i05_07_over_Buf에다가 i05_07_over.html의 data를 넣고, i05_07_over_size에다가 05_07.gif의 총 크기를 넣음

	struct stat i05_07_over_info;	//파일크기를 측정하기위한 stat 구조체

	stat(i05_07_over_path, &i05_07_over_info);
	sprintf(i05_07_over_path, "%s %d", i05_07_over_path, (int)i05_07_over_info.st_size);	//i05_07-over_path에다가 경로 + i05_07-over 파일크기로 배열에 넣음.


	//======for 05_07-over.gif===============


	//======for 05_08.gif===============

	char i05_08_Buf[13000] = { 0 };
	char i05_08_path[256] = { 0, };
	sprintf(i05_08_path, "%s%s", path, "/images/05_08.gif");
	int i05_08_fd;
	int i05_08_size;

	i05_08_fd = open(i05_08_path, O_RDONLY);
	i05_08_size = read(i05_08_fd, i05_08_Buf, 13000);	//i05_08_Buf에다가 i05_08.html의 data를 넣고, i05_08_size에다가 05_08.gif의 총 크기를 넣음

	struct stat i05_08_info;	//파일크기를 측정하기위한 stat 구조체

	stat(i05_08_path, &i05_08_info);
	sprintf(i05_08_path, "%s %d", i05_08_path, (int)i05_08_info.st_size);	//i05_08_path에다가 경로 + i05_08 파일크기로 배열에 넣음.


	//======for 05_08.gif===============


	//======for 05_08_over.gif===============

	char i05_08_over_Buf[9400] = { 0 };
	char i05_08_over_path[256] = { 0, };
	sprintf(i05_08_over_path, "%s%s", path, "/images/05_08-over.gif");
	int i05_08_over_fd;
	int i05_08_over_size;

	i05_08_over_fd = open(i05_08_over_path, O_RDONLY);
	i05_08_over_size = read(i05_08_over_fd, i05_08_over_Buf, 9400);	//i05_08_over_Buf에다가 i05_08_over.html의 data를 넣고, i05_08_over_size에다가 05_08.gif의 총 크기를 넣음

	struct stat i05_08_over_info;	//파일크기를 측정하기위한 stat 구조체

	stat(i05_08_over_path, &i05_08_over_info);
	sprintf(i05_08_over_path, "%s %d", i05_08_over_path, (int)i05_08_over_info.st_size);	//i05_08-over_path에다가 경로 + i05_08-over 파일크기로 배열에 넣음.


	//======for 05_08-over.gif===============

	//======for 05_09.gif===============

	char i05_09_Buf[125000] = { 0 };
	char i05_09_path[256] = { 0, };
	sprintf(i05_09_path, "%s%s", path, "/images/05_09.gif");
	int i05_09_fd;
	int i05_09_size;

	i05_09_fd = open(i05_09_path, O_RDONLY);
	i05_09_size = read(i05_09_fd, i05_09_Buf, 125000);	//i05_09_Buf에다가 i05_09.html의 data를 넣고, i05_09_size에다가 05_09.gif의 총 크기를 넣음

	struct stat i05_09_info;	//파일크기를 측정하기위한 stat 구조체

	stat(i05_09_path, &i05_09_info);
	sprintf(i05_09_path, "%s %d", i05_09_path, (int)i05_09_info.st_size);	//i05_09_path에다가 경로 + i05_09 파일크기로 배열에 넣음.


	//======for 05_09.gif===============


	//======for 05_10.gif===============

	char i05_10_Buf[1600] = { 0 };
	char i05_10_path[256] = { 0, };
	sprintf(i05_10_path, "%s%s", path, "/images/05_10.gif");
	int i05_10_fd;
	int i05_10_size;

	i05_10_fd = open(i05_10_path, O_RDONLY);
	i05_10_size = read(i05_10_fd, i05_10_Buf, 1600);	//i05_10_Buf에다가 i05_10.html의 data를 넣고, i05_10_size에다가 05_10.gif의 총 크기를 넣음

	struct stat i05_10_info;	//파일크기를 측정하기위한 stat 구조체

	stat(i05_10_path, &i05_10_info);
	sprintf(i05_10_path, "%s %d", i05_10_path, (int)i05_10_info.st_size);	//i05_10_path에다가 경로 + i05_10 파일크기로 배열에 넣음.


	//======for 05_10.gif===============




	//======for bac_04.jpg===============

	char bac_04_Buf[63200] = { 0 };
	char bac_04_path[256] = { 0, };
	sprintf(bac_04_path, "%s%s", path, "/images/bac_04.jpg");
	int bac_04_fd;
	int bac_04_size;

	bac_04_fd = open(bac_04_path, O_RDONLY);
	bac_04_size = read(bac_04_fd, bac_04_Buf, 63200);	//bac_04_Buf에다가 bac_04.html의 data를 넣고, bac_04_size에다가 bac_04.jpg의 총 크기를 넣음

	struct stat bac_04_info;	//파일크기를 측정하기위한 stat 구조체

	stat(bac_04_path, &bac_04_info);
	sprintf(bac_04_path, "%s %d", bac_04_path, (int)bac_04_info.st_size);	//bac_04_path에다가 경로 + bac_04 파일크기로 배열에 넣음.


	//======for bac_04.jpg===============






	//=======================================================images/jpg end=======================================================






















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
			char uri[100], content_type[20] = { 0, };
			int len;

			int n, i;
			char *p;

			int fd;	//파일 전송할때 필요한 변수.

			int fd_log;	//log 저장할때 저수준 파일입출력 open에 필요한 변수.
			char address_log[BUFSIZ];	//log 저장할 BUF


			//disable for banner1 test
			/*
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
			*/
			//disable for banner1 test

			n = read(ns, Receive_Buf, BUFSIZ);	//클라이언트가 무엇을 요청하는지 받아서 Receive_Buf에 넣는다.



			p = strtok(Receive_Buf, " ");
			p = strtok(NULL, " ");


			//======default(index)================


			if (!strcmp(p, "/")) {	//클라이언트에게 받은 요청중 index_test.html이 있는지 확인


				sprintf(content_type, "%s", "text/html");	//html파일의 타입이 text/html이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 index이 html타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, index_Buf, index_size);	//index_Buf에 담긴 데이터 클라이언트에게 전송하기


				//index 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), index_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for index.htm===============





			//======for banner1.jpg===============

			//char *banner1p;
			else if ((strstr(p, "banner1.jpg")) != NULL) {	//클라이언트에게 받은 요청중 banner1.jpg이 있는지 확인


				sprintf(content_type, "%s", "image/jpeg");	//html파일의 타입이 text/html이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 banner1이 html타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, banner1_Buf, banner1_size);	//banner1_Buf에 담긴 데이터 클라이언트에게 전송하기


				//banner1 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), banner1_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for banner1.jpg===============


			//======for banner2.jpg===============

			//char *banner2p;
			else if ((strstr(p, "banner2.jpg")) != NULL) {	//클라이언트에게 받은 요청중 banner2.jpg이 있는지 확인


				sprintf(content_type, "%s", "image/jpeg");	//html파일의 타입이 text/html이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 banner2이 html타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, banner2_Buf, banner2_size);	//banner2_Buf에 담긴 데이터 클라이언트에게 전송하기


				//banner2 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), banner2_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for banner2.jpg===============




			//======for banner3.jpg===============

			//char *banner3p;
			else if ((strstr(p, "banner3.jpg")) != NULL) {	//클라이언트에게 받은 요청중 banner3.jpg이 있는지 확인


				sprintf(content_type, "%s", "image/jpeg");	//html파일의 타입이 text/html이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 banner3이 html타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, banner3_Buf, banner3_size);	//banner3_Buf에 담긴 데이터 클라이언트에게 전송하기


				//banner3 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), banner3_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for banner3.jpg===============




			//======for bullet1.jpg===============

			//char *bullet1p;
			else if ((strstr(p, "bullet1.jpg")) != NULL) {	//클라이언트에게 받은 요청중 bullet1.jpg이 있는지 확인


				sprintf(content_type, "%s", "image/jpeg");	//html파일의 타입이 text/html이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 bullet1이 html타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, bullet1_Buf, bullet1_size);	//bullet1_Buf에 담긴 데이터 클라이언트에게 전송하기


				//bullet1 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), bullet1_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for bullet1.jpg===============


			//======for bullet2.jpg===============

			//char *bullet2p;
			else if ((strstr(p, "bullet2.jpg")) != NULL) {	//클라이언트에게 받은 요청중 bullet2.jpg이 있는지 확인


				sprintf(content_type, "%s", "image/jpeg");	//html파일의 타입이 text/html이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 bullet2이 html타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, bullet2_Buf, bullet2_size);	//bullet2_Buf에 담긴 데이터 클라이언트에게 전송하기


				//bullet2 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), bullet2_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for bullet2.jpg===============

			//======for bullet3.jpg===============

			//char *bullet3p;
			else if ((strstr(p, "bullet3.jpg")) != NULL) {	//클라이언트에게 받은 요청중 bullet3.jpg이 있는지 확인


				sprintf(content_type, "%s", "image/jpeg");	//html파일의 타입이 text/html이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 bullet3이 html타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, bullet3_Buf, bullet3_size);	//bullet3_Buf에 담긴 데이터 클라이언트에게 전송하기


				//bullet3 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), bullet3_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for bullet3.jpg===============


			//=======================================================jpg end=======================================================




			//======for icontact.htm===============

			//char *icontactp;
			else if ((strstr(p, "icontact.htm")) != NULL) {	//클라이언트에게 받은 요청중 icontact_test.html이 있는지 확인


				sprintf(content_type, "%s", "text/html");	//html파일의 타입이 text/html이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 icontact이 html타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, icontact_Buf, icontact_size);	//icontact_Buf에 담긴 데이터 클라이언트에게 전송하기


				//icontact 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), icontact_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for icontact.htm===============



			//======for contact.htm===============

			//char *contactp;
			else if ((strstr(p, "contact.htm")) != NULL) {	//클라이언트에게 받은 요청중 contact_test.html이 있는지 확인


				sprintf(content_type, "%s", "text/html");	//html파일의 타입이 text/html이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 contact이 html타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, contact_Buf, contact_size);	//contact_Buf에 담긴 데이터 클라이언트에게 전송하기


				//contact 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), contact_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for contact.htm===============


			//======for home.htm===============

			//char *homep;
			else if ((strstr(p, "home.htm")) != NULL) {	//클라이언트에게 받은 요청중 home_test.html이 있는지 확인


				sprintf(content_type, "%s", "text/html");	//html파일의 타입이 text/html이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 home이 html타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, home_Buf, home_size);	//home_Buf에 담긴 데이터 클라이언트에게 전송하기


				//home 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), home_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for home.htm===============


			//======for ilinks.htm===============

			//char *ilinksp;
			else if ((strstr(p, "ilinks.htm")) != NULL) {	//클라이언트에게 받은 요청중 ilinks_test.html이 있는지 확인


				sprintf(content_type, "%s", "text/html");	//html파일의 타입이 text/html이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 ilinks이 html타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, ilinks_Buf, ilinks_size);	//ilinks_Buf에 담긴 데이터 클라이언트에게 전송하기


				//ilinks 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), ilinks_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for ilinks.htm===============


			//======for ishop.htm===============

			//char *ishopp;
			else if ((strstr(p, "ishop.htm")) != NULL) {	//클라이언트에게 받은 요청중 ishop_test.html이 있는지 확인


				sprintf(content_type, "%s", "text/html");	//html파일의 타입이 text/html이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 ishop이 html타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, ishop_Buf, ishop_size);	//ishop_Buf에 담긴 데이터 클라이언트에게 전송하기


				//ishop 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), ishop_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for ishop.htm===============

			//======for shop.htm===============

			//char *shopp;
			else if ((strstr(p, "shop.htm")) != NULL) {	//클라이언트에게 받은 요청중 shop_test.html이 있는지 확인


				sprintf(content_type, "%s", "text/html");	//html파일의 타입이 text/html이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 shop이 html타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, shop_Buf, shop_size);	//shop_Buf에 담긴 데이터 클라이언트에게 전송하기


				//shop 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), shop_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for shop.htm===============

			//======for links.htm===============

			//char *linksp;
			else if ((strstr(p, "links.htm")) != NULL) {	//클라이언트에게 받은 요청중 links_test.html이 있는지 확인


				sprintf(content_type, "%s", "text/html");	//html파일의 타입이 text/html이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 links이 html타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, links_Buf, links_size);	//links_Buf에 담긴 데이터 클라이언트에게 전송하기


				//links 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), links_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for links.htm===============

			//======for main.htm===============

			//char *mainp;
			else if ((strstr(p, "main.htm")) != NULL) {	//클라이언트에게 받은 요청중 main_test.html이 있는지 확인


				sprintf(content_type, "%s", "text/html");	//html파일의 타입이 text/html이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 main이 html타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, main_Buf, main_size);	//main_Buf에 담긴 데이터 클라이언트에게 전송하기


				//main 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), main_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for main.htm===============






			//=======================================================htm end=======================================================

			//======for 05_01.gif===============

			//char *i05_01p;
			else if ((strstr(p, "05_01.gif")) != NULL) {	//클라이언트에게 받은 요청중 i05_01.gif이 있는지 확인


				sprintf(content_type, "%s", "image/gif");	//gif파일의 타입이 imgae/gif이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 i05_01이 jpeg타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, i05_01_Buf, i05_01_size);	//i05_01_Buf에 담긴 데이터 클라이언트에게 전송하기


				//i05_01 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), i05_01_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for 05_01.gif===============


			//======for 05_02.gif===============

			//char *i05_02p;
			else if ((strstr(p, "05_02.gif")) != NULL) {	//클라이언트에게 받은 요청중 i05_02.gif이 있는지 확인


				sprintf(content_type, "%s", "image/gif");	//gif파일의 타입이 imgae/gif이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 i05_02이 jpeg타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, i05_02_Buf, i05_02_size);	//i05_02_Buf에 담긴 데이터 클라이언트에게 전송하기


				//i05_02 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), i05_02_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for 05_02.gif===============


			//======for 05_03.gif===============

			//char *i05_03p;
			else if ((strstr(p, "05_03.gif")) != NULL) {	//클라이언트에게 받은 요청중 i05_03.gif이 있는지 확인


				sprintf(content_type, "%s", "image/gif");	//gif파일의 타입이 imgae/gif이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 i05_03이 jpeg타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, i05_03_Buf, i05_03_size);	//i05_03_Buf에 담긴 데이터 클라이언트에게 전송하기


				//i05_03 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), i05_03_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for 05_03.gif===============

			//======for 05_04-05_07_over.gif===============

			//char *i05_04-05_07_overp;
			else if ((strstr(p, "05_04-05_07_over.gif")) != NULL) {	//클라이언트에게 받은 요청중 i05_04-05_07_over.gif이 있는지 확인


				sprintf(content_type, "%s", "image/gif");	//gif파일의 타입이 imgae/gif이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 i05_04-05_07_over이 jpeg타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, i05_04_05_07_over_Buf, i05_04_05_07_over_size);	//i05_04-05_07_over_Buf에 담긴 데이터 클라이언트에게 전송하기


				//i05_04-05_07_over 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), i05_04_05_07_over_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for 05_04-05_07_over.gif===============

			//======for 05_04-over.gif===============

			//char *i05_04-overp;
			else if ((strstr(p, "05_04-over.gif")) != NULL) {	//클라이언트에게 받은 요청중 i05_04-over.gif이 있는지 확인


				sprintf(content_type, "%s", "image/gif");	//gif파일의 타입이 imgae/gif이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 i05_04-over이 jpeg타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, i05_04_over_Buf, i05_04_over_size);	//i05_04_over_Buf에 담긴 데이터 클라이언트에게 전송하기


				//i05_04_over 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), i05_04_over_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for 05_04-over.gif===============


			//======for 05_04.gif===============

			//char *i05_04p;
			else if ((strstr(p, "05_04.gif")) != NULL) {	//클라이언트에게 받은 요청중 i05_04.gif이 있는지 확인


				sprintf(content_type, "%s", "image/gif");	//gif파일의 타입이 imgae/gif이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 i05_04이 jpeg타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, i05_04_Buf, i05_04_size);	//i05_04_Buf에 담긴 데이터 클라이언트에게 전송하기


				//i05_04 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), i05_04_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for 05_04.gif===============

			//======for 05_05.gif===============

			//char *i05_05p;
			else if ((strstr(p, "05_05.gif")) != NULL) {	//클라이언트에게 받은 요청중 i05_05.gif이 있는지 확인


				sprintf(content_type, "%s", "image/gif");	//gif파일의 타입이 imgae/gif이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 i05_05이 jpeg타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, i05_05_Buf, i05_05_size);	//i05_05_Buf에 담긴 데이터 클라이언트에게 전송하기


				//i05_05 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), i05_05_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for 05_05.gif===============

			//======for 05_06-over.gif===============

			//char *i05_06-overp;
			else if ((strstr(p, "05_06-over.gif")) != NULL) {	//클라이언트에게 받은 요청중 i05_06-over.gif이 있는지 확인


				sprintf(content_type, "%s", "image/gif");	//gif파일의 타입이 imgae/gif이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 i05_06-over이 jpeg타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, i05_06_over_Buf, i05_06_over_size);	//i05_06-over_Buf에 담긴 데이터 클라이언트에게 전송하기


				//i05_06-over 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), i05_06_over_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for 05_06-over.gif===============

			//======for 05_06.gif===============

			//char *i05_06p;
			else if ((strstr(p, "05_06.gif")) != NULL) {	//클라이언트에게 받은 요청중 i05_06.gif이 있는지 확인


				sprintf(content_type, "%s", "image/gif");	//gif파일의 타입이 imgae/gif이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 i05_06이 jpeg타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, i05_06_Buf, i05_06_size);	//i05_06_Buf에 담긴 데이터 클라이언트에게 전송하기


				//i05_06 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), i05_06_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for 05_06.gif===============

			//======for 05_07-over.gif===============

			//char *i05_07-overp;
			else if ((strstr(p, "05_07-over.gif")) != NULL) {	//클라이언트에게 받은 요청중 i05_07-over.gif이 있는지 확인


				sprintf(content_type, "%s", "image/gif");	//gif파일의 타입이 imgae/gif이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 i05_07-over이 jpeg타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, i05_07_over_Buf, i05_07_over_size);	//i05_07-over_Buf에 담긴 데이터 클라이언트에게 전송하기


				//i05_07-over 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), i05_07_over_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for 05_07-over.gif===============

			//======for 05_07.gif===============

			//char *i05_07p;
			else if ((strstr(p, "05_07.gif")) != NULL) {	//클라이언트에게 받은 요청중 i05_07.gif이 있는지 확인


				sprintf(content_type, "%s", "image/gif");	//gif파일의 타입이 imgae/gif이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 i05_07이 jpeg타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, i05_07_Buf, i05_07_size);	//i05_07_Buf에 담긴 데이터 클라이언트에게 전송하기


				//i05_07 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), i05_07_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for 05_07.gif===============

			//======for 05_08-over.gif===============

			//char *i05_08-overp;
			else if ((strstr(p, "05_08-over.gif")) != NULL) {	//클라이언트에게 받은 요청중 i05_08-over.gif이 있는지 확인


				sprintf(content_type, "%s", "image/gif");	//gif파일의 타입이 imgae/gif이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 i05_08-over이 jpeg타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, i05_08_over_Buf, i05_08_over_size);	//i05_08_over_Buf에 담긴 데이터 클라이언트에게 전송하기


				//i05_08_over 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), i05_08_over_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for 05_08-over.gif===============

			//======for 05_08.gif===============

			//char *i05_08p;
			else if ((strstr(p, "05_08.gif")) != NULL) {	//클라이언트에게 받은 요청중 i05_08.gif이 있는지 확인


				sprintf(content_type, "%s", "image/gif");	//gif파일의 타입이 imgae/gif이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 i05_08이 jpeg타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, i05_08_Buf, i05_08_size);	//i05_08_Buf에 담긴 데이터 클라이언트에게 전송하기


				//i05_08 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), i05_08_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for 05_08.gif===============

			//======for 05_09.gif===============

			//char *i05_09p;
			else if ((strstr(p, "05_09.gif")) != NULL) {	//클라이언트에게 받은 요청중 i05_09.gif이 있는지 확인


				sprintf(content_type, "%s", "image/gif");	//gif파일의 타입이 imgae/gif이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 i05_09이 jpeg타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, i05_09_Buf, i05_09_size);	//i05_09_Buf에 담긴 데이터 클라이언트에게 전송하기


				//i05_09 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), i05_09_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for 05_09.gif===============

			//======for 05_10.gif===============

			//char *i05_10p;
			else if ((strstr(p, "05_10.gif")) != NULL) {	//클라이언트에게 받은 요청중 i05_10.gif이 있는지 확인


				sprintf(content_type, "%s", "image/gif");	//gif파일의 타입이 imgae/gif이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 i05_10이 jpeg타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, i05_10_Buf, i05_10_size);	//i05_10_Buf에 담긴 데이터 클라이언트에게 전송하기


				//i05_10 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), i05_10_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for 05_10.gif===============











			//======for bac_04.jpg===============

			//char *bac_04p;
			else if ((strstr(p, "bac_04.jpg")) != NULL) {	//클라이언트에게 받은 요청중 bac_04_test.html이 있는지 확인


				sprintf(content_type, "%s", "image/jpeg");	//html파일의 타입이 text/html이니 저장.


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n", 200, "OK");	//클라이언트에게 HTTP  형식을 보내겠다고 알리기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				sprintf(Send_Buf, "content-type: %s\r\n\r\n", content_type);	//클라이언트에게 bac_04이 jpeg타입인걸 보내기
				n = write(ns, Send_Buf, strlen(Send_Buf));

				write(ns, bac_04_Buf, bac_04_size);	//bac_04_Buf에 담긴 데이터 클라이언트에게 전송하기


				//bac_04 로그 찍기
				sprintf(address_log, "%s %s\n", inet_ntoa(cli.sin_addr), bac_04_path);

				mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	//파일권한 0644

				fd_log = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, mode);
				if (fd_log == -1) {
					perror("Open log.txt");
					exit(1);
				}
				write(fd_log, address_log, strlen(address_log));
				close(fd_log);


				close(ns);
				return 0;
			}

			//======for bac_04.jpg===============








			//==================cgi start ==========================
			char *findnum1;
			char *findnum2;
			char numarr[10] = { 0, };
			char numarr2[10] = { 0, };
			char numcheck[10] = { 0, };






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

				long long num1 = atoll(numarr);	//범위 때문에 longlong으로 변환했다.
				long long num2 = atoll(numarr2);
				long long result = (num2*(num2 + 1) / 2 - (num1 - 1) * (num1) / 2);

				//printf("%lld ~ %lld = %lld\n", num1, num2, result);
				//이거 계산할때마다 숫자 깎이나 확인할때 용도로 사용했었음.

				char result_char[50] = { 0, };
				sprintf(result_char, "%lld", result);


				sprintf(Send_Buf, "HTTP/2.0 %d %s\r\n"

					"Content-Type: text/html\r\n"

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





			//if(fd == -1)	//이부분 조건도 바꿔야함. 요청하는것이 배열 목록중에 있는지를 확인하고 없는경우
			else {
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


		default:
			close(ns);
		}

	}

	return 0;
}
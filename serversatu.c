#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<stdlib.h>
#define MAX 80
#include<string.h>
#define SA struct sockaddr

	void func(int sock)
	{
		char b[MAX];
		int x;
		for(;;)
	{
		bzero(b, MAX);
		read(sock, b, sizeof(b));
		printf("From Client : %s\tTo client: ",b);
		bzero(b, MAX);
		x=0;
		while((b[x++]=getchar())!='\n');
			write(sock,b,sizeof(b));
			if(strncmp("Asalamualaikum", b, 14)==0)
		{
			printf("From client: Waalaikumsalam\n");
			printf("\tTo client: ");
			bzero(b,MAX);
			x=0;
			while((b[x++]=getchar())!='\n');
			write(sock, b, sizeof(b));
		}
	}
}
int main()
{
	int sock, conn, len;
	struct sockaddr_in servaddr, cli;
	sock=socket(AF_INET, SOCK_STREAM, 0);
	if(sock==-1)
	{
		printf("Socket Creation Failed...\n");
		exit(0);
	}
	else
		printf("Socket Successfully Created...\n");
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(36772);
	if((bind(sock, (SA*)&servaddr, sizeof(servaddr)))!=0)
	{
	
		printf("Socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket Successfully Binded...\n");
	if((listen(sock,5))!=0)
	{
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening...\n");
	len=sizeof(cli);
	conn=accept(sock,(SA*)&cli,&len);
	if(conn<0)
	{
		printf("Server accept failed...\n");
		exit(0);
	}
	printf("Server accept the client...\n");
	func(conn);
	close(sock);
}

		
 # ClientServer

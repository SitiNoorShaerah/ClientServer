#include<stdio.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char*argv[])
{
	int clientSock, newSock,c, hostN;
	char message[1000];
	char hostbuff[300];
	char client_IP[300];
	struct sockaddr_in servAddr,client;
	struct sockaddr_storage servStorage;
	socklen_t addrSize;
	
	hostN = gethostname(hostbuff, sizeof(hostbuff));

	clientSock = socket(PF_INET, SOCK_STREAM, 0);
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(36772);
	servAddr.sin_addr.s_addr = inet_addr("192.168.73.129");
	memset(servAddr.sin_zero, '\0', sizeof servAddr.sin_zero);
	int hport=ntohs(servAddr.sin_port);
	char pt[200];
	sprintf(pt, "%d" , hport);
	int cli = sizeof(client);
	getpeername(clientSock, (struct sockaddr *) &client, &cli);
	inet_ntop(AF_INET, &client.sin_addr, client_IP, 
sizeof(client_IP));
	bind(clientSock, (struct sockaddr *) &servAddr, 
			sizeof(servAddr));
	
	if(listen(clientSock, 5)==0)
		printf("Server is listening.......\n");
	else
		printf("Error Occured");
		
	addrSize = sizeof servStorage;
	newSock = accept(clientSock, (struct sockaddr *) &servStorage, 
&addrSize);
	
	puts("Connection Successful");

	while(1)
	{ 
		recv(newSock, message, 100, 0);
		
		char h[] = "Hostname?";
		char i[] = "IPAddress?";
		char g[] = "Asalamualaikum";
		char x[100];
		char q[] = "Quit";
		char p[] = "HostPort";
		char l[] = "ClientIP" ;
		strcpy(x, message);

		if(strcasecmp(x	, g)==0)
		{
			strcpy(message, "Waalaikumusalam\n");
		}
		else if(strcasecmp(x , l)==0)
		{	
			strcpy(message,client_IP);
		} 
		else if(strcasecmp(x , p)==0)
		{	
			strcpy(message,pt);
		}
		else if(strcasecmp(x  ,  h)==0)
		{
			strcpy(message, hostbuff);
		}
		else if(strcasecmp(x   ,   i)==0)
		{
			strcpy(message, inet_ntoa(servAddr.sin_addr));
		}
		else if(strcasecmp(message  ,  q)==0)
		{
			strcpy(message, q);
		}
		else 
		{
			strcpy(message, "COMMAND IS NOT VALID");
		}
		send(newSock, message, 100, 0);
	}
	
		return 0;
}


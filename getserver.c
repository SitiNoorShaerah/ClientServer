#include<stdio.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
	int clientSock, newSock, hostN;
	char message[1000];
	char hostbuff[300];
	struct sockaddr_in servAddr;
	struct sockaddr_storage servStorage;
	socklen_t addrSize;
	
	hostN = gethostname(hostbuff, sizeof(hostbuff));

	clientSock = socket(PF_INET, SOCK_STREAM, 0);
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(36772);
	servAddr.sin_addr.s_addr = inet_addr("192.168.73.129");
	memset(servAddr.sin_zero, '\0', sizeof servAddr.sin_zero);

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
		char i[] = "IP Addr?";
		char g[] = "Asalamualaikum";
		char x[100];
		char q[] = "Quit";
		stcrpy(x, message);

		if(strcasecmp(x	, g)==0)
		{
			strcpy(message, "Waalaikumusalam\n");
		}
		else if(strcasecmp(x  ,  h)==0)
		{
			strcpy(message, hostbuff);
		}
		else if(strcasecmp(x   ,   i)==0)
		{
			strcpy(message, inet_ntoa(servAddr.sin_addr));
		}
		else if(strcasecmp(x  ,  q)==0)
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

# Server

/**************************************************
* Program to implement sliding window protocol,
  between two hosts(TCP Flow Control)
* Client sends the frame
* Server recieves the frame 
***************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h> 
#include<arpa/inet.h> 

#define MAX 20

int main() 
{ 
	int server_fd, sock; 
	char frame[MAX];
	char res[MAX]; // to store all bytes that are recieved successfully
	struct sockaddr_in addr;

	int ack;

	/* creating socket file descriptor */
	/* sockfd = socket(domain, type, protocol) */ 
	server_fd = socket(AF_INET, SOCK_STREAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(1234); 
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	/* attaching socket to port */
	/* bind(fd, addr , addrlen) */
	bind(server_fd, (struct sockaddr *) &addr, sizeof(addr));
	printf("\nServer is Online");

	/* listen for connections from the socket */
	/* listen(fd, backlog) */
	listen(server_fd, 5);

	/* accept a connection, we get a file descriptor */
	/* new_socket = accept(int fd, addr, addrlen) */
	sock = accept(server_fd, NULL, NULL);

	int i=0;
	int k=0; // iterator for res[MAX]
	srand(time(NULL));

	while(1) 
	{ 
		int recvsize = 5;

		// memset(starting_addr , value , length)
		memset(frame, 0, MAX); // re-initialise frame buffer with 0

		// recv(socket, buffer, length, flag)
		recv(sock, frame, recvsize, 0); 

		if(strlen(frame) < recvsize) 
		{
			recvsize = strlen(frame);
		}
		// at end exit frame is recieved from client
		if(strcmp(frame, "Exit") == 0) 
		{ 
			break; 
		} 
		
		int err_idx = rand()%8; // probability of byte to get corrupted = 50%
		int j;

		if(err_idx < recvsize)
		{
			for(j=0; j<err_idx ; j++)
			{
				res[k++] = frame[j];
			}
			frame[err_idx]='x';
			printf("\n\nPacket received = %s", frame);
			printf("\nError at byte   = %d", err_idx+1);
			printf("\nReceiving window: ");
			printf("\n start seqno = %d", i);
			printf("\n end seqno   = %d", i+err_idx);

			i = i + err_idx;
			ack = i; 
		}

		else
		{ 
			for(j=0; j<recvsize ; j++)
			{
				res[k++] = frame[j];
			}
			printf("\n\nPacket received = %s", frame);
			printf("\nReceiving window: ");
			printf("\n start seqno = %d", i);
			printf("\n end seqno   = %d", i+recvsize-1);
			
			i = i + recvsize;
			ack = i;  
		}

		printf("\nSending ack = %d", ack);
		send(sock, &ack, sizeof(ack), 0) ;  
	}

	res[k] = '\0';
	printf("\n\nFinal string recieved at Destination = ");
	fputs(res, stdout);
	printf("\n\n");

	close(sock);
	close(server_fd);
}
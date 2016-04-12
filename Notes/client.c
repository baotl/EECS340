/* 
 * tcpclient.c - A simple TCP client
 * usage: tcpclient <host> <port>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

#define BUFSIZE 1024

/* 
 * error - wrapper for perror
 */
void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char *hostname;
    char buf[BUFSIZE];

    /* check command line arguments */
    if (argc != 3) {
       fprintf(stderr,"usage: %s <hostname> <port>\n", argv[0]);
       exit(0);
    }
    hostname = argv[1];
    portno = atoi(argv[2]);

    /* socket: create the socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    /* gethostbyname: get the server's DNS entry */
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host as %s\n", hostname);
        exit(0);
    }

    /* build the server's Internet address */
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = *( unsigned long *)server->h_addr_list[0];
    serveraddr.sin_port = htons(portno);

    /* connect: create a connection with the server */
    if (connect(sockfd, (struct sockaddr*) &serveraddr, sizeof(serveraddr)) < 0) 
      error("ERROR connecting");

    fd_set read_fds;
    int fdmax = 0;
    fdmax = (fdmax>sockfd)? fdmax: sockfd;
    
    for(;;) {
    	FD_SET(0, &read_fds);
    	FD_SET(sockfd, &read_fds);
	
	if (select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            exit(1);
        }
	
	if(FD_ISSET(0, &read_fds)) 
	{ 
    		memset(buf, 0, BUFSIZE);
    		fgets(buf, BUFSIZE, stdin);

    		/* send the message line to the server */
    		n = write(sockfd, buf, strlen(buf));
    		if (n < 0) { 
    		  error("ERROR writing to socket");
		  break;
		}
	}
	if(FD_ISSET(sockfd, &read_fds))
	{
    		memset(buf, 0, BUFSIZE);
    		n = read(sockfd, buf, BUFSIZE);
    		if (n <0) { 
    		  error("ERROR reading from socket");
		  break;
		}
		if(n==0) {
    		  error("server connection closed.");
		}

    		printf(">> %s", buf);
	}	
    }   
    
    close(sockfd);
    return 0;
}


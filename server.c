/*===========================================================================*
   Exercice : UDP socket Server
   Auteur   : STIRNEMANN Jonas
   Date création : 11/10/2020
  =============================================================================
   Descriptif: Receive data from a client through a socket 
=*===========================================================================*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT 42069

int main()
{
	char receiveBuffer[50] = {0};

	//############## CREATE SOCKET OBJECT ##############
	//AF_INET = Add Familly > IPV4 
	//SOCK_DGRAM = Protocol > User Datagram Protocol (UDP) 
	//0 lets the programm chose the right things to create UDP packet  
	int sock1 = socket(AF_INET, SOCK_DGRAM, 0); 

	//error handling
	if(sock1 == -1)
	{
		perror("Failed to create socket!");
		exit(EXIT_FAILURE);
	}
	//############## END CREATE SOCKET OBJECT ##############

	//############## CREATE ADRESS OBJECT ##############
	struct sockaddr_in servAdd = {0}; //0 loads the struct and zeroes it 
	//AF_INET = Add Familly > IPV4 
	servAdd.sin_family = AF_INET;
	//htons converts the order of the bits to make it acceptable by protocols
	servAdd.sin_port = htons(PORT); 
	//INADDR_ANY -> equivalent to 0.0.0.0 (local test)
	servAdd.sin_addr.s_addr = INADDR_ANY;
	//############## END CREATE ADRESS OBJECT ##############

	//############## BINDING TO A PORT  ##############
	//socket object
	//server address (casted into the right type)
	//size of address
	int returnCode = bind( sock1, (const struct sockaddr *)&servAdd, sizeof(servAdd) );

	//error handling
	if(returnCode == -1)
	{
		perror("Failed to bind!");
		//close the socket
		close(sock1);
		exit(EXIT_FAILURE);
	}
	//############## END BINDING TO A PORT  ##############
	
	//############## RECEIVE AND PROCESS A MESSAGE  ##############	
	socklen_t len = 0;
	//socket object
	//Receive Buffer for the message
	//size of Buffer
	//MSG_WAITALL -> wait 'till the whole message is received
	//client address
	//adress lenght
	int n = recvfrom(sock1, (char *)receiveBuffer, 50, MSG_WAITALL, 0, &len );
	printf("Message : %s\nPort    : %d\n", receiveBuffer, PORT);
	//############## END RECEIVE AND PROCESS A MESSAGE  ##############	

	//close the socket
	close(sock1);
	return 0;
}
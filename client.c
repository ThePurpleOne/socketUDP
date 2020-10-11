/*===========================================================================*
   Exercice : UDP socket Client
   Auteur   : STIRNEMANN Jonas
   Date création : 11/10/2020
  =============================================================================
   Descriptif: Send data through socket 
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
	char *message = "Hey, I'm a message from the client!";


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

	//############## SENDING MESSAGE TO A PORT  ##############
	//socket object
	//message (casted in const char to avoid modifs)
	//0 -> not setting any flags
	//destination server address (casted into the right type)
	//size of address
	int len = ( sendto(sock1, (const char *)message, strlen(message), 0, (const struct sockaddr *)&servAdd, sizeof(servAdd)) );

	//error handling
	if(len == -1)
	{
		perror("Failed to send!");
	}
	//############## END SENDING MESSAGE TO A PORT  ##############
	
	//close the socket
	close(sock1);

	return 0;
}
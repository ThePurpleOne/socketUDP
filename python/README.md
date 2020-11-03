# SOCKETS

## BASIC SOCKETS
      
### Client
- Create socket
- Connect
- Send message

### Server
- Create a socket 
- Bind the socket to an IP (everything that'll be sent on this IP will hit this)
- Wait, accept connection and get client infos
- Handle the connection in a thread
	- get a fixed size header containing the real msg size
	- get the message

## COMPILE
```bash
gcc server.c -o server
gcc client.c -o client
```

## RUN 
*different terminals (server first)*
```bash
./server
./client
```



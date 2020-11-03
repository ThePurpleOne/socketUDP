import socket
import threading

PORT = 5050
SERVER = "192.168.1.110"
ADDR = (SERVER, PORT) 
HEADER_SIZE = 64
DISCONNECT_MESSAGE = "&DISCONNECT"
ENCODING = 'utf-8'

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #ipv4 TCP
server.bind(ADDR)

def handle_connection(conn, addr):
	print(f"{addr} CONNECTED")

	connected = True
	while connected:
		messageLenght =  conn.recv(HEADER_SIZE).decode(ENCODING) 
		if messageLenght:
			messageLenght = int(messageLenght)
			message = conn.recv(messageLenght).decode(ENCODING) 
			if message == DISCONNECT_MESSAGE:
				connected = False
			print(f"Message from {addr} : {message} ")

	conn.close()

def wait_for_connection():
	server.listen()
	while True:
		conn, addr = server.accept() #wait
		thread = threading.Thread(target=handle_connection, args=(conn, addr))
		thread.start()


print(f"STARTING SERVER...\nLISTENNING ON IP : {ADDR}")

wait_for_connection()

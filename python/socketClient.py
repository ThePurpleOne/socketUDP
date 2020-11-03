import socket

PORT = 5050
SERVER = "192.168.1.110"
ADDR = (SERVER, PORT) 
HEADER_SIZE = 64
DISCONNECT_MESSAGE = "&DISCONNECT"
ENCODING = 'utf-8'

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #ipv4 TCP
client.connect(ADDR)

	def send(msg):
		message = msg.encode(ENCODING)
		msg_lenght = len(message) # get message len for the header
		msg_lenght = str(msg_lenght).encode(ENCODING) #format to send
		msg_lenght += b' ' * (HEADER_SIZE - len(msg_lenght)) #add binary ' ' padding to fill header
		print(msg_lenght)
		client.send(msg_lenght)
		client.send(message)

	send("Hey Cunt!")
	input()
	send("Hey Twat!")
	input()
	send("Hey Dumbass!")
	send(DISCONNECT_MESSAGE)



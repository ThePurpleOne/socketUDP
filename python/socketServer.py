import socket


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #ipv4 TCP
s.bind(("127.0.0.1", 6942 ))


while True:
	s.listen(5)
	clientSocket, address = s.accept()
	print(f"You've successfully connected to {address} !")
	message = clientSocket.recv(1024)
	print(message.decode("utf-8"))

clientSocket.close()
s.close()

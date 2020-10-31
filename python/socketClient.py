import socket


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #ipv4 TCP

try:
	s.connect(("127.0.0.1", 6942))
	print("Client connecté !")
	s.sendall(bytes("Message envoyé depuis le client !", "utf-8"))
	print("message envoyé")

except:
	pass

finally:
	s.close()

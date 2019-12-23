"""
import socket

print('Now working...')

while True:
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect(("localhost", 2333))
	str_in = input('Message: ')
	s.sendall(str_in.encode())
	s.close()
"""


class Client(object):
	def __init__(self, num):
		self.num = num

	def send(self, l, clients):
		if len(l) == 1:
			print('Node {} received!'.format(self.num))
		else:
			l.remove(l[0])
			clients[l[0]].send(l, clients)

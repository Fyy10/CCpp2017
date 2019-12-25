"""
import socket
from numpy import *
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("localhost", 2333))
s.listen(1)


def detect(str_in):
	print(str_in.decode())


print('Now working...')

while True:
	conn, address = s.accept()
	data = conn.recv(1024)
	conn.close()
	detect(data)
"""


from test import *
from client import *
import time


def run_server():
	n = int(input('Please input the number of nodes (n > 1): '))
	if n < 2:
		raise ValueError('The number of nodes should be greater than 1')
	g = Graph(n)
	clients = [Client(i) for i in range(n)]
	while True:
		g.display()
		start = time.time()
		for i in range(1, n):
			cost, order = dijkstra(0, i, g)
			print('Node: {}, Cost: {}, Order: {}'.format(i, cost, order))
			# sending message
			clients[0].send(order, clients)
		end = time.time()
		print('Total time: {}s'.format(end - start))
		# For convenience, use system pause to represent every 10s passed
		os.system('pause')
		# Generate a new graph
		g.generate()


if __name__ == '__main__':
	run_server()

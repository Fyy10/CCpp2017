from numpy import *
import random as rnd
import os
from client import *


class Graph(object):
    def __init__(self, n):
        self.nodes = n
        self.dis = self.generate(n)

    def generate(self, n=None):
        if n is None:
            n = self.nodes
        # The index of nodes starts from 0
        self.dis = tile(inf, (n, n))
        for i in range(n):
            self.dis[i, i] = 0
            self.dis[0, i] = self.dis[i, 0] = 1
        self.dis[0, 0] = 0
        s = set()
        while len(s) < n:
            for i in range(n):
                for j in range(n):
                    if i == j or judge_rand():
                        continue
                    self.dis[i, j] = self.dis[j, i] = rand()
                    s.add(i)
                    s.add(j)
        return self.dis

    def set_n(self, n):
        self.nodes = n
        self.generate(n)

    def display(self):
        print('Graph:')
        print(self.dis)


# range of edges
def rand():
    edge = rnd.randint(1, 100)
    return edge


# randomly decide
def judge_rand():
    return random.randint(0, 1)


def dijkstra(start, end, graph):
    dis = graph.dis
    n = graph.nodes
    # judge if a node is visited
    vis = zeros(n, dtype=bool)
    vis[start] = True
    # cost from start to any node
    cost = tile(inf, n)
    cost[start] = 0
    # the order of sending message
    order = [[] for i in range(n)]
    for i in range(n):
        cost[i] = dis[start, i]
    idx = find_min(cost, vis)
    prev = [i for i in range(n)]
    while not alltrue(vis):
        for i in range(n):
            if i == idx or vis[i]:
                continue
            if cost[idx] + dis[idx, i] < cost[i]:
                cost[i] = cost[idx] + dis[idx, i]
                prev[i] = idx
        idx = find_min(cost, vis)
        vis[idx] = True
        last_state = prev[idx]
        while not vis[last_state]:
            last_state = prev[last_state]
        for node in order[last_state]:
            order[idx].append(node)
        order[idx].append(idx)
    for i in range(n):
        order[i].insert(0, start)
    return cost[end], order[end]


def find_min(l, vis):
    minx = inf
    idx = 0
    for i in range(len(l)):
        if l[i] < minx and not vis[i]:
            minx = l[i]
            idx = i
    return idx


def main():
    n = int(input('Please input the number of nodes (n > 1): '))
    if n < 2:
        raise ValueError('The number of nodes should be greater than 1')
    g = Graph(n)
    g.display()
    # Assume node 0 to be the head
    for i in range(1, n):
        cost, order = dijkstra(0, i, g)
        print('node: {}, cost: {}, order: {}'.format(i, cost, order))


def run_network():
    n = int(input('Please input the number of nodes (n > 1): '))
    if n < 2:
        raise ValueError('The number of nodes should be greater than 1')
    g = Graph(n)
    while True:
        g.display()
        for i in range(1, n):
            cost, order = dijkstra(0, i, g)
            print('node: {}, cost: {}, order: {}'.format(i, cost, order))
        # For convenience, use system pause to represent every 10s passed
        os.system('pause')
        # Generate a new graph
        g.generate()


if __name__ == '__main__':
    # main()
    run_network()

import numpy as np
import random


size = 20
dfs = np.zeros((size, size), dtype=bool)
maze = np.ones((2*size+1, 2*size+1), dtype=bool)
# 1: up, 2: right, 3: down, 4: left
operations = {1: (-1, 0), 2: (0, 1), 3: (1, 0), 4: (0, -1)}
directions = [1, 2, 3, 4]

for i in range(2*size+1):
    if i % 2 == 0:
        for j in range(2*size+1):
            maze[i, j] = 0

for i in range(2*size+1):
    if i % 2 == 0:
        for j in range(2*size+1):
            maze[j, i] = 0


def generate(start):
    x, y = start
    dfs[x, y] = 1
    random.shuffle(directions)
    for direction in directions:
        px, py = (x + dx for x, dx in zip(start, operations[direction]))
        if px < 0 or px >= size or py < 0 or py >= size:
            pass
        else:
            if dfs[px, py] == 0:
                mx = 2*x + 1
                my = 2*y + 1
                if direction == 1:
                    maze[mx-1, my] = 1
                elif direction == 2:
                    maze[mx, my+1] = 1
                elif direction == 3:
                    maze[mx+1, my] = 1
                elif direction == 4:
                    maze[mx, my-1] = 1
                generate((px, py))


generate((0, 0))
maze = maze.astype(int)
maze[1, 0] = 1
maze[2*size-1, 2*size] = 1

f = open('data.in', 'w')
for i in range(2*size+1):
    for j in range(2*size+1):
        f.write(str(maze[i, j]))
    f.write('\n')

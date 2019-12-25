import os
import time


def run_maze():
    n = int(input('Number of tests: '))
    print('Now Testing...')
    start = time.time()
    for i in range(n):
        os.system('python maze_data.py')
        os.system('maze.exe < data.in > data.out')
    end = time.time()
    print('Finished Testing!')
    print('Total time: {}s'.format(end - start))


if __name__ == '__main__':
    run_maze()

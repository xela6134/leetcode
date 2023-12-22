# multiprocessing: running tasks in parallel on different cpu cores, bypasses GIL used for threading
#
# multiprocessing: better for cpu bound tasks (heavy cpu usage)
# multithreading: better for io bound tasks (waiting around)

from multiprocessing import Process, cpu_count
import time

def counter(num):
    count = 0
    while count < num:
        count += 1

def main():
    a = Process(counter, args=(1000000000))

if __name__ == '__main__':
    main()
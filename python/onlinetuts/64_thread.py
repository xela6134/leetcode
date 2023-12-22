# threads: separate order of instructions
# 
# Each thread takes turns running to achieve concurrency, 
# GIL (Global Interpretor Lock) allows only one thread to hold the
# control of the Python interpreter at any one time
# 
# cpu bound: program/task spends most of its time waiting for internal events (CPU internal)
# -> use multiprocessing
# 
# io bound: program/task spends most of its time waiting for external events (user inputted)
# -> user multithreading

import threading
import time

def eat_breakfast():
    time.sleep(2)
    print("You ate breakfast")
    
def drink_coffee():
    time.sleep(3)
    print("You drank coffee")
    
def do_work():
    time.sleep(4)
    print("You finished studying")

x = threading.Thread(target=eat_breakfast, args=())
y = threading.Thread(target=drink_coffee(), args=())
z = threading.Thread(target=do_work, args=())

x.start()
y.start()
z.start()

x.join()
y.join()
z.join()    # all joins together

print(threading.active_count())
print(threading.enumerate())

'''
# the functions below run separately, another is called only after one has been finished completely
eat_breakfast()
drink_coffee()
do_work()

print(threading.active_count())
print(threading.enumerate())
'''
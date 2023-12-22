# daemon thread: a thread that runs backgroun operations. not important for the main program
#               ex) garbage collection, action listener, signal dispatches

import threading
import time

def timer():
    print()
    count = 0
    while True:
        time.sleep(1)
        count += 1
        print("logged in for: " + str(count) + " seconds")

x = threading.Thread(target=timer)
x.setDaemon(True)
x.start()
print(x.isDaemon())

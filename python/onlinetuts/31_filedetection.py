import os

path = "/mnt/c/Users/Administrator/Desktop/coding/python/onlinetuts/resources/moo.txt"

if os.path.exists(path):
    print('exists!')
    if os.path.isfile(path):
        print('this is a file')
    elif os.path.isdir(path):
        print('this is a directory')
else:
    print('nonexistent!')
    
print(os.getcwd())  # current directory
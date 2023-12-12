import os

path = "/mnt/c/Users/Administrator/Desktop/coding/python/onlinetuts/resources/moo.txt"

with(open(path, 'r')) as file:
    print(file.read())

print(file.closed)

path1 = "fakepath"

try:
    with(open(path1), 'r') as file:
        print(file.read())
except FileNotFoundError as e:
    print(e)
    print("nonexistent file!")
else:
    print("file exists!")
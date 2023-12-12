import os

source = 'resources/moo.txt'
destination = 'resources/moo2.txt'

try:
    if os.path.exists(destination):
        print("A file already exists")
    else:
        os.replace(source, destination)
        print(source + " was moved")
except FileNotFoundError:
    print(source + " was not found")

import os

path = 'resources/moo1.txt'

try:
    os.remove('resources/moo1.txt')
    # os.rmdir(resources) -> removes directory
except FileNotFoundError:
    print("File not found")
except PermissionError:
    print("You should not be deleting that")
else:
    print(path + " was deleted")
# zip(*iterables): aggregate elements from two or more iterables (list, tuples, sets, etc)
#                  creates a zip object with paired elements stored in tuples for each element

usernames = ["mooman", "meowman", "woofman"]
passwords = ("spongebob", "squarepants", "trianglepants")

users = dict(zip(usernames, passwords))
print(type(users))

for key, value in users.items():
    print(key + ": " + value)

heights = [181, 192, 170]
newdata = zip(usernames, passwords, heights)
for i in newdata:
    print(i)
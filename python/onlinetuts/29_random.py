import random

for i in range (1, 5):    
    x = random.randint(1, 6)
    print(x)
    
y = random.random()
print(y)

myList = ['rock', 'paper', 'scissors']
z = random.choice(myList)

cards = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A']
random.shuffle(cards)
print(cards)
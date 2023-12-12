# lists

food = ["pizza", "sushi", "jokbal", "kimchi", "bossam", "jeon"]

food.append("ice cream")    # appends to end of list
food.remove("hotdog")       # removes that specific item
food.pop()                  # remove last item
food.insert(0, "cake")      # straightforward
food.sort()                 # sorts list, can be customised
# food.clear()              # clears list

for x in food:
    print(x)
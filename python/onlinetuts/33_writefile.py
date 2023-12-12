# write file

text = "some random text"
path = "/mnt/c/Users/Administrator/Desktop/coding/python/onlinetuts/resources/random.txt"

with(open('resources/random.txt', 'w')) as file:
    file.write(text)

# append: 'a'
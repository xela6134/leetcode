# reduce(): apply a function to an iterable and reduce it to a single cumulative value
#           performs function on first two elements and repeats process until 1 value remains
# reduce(function, iterable)

import functools

letters = ['H', 'E', 'L', 'L', 'O']
words = functools.reduce(lambda x, y: x + y, letters)
print(words)

# the whole process:
# 
# ['H', 'E', 'L', 'L', 'O']
# ['HE', 'L', 'L', 'O']
# ['HEL', 'L', 'O']
# ['HELL', 'O']
# ['HELLO']

numbers = [5, 4, 3, 2, 1]
factorial = functools.reduce(lambda x, y: x * y, numbers)
print(factorial)
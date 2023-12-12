# functions

def hello(name: str, age: int):
    print('hello ' + name + '!')
    print('you are ' + str(age) + ' years old!')
    print('have a nice day!')
    print('')

hello('Harry', 21)
hello('Ron', 20)
hello('Hermione', 19)

# return functions
def multiply(int1: int, int2: int):
    return int1 * int2

print(multiply(6, 8))
print(multiply(2, 3))

# keyword arguments
def whatsup(first: str, middle: str, last: str):
    print("Whatup " + first + " " + middle + " " + last)

whatsup(last="Potter", first="Harry", middle="James")
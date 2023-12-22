# higher order function: 1. accepts a function as an argument
#                        2. returns a function (funcions are treated as objects)

def loud(text: str):
    return text.upper()

def quiet(text: str):
    return text.lower()

def hello(func):
    text = func("HellO")
    print(text)
    
hello(loud)
hello(quiet)

def divisor(x):
    def dividend(y):
        return y / x
    
    return dividend

divide = divisor(2)
print(type(divide))
print(divide(10))

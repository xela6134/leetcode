def hello():
    print("Hello")
    
hi = hello  # this isn't calling the function itself, it's copying the address of the function
hello()
hi()

# exception detecting

try:
    numerator = int(input("Enter a number to divide: "))
    denominator = int(input("Enter a number to divide by: "))
    result = numerator / denominator
except ZeroDivisionError as e:
    print(e)
    print("YOU CANNOT DIVIDE BY ZERO!")
except ValueError as e:
    print(e)
    print("only numbers please")
except Exception as e:
    print(e)
    print("some weird exception")
else:
    # only executed if exception does not exist
    print(result)
finally:
    # whether or not exceptions are caught or not
    # this block of code always executes
    print('hello hello hello')
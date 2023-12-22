double = lambda x: x * 2
print(double(5))

multiply = lambda x, y: x * y
print(multiply(4, 3))

full_name = lambda first_name, last_name: first_name + " " + last_name
print(full_name("Harry", "Potter"))

age_check = lambda age: True if age >= 18 else False
print(age_check(21))
print(age_check(15))
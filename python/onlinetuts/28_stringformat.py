# str.format() = optional method that gives users more control when displaying output

animal = 'cow'
item = 'moon'

print('The {} jumped over the {}'.format(animal, item))
print(f'The {animal} jumped over the {item}')

pi = 3.14159265
print('The number of pi is {:.3f}'.format(pi))

number = 1234567890
print('The number is {:,}'.format(number))  # commas inserted
print('The number is {:b}'.format(number))  # binary
print('The number is {:o}'.format(number))  # octal
print('The number is {:X}'.format(number))  # hex
print('The number is {:E}'.format(number))  # scientific notation

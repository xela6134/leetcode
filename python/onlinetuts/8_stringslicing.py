# slicing: [start:stop:step]

name = "Lorem Ipsum"
first_name = name[0:5]
print(first_name)

first_name_sub = name[:5]   # python assumes this is the start of the string
print(first_name_sub)

last_name = name[6:11]
print(last_name)

reversed_name = name[::-1]
print(reversed_name)

dummy = "ababababababababa"
funky = dummy[::2]  # python assumes its the whole string when you leave these two fields blank
print(funky)

# slice() function

website = "http://www.google.com"
sliced = slice(7, -4)
print(website[sliced])
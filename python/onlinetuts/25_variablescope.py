# scope: the region that a variabe is recognised
#       a variable is only availbale from inside the region it is created
#       a global and locally scoped versions of a vriable can be created

name = "Harry"  # global scope
def display_name():
    name = "Ron"
    print(name)
    
display_name()
print(name)

# L = Local
# E = Enclosing
# G = Global
# B = Built-in
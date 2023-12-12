# OOP in Python

class Dog:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def sound(self):
        print("bark")
    
    def introduce(self):
        print("My name is " + self.name)
        
    def get_name(self):
        return self.name
    
    def get_age(self):
        return self.age

    def set_age(self, age):
        self.age = age
        
class Cat:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def sound(self):
        print("meow")
        
    def introduce(self):
        print("My name is " + self.name)
        
    def get_name(self):
        return self.name
    
    def get_age(self):
        return self.age

d = Dog("Naafiri", 2)
d1 = Dog("Nasus", 3)
c = Cat("Mandu", 4)

d.sound()
c.sound()
d.introduce()
d1.introduce()

print(d.name)
print(d1.name)
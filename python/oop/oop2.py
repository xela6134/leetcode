# Inheritance

class Pet:
    legs = 4
    
    def __init__(self, name, age):
        self.name = name
        self.age = age
        
    def introduce(self):
        print("I am " + self.name + " and I am " + str(self.age) + " years old")
        
    def sound(self):
        print("WhAt dO i hAvE tO SaY?.?")
        
# inheritance
class Cat(Pet):
    def __init__(self, name, age, colour):
        super().__init__(name, age)
        self.colour = colour
    
    def sound(self):
        print("Meow")
        
    def brag(self):
        print("My colour is " + self.colour)

class Dog(Pet):
    def __init__(self, name, age, strength):
        super().__init__(name, age)
        self.strength = strength
    
    def sound(self):
        print("Bark")
    
    def brag(self):
        print("My power is " + str(self.strength))

class Fish(Pet):
    legs = 2
    pass
        
d = Dog("Nasus", 1000, 100)
c = Cat("Rengar", 25, "black")
f = Fish("Fizz", 15)
d.introduce()
c.introduce()
f.introduce()
d.sound()
c.sound()
f.sound()
d.brag()
c.brag()

print(d.legs)
print(c.legs)
print(f.legs)
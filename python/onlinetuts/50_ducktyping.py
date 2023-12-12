# Duck typing: concept where the class of an object is less important than the methods/attributes
#              class type is not checked if minimum methods/attributes are present
#              "If it walks like a duck, and it qacks like a duck, then it must be a duck"

class Duck:
    def walk(self):
        print("This duck is walking")
    
    def talk(self):
        print("This duck is talking")

class Chicken:
    def walk(self):
        print("This chicken is walking")
    
    def talk(self):
        print("This chicken is talking")

class Human:
    def catch(self, animal):
        animal.walk()
        animal.talk()
        print("You caught the critter")
        
        if type(animal) == Duck:
            print("You caught a duck, to be precise!")
        elif type(animal) == Chicken:
            print("You caught a chicken, to be precise!")

duck = Duck()
chicken = Chicken()
human = Human()

human.catch(duck)
human.catch(chicken)
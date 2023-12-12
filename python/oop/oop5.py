# Multiple Inheritance: when a child class is derived from more than one parent class

class Prey:
    def flee(self):
        print("RUNNNNNNNNNNNNN")

class Predator:
    def hunt(self):
        print("ON THE HUNT")

class Rabbit(Prey):
    pass

class Hawk(Predator):
    pass

class Fish(Prey, Predator):
    pass

rabbit = Rabbit()
hawk = Hawk()
fish = Fish()

rabbit.flee()

hawk.hunt()

fish.hunt()
fish.flee()
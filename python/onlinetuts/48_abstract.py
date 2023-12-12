# abstract methods and classes
# abc: abstract based class

from abc import ABC, abstractmethod

class Vehicle(ABC):
    @abstractmethod
    def go(self):
        pass
    
class Car(Vehicle):
    def go(self):
        print("Vroong goes the car")
    
class Motorcycle(Vehicle):
    def go(self):
        print("Vroong goes the motorcycle")

vehicle = Vehicle()
car = Car()
motorcycle = Motorcycle()

vehicle.go()
car.go()
motorcycle.go()

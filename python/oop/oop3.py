# Other cool stuff

class Person:
    number_of_people = 0
    
    def __init__(self, name):
        self.name = name
        Person.add_person()
        
    @classmethod    # static
    def get_people(cls):
        return cls.number_of_people
    
    @classmethod
    def add_person(cls):
        cls.number_of_people += 1

print(Person.number_of_people)
print(Person.get_people())
p1 = Person("Sica")
print(Person.get_people())
p2 = Person("Woojun")
print(Person.get_people())

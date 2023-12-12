# Static methods

class Math:
    @staticmethod
    def add5(x):
        return x + 5
    
    @staticmethod
    def add1(x):
        return x + 1

print(Math.add1(5))
print(Math.add5(1))
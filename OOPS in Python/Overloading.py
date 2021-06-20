"""
    Polymorphism :
        1. DuckTyping
        2. Operator Overloading
        3. Method Overloading (No Method Overloading in Python )
            - Can achieve using Default args or using variable length args
            def over(self,*args) or def over(self,a=None,b=None,c=None)
        4. Method Overriding
            - Cannot have two function with same name in same class
            - But can possible with inheritance. By default it will check in current class, later in inherited class.
"""


a = 5
b = 10

print(a + b)            # Internally it is converted as int.__add__()
print(int.__add__(a, b))
print(int.__sub__(a, b))
print(int.__mul__(a,b))

# Operator Overloading

class Student:
    def __init__(self,a,b):
        self.a = a
        self.b = b

    def __add__(self, other):           # Overloading the default __add__ function and returning add instance
        a = self.a + other.a
        b = self.b + other.b
        return Student(a, b)

    def __str__(self):
        print("in __str__: ",self.a)   # Now it prints the value
        return "{} {}".format(self.a, self.b)       # Converting tuple to space separated value

s1 = Student(10, 20)
s2 = Student(50, 50)

s3 = s1 + s2            # Results in unsupported operand type! Overload the add method
print(s3.a)
print(s3.b)

q = 10
print(q)            # q gets printed but object address is printed for the next case
print(s3)           # Internally q --> q.__str__()

print(q.__str__())
print(s3.__str__())  # After overloading the __str__() method


# DuckTyping

class Employee:
    def details(self):
        print("Its APK in Employee Class")

class Hosteller:
    def details(self):
        print("Its APk in Hosteller Class")

class Check:
    def show(self,d):
        d.details()
    def details(self,a):
        print("In check")

d = Employee()          # If the class has the method details it will execute it
c = Check()
c.show(d)
d = Hosteller()         # In this case also we have details method in the the Hosteller class
c.show(d)

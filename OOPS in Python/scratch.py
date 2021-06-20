'''
    Types of Variables :
        1.Instance Variables
        2.Class Variables (Static Variables)

    Types of Methods :
        1.Instance Methods
        2.Class Methods
        3.Static Methods

    ~ To represent instance use self as pointer
    ~ To represent class use cls as pointer
    ~ Use of @classmethod and @staticmethod is must before declaring this kinds of methods

'''



class Employee:

    age = 20    # Class Variable    (Gets reflected to all the objects)

    def __init__(self):         # Self acts as pointer to denote the object
        self.name = "APK"
        self.sal = 2000     # Instance Variables (Reflected only for specified objects)

    def update(self):        # Mutator Methods
        self.sal=100000

    def get_name(self):     # Accessor Methods
        return self.name    # Instance Method

    @classmethod        # To avoid errors
    def get_age(cls):
        return cls.age      # Class Method

    @staticmethod
    def dummy():        # Static Method
        print("Now you are in static method which does not deal with any class or instance variables")


e1 = Employee()         # Instance for Employee where Employee is passed with e1
e2 = Employee()

e2.name = "Prem"        # Changing value of the Employee Instance (Changes only for specified object)
e2.update()             # Calling method for Instance e2

Employee.age = 22       # (Changes gets reflected in all the objects)

print(e1.name, e1.sal, e1.age)
print(e2.name, e2.sal, e2.age)
print(e1.get_name())
print(Employee.get_age())
print(Employee.dummy())


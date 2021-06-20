
'''
    Inheritance :
        1. Single Level Inheritance
        2. Multi Level Inheritance
        3. Multiple Inheritance
'''

class Psg:                                  # Psg -->  Student  Single Inheritance

    def __init__(self):
        print("Constructor for Psg")

    def display(self):
        print("You're now in PSG class")

    def symposium(self):
        print("We have two culturals in PSG")


class Student(Psg):                     # Psg --> Student --> Marks     Multi Level Inheritance

    def __init__(self):
        #super().__init__()
        print("Constructor for Student")

    def display(self):
        print("You're in Student class")
    def rollno(self):
        print("My roll no is 715517104044")

class Marks(Student):

    def __init__(self):
        #super().__init__()
        print("Constructor for Marks")

    def Marks(self):
        print("You have very good marks")

class faculty:
    def __init__(self):
        print("Constructor for Faculty")

    def staffs(self):
        print("We have plenty of staffs")

class Placement(Psg,faculty):           # No relation between two classes but I need both of them in Placement class
                                          # Multiple Inheritance
    def __init__(self):
        #super().__init__()
        print("Constructor for Placement")

    def plt(self):
        print("100% placement")

#c = Psg()               # Prints its constructor
#s = Student()
#s.display()
#m = Marks()
#f = faculty()
p = Placement()

#c.display()             # Prints all constructor with display
p.plt()                 # Prints only its own constructor without super()
#p.plt()                 # Now it prints with constructor of Psg and its own constructor with usage of super()

'''
    Constructor in Inheritance :
        1. First checks for its own constructor
        2. If it has its own constructor , it will execute that
        3. If it does not have constructor , then it will prints base class constructor
        4. If constructor is present in both the classes, it will print only its own constructor.
        5. If constructor is present in both the classes,to call base class constructor super().__init__().
        5. In cases of multiple inheritance , Constructor gets executed from left to right!
        6. THe above order is called Method Resolution Order (MRO)
        7. Super() keyword is used to represent the super class or parent class

'''



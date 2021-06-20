class first():

    def __init__(self):
        self.__a = 100

    def getters(self):
        print("val of a",self.__a)

    def setters(self,val):
        self.__a = val

f = first()
f.getters()
print("Now changed outside the class")
f.__a = -100
f.getters()
print("Now changing inside the class")
f.setters(-100)
f.getters()

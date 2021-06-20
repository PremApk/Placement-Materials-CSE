from abc import ABC,abstractmethod

class first(ABC):
    @abstractmethod
    def dummy():
        pass

class real(first):

    def dummy(self):
        print("In real dummy")

#a = first() # This will throw error beacuse we can't instantiate abstract class
r = real()
r.dummy()

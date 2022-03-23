# Deque implementaion in python


class Deque:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def addRear(self, item):
        self.items.append(item)

    def addFront(self, item):
        self.items.insert(0, item)

    def removeFront(self):
        return self.items.pop(0)

    def removeRear(self):
        return self.items.pop()

    def size(self):
        return len(self.items)


d = Deque()
print(d.isEmpty())
print(d.items)

d.addRear(8)
print(d.items)

d.addRear(5)
print(d.items)

d.addFront(7)
print(d.items)

d.addFront(10)
print(d.items)

print(d.size())
print(d.isEmpty())
d.addRear(11)
print(d.items)

print(d.removeRear())
print(d.items)

print(d.removeFront())
print(d.items)

d.addFront(55)
print(d.items)

d.addRear(45)
print(d.items)

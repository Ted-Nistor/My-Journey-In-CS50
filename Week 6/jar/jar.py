class Jar:
    def __init__(self, current, capacity=12):
        self.capacity = capacity
        self.current = current

    def __str__(self):
        s = ""
        for n in range(self.current):
            s += "🍪"
        return s

    def deposit(self, n):
        if n >= self.capacity:
            raise ValueError("You're trying to deposit more cookies than the jar's capacity")
        else:
            self.current += n
            return self.current

    def withdraw(self, n):
        if n >= self.current:
            raise ValueError('Not enough cookies in the jar')
        else:
            self.current -= n
            return self.current

    @property
    def capacity(self):
        return self._capacity

    @capacity.setter
    def capacity(self, value):
        if value < 1:
            raise ValueError("Capacity must be a positive integer")
        self._capacity = value

    @property
    def size(self):
        return self.current


def main():
    jar = Jar(4)
    print(jar)
    jar.deposit(5)
    print(jar)
    jar.deposit(7)
    jar.withdraw(9)
    print(jar)
    jar.withdraw(1)
    print(jar)

main()

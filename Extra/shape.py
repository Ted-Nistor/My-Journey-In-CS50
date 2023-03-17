class Rectangle:
    def __init__(self, length=0, width=0):
        self.length = length
        self.width = width

    def set_length(self, length):
        self.length = length

    def set_width(self, width):
        self.width = width

    def area(self):
        return self.length * self.width

    def perimeter(self):
        return 2 * (self.length + self.width)

def main():
    rectangle1 = Rectangle()
    rectangle1.set_length(4)
    rectangle1.set_width(5)
    print(f"Perimeter = {rectangle1.perimeter()}")
    print(f"Area = {rectangle1.area()}")

main()

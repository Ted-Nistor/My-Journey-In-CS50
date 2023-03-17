# my version

# def main():
#     height = int (input('Height:'))
#     while height < 0:
#         height = int (input('Height:'))

#     blocks(height)


# def blocks(n):
#     for i in range(n):
#         print('#')

# main()

# cs50 version
def main():
    height = get_height()
    bricks(height)


def get_height():
    while True:
        try:
            n = int(input('Height:'))
            if n > 0 and n < 10:
                return n
        except ValueError:
            print("Not an integer")


def bricks(n):
    for i in range(n):
        print("#")


main()
# TODO
def main():
    height = get_height()
    for row in range(height):
        print(' ' * (height - row - 1) + '#' * (row + 1), end='')
        print()
        

def get_height():
    while True:
        try:
            h = int(input('Height:'))
            if isinstance(h, int) and h > 0 and h < 9:
                return h
        except ValueError:
            print("Please input an integer between 1 and 8")


main()
def main():
    height = get_height()
    for row in range(height):
            print (' ' * (height - row -1) + '#' * (row + 1) + '  ' + '#' * (row + 1), end ='')
            print()

def get_height():
    while True:
        h = int(input('Height:'))
        if h > 0 and h < 9:
            return h
main()
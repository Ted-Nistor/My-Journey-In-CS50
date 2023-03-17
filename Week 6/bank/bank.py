def main():
    greeting = input("Greeting: ")
    if "hello" in greeting.lower():
        print('$0')
    elif greeting[0].lower() == 'h':
        print('$20')
    else:
        print('$100')


main()
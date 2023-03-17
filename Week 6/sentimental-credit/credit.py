# TODO
def main():
    while True:
        try:
            card = int(input("Card Number: "))
            if int(card) > 0:
                break
        except ValueError:
            print("Please enter a valid card number")
    if check_card(card) == 1:
        print("INVALID")
        return
    card_type(card)


def check_card(x):
    first_set = 0
    second_set = 0
    sum = 0
    temp_sum = x
    while temp_sum > 0:
        sum = 2 * int((temp_sum % 100) / 10)
        if sum > 9:
            sum = sum % 10 + int(sum / 10)
            first_set += sum
        else:
            first_set += sum
        temp_sum = int(temp_sum / 100)
    temp_sum = x
    sum = 0
    while temp_sum > 0:
        sum = int(temp_sum % 10)
        second_set += sum
        temp_sum = int(temp_sum / 100)
    if not int((first_set + second_set) % 10) == 0:
        return 1


def card_type(x):
    x = str(x)
    if (x[:2] == '34' or x[:2] == '37') and len(x) == 15:
        print("AMEX")
    elif (x[:2] in ['51', '52', '53', '54', '55']) and len(x) == 16:
        print("MASTERCARD")
    elif x[0] == '4' and (len(x) == 13 or len(x) == 16):
        print("VISA")
    else:
        print("INVALID")


main()

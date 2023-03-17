def get_change():
    while True:
        try:
            change_owed = float(input("Change owed: "))
            if change_owed < 0:
                continue
            return int(round(change_owed * 100))
        except ValueError:
            continue


def calculate_coins(change):
    coins = 0
    coins += change // 25
    change %= 25
    coins += change // 10
    change %= 10
    coins += change // 5
    change %= 5
    coins += change
    return coins


change = get_change()
num_coins = calculate_coins(change)
print(num_coins)

# // is the floor division operator which returns an integer
# while discarding the remainder.
# if you use int (x / y) you can get the same results, but // is more
# concise
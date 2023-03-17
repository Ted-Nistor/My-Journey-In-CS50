import random
def main():
        challenge_rating = get_challenge_rating()
        total_dice = get_total_dice()
        adept = get_skill_level()

        dice_roll = [roll_dice() for _ in range(total_dice)]
        neutral_rolls = [dice for dice in dice_roll if dice not in [1, 5, 6]]
        success_rolls = [dice for dice in dice_roll if (dice in [5, 6]) or (adept and dice in [4])]
        complication_rolls = [dice for dice in dice_roll if dice == 1]
        get_probability(total_dice, challenge_rating, adept)
        print_results(dice_roll, neutral_rolls, success_rolls, complication_rolls, adept)

        success_count, complication_count, edge_count = get_results(challenge_rating, success_rolls, complication_rolls, adept)

        reroll = reroll_neutral_dice(neutral_rolls, success_rolls, complication_rolls, adept)
        if reroll:
            success_count, complication_count, edge_count = get_results(challenge_rating, reroll, complication_rolls, adept)
            print(f"Results after Reroll: {reroll}")
        else:
            print(f"Final Results: {dice_roll}")
            return


def get_challenge_rating():
    while True:
        challenge_rating = int(input("What's the Challenge Rating? "))
        if 0 < challenge_rating <= 5:
            return challenge_rating
        else:
            print("Please input a CR between 1 and 5")

def get_total_dice():
    while True:
        total_dice = int(input("How many dice? "))
        if 0 < total_dice <= 10:
            return total_dice
        else:
            print("Please input a value between 1 and 10")

def get_skill_level():
    while True:
        answer = input("Are you an adept in the skill? ")
        if 'n' in answer[0].lower():
            return False
        elif 'y' in answer[0].lower():
            return True
        else:
            print("Please answer with 'Yes' or 'No' to proceed")

def roll_dice():
    return random.randint(1, 6)

def print_results(dice_roll, neutral_rolls, success_rolls, complication_rolls, adept):
    print(f"Results: {dice_roll}")
    print(f"Successes: {success_rolls}")
    if adept:
        neutral_rolls = [dice for dice in neutral_rolls if dice != 4]
    print(f"Neutrals: {neutral_rolls}")
    print(f"Complications: {complication_rolls}")

def get_results(challenge_rating, success_rolls, complication_rolls, adept):
    success_count = 0
    complication_count = len(complication_rolls)
    edge_count = 0
    for success in success_rolls:
        if success == 5:
            success_count += 1
        elif success == 6:
            success_count += 2
        elif adept == True and success in [4,5]:
            success_count += 1

    edge_count = success_count - challenge_rating
    print_challenge_result(success_count, challenge_rating, complication_count, adept)
    return success_count, complication_count, edge_count

def print_challenge_result(success_count, challenge_rating, complication_count, adept):
    if success_count < challenge_rating:
        print(f"You have {success_count} success(es) against CR {challenge_rating}.", end='')
        print(f" You need {challenge_rating - success_count} more successes to beat the challenge.")
    elif success_count == challenge_rating:
        if complication_count > 0:
            print(f"You have enough successes to beat the CR, but you generated {complication_count} complications.")
        else:
            print("You have beaten the challenge!")
    else:
        if complication_count <= 0:
            print(f"You have {success_count} successes against CR {challenge_rating}.", end='')
            print(f" You have {abs(success_count - challenge_rating)} Edge to spend.")
        else:
            print(f"You have {success_count} successes against CR {challenge_rating}, but you generated {complication_count} complication(s). ", end='')
            print(f"You may spend up to {abs(success_count - challenge_rating)} Edge to cancel any complication(s).")


def reroll_neutral_dice(neutral_rolls, success_rolls, complication_rolls, adept):
    if len(neutral_rolls) > 0 :
        while True:
            print("Would you like to reroll all neutrals?")
            answer = input('Answer: ')
            if 'y' in answer[0].lower():
                reroll = []
                reroll.extend(success_rolls)
                reroll.extend(complication_rolls)
                for roll in neutral_rolls:
                        new_roll = roll_dice()
                        reroll.append(new_roll)
                        if new_roll == 1:
                            complication_rolls.append(1)
                        elif new_roll in [5, 6] or (adept and new_roll in [4,5,6]):
                            success_rolls.append(new_roll)
                if reroll:
                    print(f"Successes: {success_rolls}")
                    print(f"Complications: {complication_rolls}")
                    return reroll
            elif 'n' in answer[0].lower():
                    return

def get_probability(num_dice, challenge_rating, is_adept):
    num_successes = 0
    num_trials = 1000000
    for i in range(num_trials):
        successes = 0
        for j in range(num_dice):
            roll = random.randint(1, 6)
            if roll == 6:
                successes += 2
            elif roll == 5:
                successes += 1
            elif roll == 4 and is_adept:
                successes += 1
        if successes >= challenge_rating:
            num_successes += 1
    probability = num_successes / num_trials * 100
    print("Probability of success: {:.2f}%".format(probability))


main()
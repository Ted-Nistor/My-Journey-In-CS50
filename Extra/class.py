import random

class Enemy:
    def __init__(self, name, attack, defense, damage):
        self.name = name
        self.attack = attack
        self.defense = defense
        self.damage = damage

    def random_dice(self):
        return random.randint(1,20)
    def attack_roll(self):
        return self.random_dice() + self.attack
    def defence_roll(self):
        return self.random_dice() + self.defense
    def damage_roll(self):
        return self.random_dice() + self.damage

class Orc(Enemy):
    pass


def main():
    orc1 = Orc('Orc', 4, -2 , 6)
    print(f"{orc1.name} rolled a {orc1.attack_roll()} on his attack roll and it deals {orc1.damage_roll()} damage")
main()
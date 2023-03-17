class Pet:
    def __init__(self, name, hunger, thirst, happiness, energy):
        self.name = name
        self.hunger = hunger
        self.thirst = thirst
        self.happiness = happiness
        self.energy = energy

    def feed(self):
        if 0 <= self.hunger <= 10:
            self.hunger -= 2

    def give_water(self):
        if 0 <= self.thirst <= 10:
            self.thirst -= 2

    def play(self):
        if 0 <= self.happiness <= 10 and 0 <= self.energy <= 10:
            self.happiness += 2
            self.energy -= 2

    def sleep(self):
        if 0 <= self.happiness <= 10 and 0 <= self.energy <= 10:
            self.happiness -= 2
            self.energy += 3

    def get_status(self):
        print(f"{self.name} has a hunger level of {self.hunger}, a thirst level of {self.thirst}, a happiness level of {self.happiness}, and {self.energy} energy")

class Game:
    def __init__(self, pet):
        self.pet = pet

    def play(self):
        print("Choose one of the following options: (A) feed, (B) give water, (C) play , (D) sleep. Only choose the letter coresponding to the answer")
        while True:
            answer = input("Answer: ")
            if answer[0].lower() not in ['a','b','c','d']:
                raise ValueError ('please input the letter of the answer(a, b ,c or d) ')
            else:
                if answer.lower() == 'a':
                    self.pet.feed()
                elif answer.lower() == 'b':
                    self.pet.give_water()
                elif answer.lower() == 'c':
                    self.pet.play()
                elif answer.lower() == 'd':
                    self.pet.sleep()

def main():
    doggo = Pet("Dante", 5, 2, 6, 1)
    user = Game(doggo)
main()



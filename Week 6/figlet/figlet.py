from sys import argv
from sys import exit
import random
from pyfiglet import Figlet

def main():
    figlet = Figlet()
    fonts = figlet.getFonts()
    if len(argv) == 1:
        text = input('Text: ')
        figlet.setFont(font = random.choice(fonts))
        print(figlet.renderText(text))
    elif len(argv) == 3 and (argv[1] == '-f' or argv[1] == '--font') and argv[2] in fonts:
        text = input('Text: ')
        figlet.setFont(font = argv[2])
        print(figlet.renderText(text))

    else:
        print('Invalid usage')
        exit(1)




main()
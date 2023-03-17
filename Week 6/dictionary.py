#Spell checker problem set 5
words = set()



def check(word):
    if word.lower() in words:
        return True
    else:
        return False

def load(dictionary):
    file = open(dictionary, "r")
    for line in file:
        word = line.rstrip()  #rsrtip = reverse strip gets rid of the \n
        words,add(word)
    close(file)
    return True


def size():
    return len(words)   #returns the lengths of the words

def unload():
    return True



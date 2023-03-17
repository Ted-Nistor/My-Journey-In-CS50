# TODO
def main():
    text = input("Insert Text: ")
    letters = 0
    words = len(text.split())
    sentences = 0
    for i in text:
        if i.isalpha():
            letters += 1
        if i.endswith(('.', '!', '?')):
            sentences += 1
    # print(letters)
    # print(words)
    # print(sentences)
    grade = round(0.0588 * ((letters/words) * 100) - 0.296 * ((sentences/words) * 100) - 15.8)
    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


main()
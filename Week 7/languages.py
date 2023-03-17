import csv
import random

trials = 100
languages = ['Java', 'Kotlin', 'C', 'C++', 'Javascript', 'Python', 'C#', 'PHP']

# create dictionary to hold scores for each language
scores = {language: 0 for language in languages}

# generate random scores for each language
for i in range(trials):
    # randomly select a language and add a random score
    language = random.choice(languages)
    scores[language] += 1

# write scores to CSV file
with open('languages.csv', 'w') as file:
    writer = csv.writer(file)
    writer.writerow(['Language', 'Score'])
    for language, score in scores.items():
        writer.writerow([language, score])
    ratings = scores.items()

print(ratings)
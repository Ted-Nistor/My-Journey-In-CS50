import csv

# with open("favorites.csv", "r") as file:
#     reader = csv.DictReader(file)
#     comedy, drama, sci_fi = 0, 0, 0
#     comedy_titles , drama_titles, sci_fi_titles = [], [], []
#     for row in reader:
#         title = row['title']
#         genre = row['genres']
#         if 'Comedy' in genre:
#             comedy += 1
#             comedy_titles.append(title)
#         elif 'Drama' in genre:
#             drama += 1
#             drama_titles.append(title)
#         elif 'Sci-Fi' in genre:
#             sci_fi += 1
#             sci_fi_titles.append(title)

# print(f"Comedies: {comedy}, Dramas: {drama}, Sci-fi: {sci_fi}")
# for title in sci_fi_titles:
#     print(title)

#othe way

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = {}
    for row in reader:
        genres = row['genres']
        genre_list = genres.split(', ')
        for genre in genre_list:
            if genre in counts:
                counts[genre] += 1
            else:
                counts[genre] = 1
        title = row['title']

for genre in sorted(counts,key = lambda genre: counts[genre], reverse = True):
    print(f"{genre}: {counts[genre]}")


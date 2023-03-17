import csv
import requests
from collections import deque


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    # create a dictionary for new cases
    new_cases = {}
    # loop through the rows of the file and assign the name and cases
    for row in reader:
        state_name = row['state']
        cases_value = int(row['cases'])
        # if the state is not already in the dictionary, first deque the dictionary
        # so it only has the 14 most recent entries, then append the cases value to
        # the key of the dictionary(key being the state name)
        if state_name not in new_cases:
            new_cases[state_name] = deque(maxlen=14)
        new_cases[state_name].append(cases_value)
        # to make it prettier so it doesn't always show deque[...], convert the case values
        # to a list
    for state_name in new_cases:
        new_cases[state_name] = list(new_cases[state_name])
    return new_cases


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    # loop through the states and assign the cases values to each state
    for state in states:
        cases = new_cases[state]
        # initialize an average then loop through the last 7 entries.
        # we already know that they're only going to be 14 entries in the list
        average = 0
        # initialize a value for differences and add to the sum
        # we could create more variables, but I decided to just stick with only
        # difference and average, so all the maths are going to be done by only
        # using them
        difference = 0
        for i in range(7, len(cases), 1):
            average += cases[i]
        for j in range(len(cases) - 7):
            difference += cases[i]
        print(f"{state} had a 7-day average of {average / 7:.2f}", end='')
        # if it's an increase, print increase of..., else print decrease of...
        # the value in percents is the sum of the values in the previous week

        if (average / 7 - difference / 7) / (average / 7) >= 0:
            print(f" increase of {(average / 7 - difference / 7) / (average / 7):.5f}%")
        else:
            print(f" decrease of {-(average / 7 - difference / 7) / (average / 7):.5f}%")


main()

import csv
import csv
from sys import argv
from sys import exit


def main():

    # TODO: Check for command-line usage

    while True:
        if len(argv) == 3:
            break
        else:
            print("Usage python dna.py databases/file.csv sequences/file.txt")
            exit()
    # TODO: Read database file into a variable

    with open(argv[1], 'r') as database:
        database_contents = csv.DictReader(database)
        fieldnames = database_contents.fieldnames
        database_rows = [row for row in database_contents]

    # TODO: Read DNA sequence file into a variable
    with open(argv[2], 'r') as file:
        file_contents = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    str_count = {}
    for str_name in database_contents.fieldnames[1:]:
        str_count[str_name] = longest_match(file_contents, str_name)
        
    # TODO: Check database for matching profiles
    for row in database_rows:
        name = row['name']
        matches = True
        for str_name in fieldnames[1:]:
            if str_count[str_name] != int(row[str_name]):
                matches = False
                break
        if matches:
            print(name)
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()

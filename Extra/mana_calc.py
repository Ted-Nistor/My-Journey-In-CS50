def main():
    print("Input spell parameters")
    magnitude = {
        "1":0,
        "2":1,
        "3":2,
        "4":3,
        "5":5
    }
    range = {
        "1":0,
        "2":1,
        "3":2,
        "4":3,
        "5":5
    }
    duration = {
        "1":0,
        "2":1,
        "3":2,
        "4":3,
        "5":5
    }

    while True:
        key_magnitude = input("Magnitude: ")
        key_range = input("Range: ")
        key_duration = input("Duration: ")
        if key_magnitude in magnitude and key_range in range and key_duration in duration:
            break
    magnitude_value = magnitude[key_magnitude]
    range_value = range[key_range]
    duration_value = duration[key_duration]

    print(magnitude_value)
    print(range_value)
    print(duration_value)
    total = magnitude_value + range_value + duration_value
    print(f"Total Mana: {total}")

main()
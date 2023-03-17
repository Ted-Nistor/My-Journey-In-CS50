def int_to_roman(num):
    roman_numeral = ""
    thousands = num // 1000
    num %= 1000
    hundreds = num // 100
    num %= 100
    tens = num // 10
    ones = num % 10

    # Add "M" for thousands
    roman_numeral += "M" * thousands

    # Handle hundreds place
    if hundreds == 9:
        roman_numeral += "CM"
    elif hundreds >= 5:
        roman_numeral += "D" + "C" * (hundreds - 5)
    elif hundreds == 4:
        roman_numeral += "CD"
    else:
        roman_numeral += "C" * hundreds

    # Handle tens place
    if tens == 9:
        roman_numeral += "XC"
    elif tens >= 5:
        roman_numeral += "L" + "X" * (tens - 5)
    elif tens == 4:
        roman_numeral += "XL"
    else:
        roman_numeral += "X" * tens

    # Handle ones place
    if ones == 9:
        roman_numeral += "IX"
    elif ones >= 5:
        roman_numeral += "V" + "I" * (ones - 5)
    elif ones == 4:
        roman_numeral += "IV"
    else:
        roman_numeral += "I" * ones

    return roman_numeral


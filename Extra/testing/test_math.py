import testing_practice

def test_add_numbers():
    # Case 1 : adding two positive numbers
    assert testing_practice.add_numbers(2,3) == 5

    # Case 2 : adding two negative numbers
    assert testing_practice.add_numbers(-2, -3) == -5

    # Case 3 : adding a positive and a negative number
    assert testing_practice.add_numbers(2, -3) == -1

    # Case 4 : adding zero and a number
    assert testing_practice.add_numbers(0,5) == 5

    # Case 5 : adding a number and zero
    assert testing_practice.add_numbers(5,0) == 5

    # Case 6 : adding two zeroes
    assert testing_practice.add_numbers(0,0) == 0

    # Case 7 : adding two decimal numbers
    assert testing_practice.add_numbers(1.5, 2.7) == 4.2

    # Case 8 : adding a string and a number
    try:
        testing_practice.add_numbers(2, "3")
    except TypeError as e:
        assert str(e) == "unsupported operand type(s) for +: 'int' and 'str'"

    # Case 9 : adding two strings
    try:
        testing_practice.add_numbers("2", "3")
    except TypeError as e:
        assert str(e) == "unsupported operand type(s) for +: 'str' and 'str'"
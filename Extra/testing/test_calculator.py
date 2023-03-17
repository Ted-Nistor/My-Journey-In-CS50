import pytest
import calculator

test_obj = calculator.Calculator()


# Case 1: Test the basic functionality of the calculator
# by performing basic arithmetic
def test_calculator_basic_functions():
    # Case 1 A. Add two numbers
    assert test_obj.add(2,3) == 5
    # Case 1 B. Subtract two numbers
    assert test_obj.subtract(5,3) == 2
    # Case 1 C. Multiply two numbers
    assert test_obj.multiply(2,3) == 6
    # Case 1 D. Divide two numbers
    assert test_obj.divide(6,3) == 2

# Case 2: Test the calculator against edge cases
def test_calculator_edge_cases():
    # Case 2 A. Dividing by 0
    with pytest.raises(ValueError):
        test_obj.divide(4,0)
    # Case 2 B. Diving by a negative number
    assert test_obj.divide(4,-2) == -2
    # Case 2 C. Division with two negative numbers
    assert test_obj.divide(-4,-2) == 2
    # Case 2 D. Dividing by a string
    try:
        test_obj.divide(2, "3")
    except TypeError as e:
        assert str(e) == "unsupported operand type(s) for /: 'int' and 'str'"
    # Case 2 E. Dividing two strings
    try:
        test_obj.divide("2","3")
    except TypeError as e:
        assert str(e) == "unsupported operand type(s) for /: 'str' and 'str'"

    # Case 2 F. Adding a string - Problem of implementation
    # try:
    #     test_obj.add("2", 3)
    # except TypeError as e:
    #     assert str(e) == "unsupported operand type(s) for +: 'str' and 'int'"
    try:
        test_obj.add(2, "3")
    except TypeError as e:
        assert str(e) == "unsupported operand type(s) for +: 'int' and 'str'"

    # Case 2 G. Adding two strings
    try:
        test_obj.add("2","3")
    except TypeError as e:
        assert str(e) == "unsupported operand type(s) for +: 'str' and 'str'"
    # Case 2 H. Subtracting a string


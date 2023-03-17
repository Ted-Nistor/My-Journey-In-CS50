def main():
    my_list = [5,7,2,10,4]
    target_value = 10
    linear_search(my_list,target_value)


def linear_search(lst, target):
    for i in range(len(lst)):
        if lst[i] == target:
            print(f"Found element {lst[i]} at index {i}")
            return i
    print(f"Element {target} is not in the list")
    return -1

main()

def main():
    my_list = [2,4,6,7,8,10,15,20,25]
    target = 7
    print(binary_search(my_list, target))


def binary_search(lst, target):
    left = 0
    right = len(lst) - 1

    while left <= right:
        mid = (left + right) // 2

        if lst[mid] == target:
            return mid
        elif lst[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

main()
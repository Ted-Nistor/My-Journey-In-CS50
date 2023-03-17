def main():
    my_list = [5,7,19,1,3,6,24,10,8,12]
    target = 10
    print(bubble_sort(my_list))
    if binary_search(bubble_sort(my_list), target):
        print(f"Found element {target} in the list")

def bubble_sort(lst):
    n = len(lst)
    for i in range(n):
        for j in range(n - i - 1):
            if lst[j] > lst[j + 1]:
                lst[j], lst[j + 1] = lst[j + 1], lst[j]
    return lst

def binary_search(lst, target):
    left = 0
    right = len(lst) -1

    while left <= right:
        mid = (left + right) // 2
        if lst[mid] == target:
            return lst[mid]
        elif lst[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    print(f"Couldn't find element {target} in the list")
    return -1

main()
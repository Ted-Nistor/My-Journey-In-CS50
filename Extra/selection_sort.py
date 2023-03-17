def main():
    my_list = [2,6,0,12,15,20,30,4,7,9,16]

    print(selection_sort(my_list))

def selection_sort(list):
    for i in range(1, len(list)):
        j = i
        while j > 0 and list[j - 1] > list[j]:
            list[j], list[j - 1] = list[j -1], list[j]
            j -= 1
    return list

main()


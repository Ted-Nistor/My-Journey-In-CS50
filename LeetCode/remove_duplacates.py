original_list = [1,2,2,3,4,4,5]
set_list = []

for element in original_list:
    if element not in set_list:
        set_list.append(element)
print(set_list)
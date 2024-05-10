def selection_sort_asc(arr):

    for i in range(len(arr)):
        min_index = i
        for j in range(i+1, len(arr)):
            if arr[min_index] > arr[j]:
                min_index = j

        arr[i], arr[min_index] = arr[min_index], arr[i]

    return arr

def selection_sort_dsc(arr):

    for i in range(len(arr)):
        min_index = i
        for j in range(i+1, len(arr)):
            if arr[min_index] < arr[j]:
                min_index = j

        arr[i], arr[min_index] = arr[min_index], arr[i]

    return arr


arr = [10, 9, 5, 18, 2]
val1 = selection_sort_asc(arr)
print(val1)

val2 = selection_sort_dsc(arr)
print(val2)

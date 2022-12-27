def quicksort(lst):
    if(len(lst)<=1):
        return lst
    else:
        pivot = lst.pop()
        greater = []
        smaller = []

        for i in lst:
            if(i<pivot):
                smaller.append(i)
            else:
                greater.append(i)

        return quicksort(smaller) + [pivot] + quicksort(greater)

lst = [5, 10, 7, 25, 18]
print(quicksort(lst))


#program For Bubble Sort


def bubble_sort(lst):

    n = len(lst)
    for j in range(0, n-1):
        for i in range(0, n-1):
            if(lst[i]>lst[i+1]):
                temp = lst[i]
                lst[i] = lst[i+1]
                lst[i+1] = temp
        
lst = [568, 320, 600, 55, 480]
bubble_sort(lst)
print(lst)


#SELECTION SORT:

def selection_sort(lst):
    n = len(lst)
    for i in range(n-1):
        min = i
        for j in range(i+1, n):
            if(lst[j]<lst[i]):
                min = j
        temp = lst[i]
        lst[i] = lst[min]
        lst[min] = temp

lst = [550,10, 20, 58, 50, 2]
selection_sort(lst)
print(lst)






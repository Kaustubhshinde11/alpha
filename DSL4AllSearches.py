# Program of Linear Search
def linear_search(list1, n, p):
    for i in range(0, n):
        if(list1[i] == p):
            return i
    return -1

list1=[]
n=int(input("Enter the number of students who attended test"))
for i in range(n):
    rolls=int(input("Enter the roll number"))
    list1.append(rolls)
print(list1)
p = int(input("Enter the key to search for: "))
                    
        
res = linear_search(list1, n, p)
if(res==-1):
    print("Roll Number not found")
else:
    print("Roll Number found at index ", res)



#program of Binary search

def binary_search(list1, key):
    start = 0
    end = len(list1)-1
    mid=0
    while(start<=end):
        mid = (start+end)//2
        if(list1[mid]<key):
            start = mid+1
        elif(list1[mid]>key):
            end = mid-1
        else:
            return mid
    return -1



list1=[10, 20, 30, 40, 50]
key = 10


print(" Element found")
                    
res = binary_search(list1, key)
if(res!=-1):
    print("Topper found at index ", res)
else:
    print("Topper not found at index ")



#Program Of Sentenel Search

def sentenel(lst, target):
    size = len(lst)
    lst.append(target)
    i=0
    while(lst[i]!=target):
        i += 1
    if(i==size):
        return None
    else:
        return i
    

lst = [10, 20, 30, 50, 80, 541]
target = 700

res = sentenel(lst, target)
if(res!=None):
    print("Element found at index", res)
else:
    print("Element not found")
    



    

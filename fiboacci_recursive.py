n = int(input("Enter the number of terms you want: "))

step_count = 0


def fibo(p):

    global step_count
    step_count += 1

    if p <= 1:
        return p
    else:
        return fibo(p-1) + fibo(p-2)


for i in range(n):
    print(fibo(i), end = " ")

print("The total recursive calls are: ", step_count)



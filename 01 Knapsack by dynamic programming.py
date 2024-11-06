class Item:

    def __init__(self, value, weight):

        self.value = value
        self.weight = weight
        

def Knapsack_sol(capacity, items):

    dp = [0]*(capacity+1)

    for item in items:

        for w in range (capacity, item.weight-1, -1):

            dp[w] = max(dp[w], dp[w - item.weight] + item.value)


    return dp[capacity]

items = []
capacity = int(input("Enter the total capacity: "))
i = int(input("Enter the number of items: "))

for w in range(i):
    value = int(input("Enter the value: "))
    weight = int(input("Enter the weight: "))
    items.append((Item(value, weight)))
    
max_val = Knapsack_sol(capacity, items)

print("The maximum value that knapsack can hold within given weight is: ", max_val)


        

class Item:

    def __init__(self, value, weight):
        
        self.value = value
        self.weight = weight

    def value_weight(self):
        
        return self.value / self.weight


def Fractional_Knapsack(capacity, items):

    items.sort(key = lambda item: item.value_weight(), reverse = True)

    total_value = 0.0

    remaining_capacity = capacity

    for item in items:
        if item.weight <= remaining_capacity:
            
            total_value += item.value
            remaining_capacity -= item.weight

        else:

            fraction = remaining_capacity/item.weight

            total_value += item.value*fraction
            break

    return total_value


items = []
capacity = int(input("Enter the total capacity: "))
i = int(input("Enter the number of items: "))

for w in range(i):
    value = int(input("Enter the value: "))
    weight = int(input("Enter the weight: "))
    items.append((Item(value, weight)))
    
max_val = Fractional_Knapsack(capacity, items)

print("The maximum value that knapsack can hold within given weight is: ", max_val)

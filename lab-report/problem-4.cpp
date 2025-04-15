FractionalKnapsack(W, items):
    Sort items by value/weight ratio in descending order
    total_value = 0

    for item in items:
        if W == 0:
            break
        if item.weight <= W:
            W -= item.weight
            total_value += item.value
        else:
            fraction = W / item.weight
            total_value += item.value * fraction
            W = 0

    return total_value

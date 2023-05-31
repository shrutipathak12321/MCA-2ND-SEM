import math
def is_odd(num):
    return math.sqrt(num) % 2 != 0

def square(num):
    return num * num

# List of numbers
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# Use map to square each number
squared_numbers = list(map(square, numbers))

# Use filter to keep only odd numbers
filtered_numbers = list(filter(is_odd, squared_numbers))

print(filtered_numbers)
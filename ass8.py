# Create a list of all numbers up to N=50 that are multiples of five using an anonymous function

N = 50

# Use a list comprehension with an anonymous function
multiples_of_five = [num for num in range(1, N+1) if (lambda x: x % 5 == 0)(num)]

# Print the list of multiples of five
print(multiples_of_five)
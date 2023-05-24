from itertools import compress,count
numbers=count(1)
odd_pattern= [True,False]*10
odd_numbers= compress(numbers,odd_pattern)
print("First 10 odd numbers : ")
for _ in range(10):
    print(next(odd_numbers),end = " ")
print()

numbers=count(1)
even_pattern= [False,True]*10
even_numbers= compress(numbers,even_pattern)
print("First 10 even numbers : ")
for _ in range(10):
    print(next(even_numbers),end = " ")
print()
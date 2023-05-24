min=int(input("Enter the lowest range: "))
max=int(input("Enter the upper range: "))
print("The Prime numbers in the range are: ")
for i in range(min,max+1):
    if i > 1:
        for j in range(2,i):
            if (i%j) == 0:
                break
        else:
            print(i)




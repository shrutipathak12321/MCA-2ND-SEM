def fibo_generator():
    a,b=0,1
    count=0
    while count < 7:
        yield a
        a,b=b,a+b
        count +=1

fib_gen= fibo_generator()

print("Fibonacci Sequence with 7 terms: ")
for i in range(7):
    fibo_num=next(fib_gen)
    print(fibo_num, end= " ")

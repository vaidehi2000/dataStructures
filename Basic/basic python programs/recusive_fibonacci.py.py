def fibonacci(n):
    if(n <=1):
        return n
    else:
        return(fibonacci(n-1) + fibonacci(n-2))

#driver code
n = int(input("Enter number of terms :")) #taking input and to be on safe side converting it to int
print("Fibonacci sequence is:")
for i in range(n):
    print fibonacci(i), #calling and printing values

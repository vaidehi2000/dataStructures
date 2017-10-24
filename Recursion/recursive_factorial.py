def fact(n):
    if n==1: #terminating condition
        return 1
    else:
        return n*fact(n-1) #calling the fucntion again (recursion)
n=input("Enter the Number :")
answer=fact(n)
print "The answer is ",answer

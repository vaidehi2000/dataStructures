#Sum of array in python
arr = []
s=0 #empty variable to store sum
n=input("Enter the length of array :")    # taking the size of array
for a in xrange(n):
    data=input("Enter the element :")
    arr.append(data)    #adding element to the array
for a in arr: #iterating through each element and adding it to s
    s+=a
print "The sum of the array is",s #printing the result

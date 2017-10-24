#checking pallindrome using 2 methods
s=raw_input("Enter the string :")
temp=[] #empty list
#using slicing
if s==s[::-1]: 
    print "String",s,"is a Pallindrome"
else:
    print "String",s,"is not a Pallindrome"

#using stack

for a in xrange(-1,-len(s)-1,-1): #storing the string in reverse order (LIFO)
    temp.append(s[a])

if list(s)==temp: 
    print "String",s,"is a Pallindrome"
else:
    print "String",s,"is not a Pallindrome"

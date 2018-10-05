# finding whether the entered year is leap year or not.
# Enter the year as input and output will be True or false

def is_leap(year):  #function to check the leap year
    leap = False
    # logic here
    if  year%4 == 0:
        if year%100 == 0 :
            if year%400 == 0:
                leap=True
            else :
                leap=False
        else :
            leap=True
    return leap
year=int(input())   #taking input
print(is_leap(year)) #printing the result

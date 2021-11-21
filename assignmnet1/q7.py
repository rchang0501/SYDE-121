import sys 
import math 

lines = 0 
max_int = 0
min_int = 0
total_int = 0.0
avg_int = 0.0 
total_squared = 0.0 
stdev = 0.0 

for curr in sys.stdin: 
    lines += 1 # count the number of lines 
    currInt = int(curr) # convert the current line into an integer 
    total_int += currInt # add all the numbers in the file together 

    # Determine the sum of squares
    total_squared += currInt*currInt 

    # initialize the max and min integers 
    if (lines == 1):
        max_int = currInt 
        min_int = currInt

    # Determine the biggest integer------------------------------------
    elif (currInt > max_int): 
        max_int = currInt

    # Determine the smallest integer-----------------------------------
    elif (currInt < min_int): 
        min_int = currInt

if (lines <= 1):
    print("ERROR")

else:
    avg_int = total_int/lines 

    stdev = math.sqrt(1/(lines-1)*(total_squared - lines*avg_int*avg_int))

    print ("number of integers: " + str(lines))
    print ("max integer read: " + str(max_int))
    print ("min integer read: " + str(min_int))
    print ("average of integers read: " + str(avg_int))     
    print ("standard deviation: " + str(stdev))    

    


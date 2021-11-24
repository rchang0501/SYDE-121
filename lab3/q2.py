import sys 
import math 

lines = 0 
total_int = 0.0
avg_int = 0.0 
total_squared = 0.0 
stdev = 0.0 

values = [] #list to hold all input values

for curr in sys.stdin: 
    lines += 1 #count the number of lines 
    
    currInt = int(curr) # convert the current line into an integer
    total_int += currInt # add all the numbers in the file together

    values.append(currInt) # add the number to the value array 

# making sure there are enough values to compute standard deviation 
if (len(values) <= 1):
    print("ERROR") # ouput error line 

else:
    avg_int = total_int / lines #calculate the average of the values 

    # iterate through list 
    for i in range (0, len(values), 1): 
        total_squared += (values[i] - avg_int)*(values[i] - avg_int) # compute the numerator of the expression 
    
    stdev = math.sqrt(1/(lines-1)*(total_squared)) # comput the standard deviation 
    print ("standard deviation: " + str(stdev))    

    


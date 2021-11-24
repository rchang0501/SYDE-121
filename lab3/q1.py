#Program and code a simplified tac command that reads in lines 
# and outputs the lines read in reverse order. 
# Document your program as a flowchart.

import sys

arr = []

for curr in sys.stdin: 
    arr.append(curr)

for i in range (len(arr)-1, -1, -1): 
    print(arr[i]) 


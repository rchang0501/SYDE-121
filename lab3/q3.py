import sys 

values = []
#list = [][] #matrix (2d array)
lines = 0 
rows = 0.0 
cols = 0.0 

for curr in sys.stdin: 
    lines += 1 
    curr_int = float(curr)

    if (lines == 1):
        rows = int(curr)
    elif (lines == 2):
        cols = int(curr)

    else: 
        values.append(curr_int)

counter = 0 
list = [[0 for x in range(cols)] for y in range(rows)] 

for i in range (0, rows, 1):
    for j in range(0, cols, 1):
        list[i][j] = values[counter]
        counter+=1  

for element in list:
    print(element)
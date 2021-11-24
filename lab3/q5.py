import sys 

values = []
targets = []
lines = 0 
rows = 0.0 
cols = 0.0 

for curr in sys.stdin: 
    lines += 1 
    curr_num = float(curr)

    if (lines == 1):
        rows = int(curr)
    elif (lines == 2):
        cols = int(curr)

    elif (lines > 2 and lines <= (rows * cols) + 2): 
        values.append(curr_num)

    else: 
        targets.append(int(curr))

counter = 0 

list = [[0 for x in range(cols)] for y in range(rows)] 

for i in range (0, rows, 1):
    for j in range(0, cols, 1):
        list[i][j] = values[counter]
        counter+=1  

print ("Matrix")
print ("-------------")

# print matrix 
for element in list:
    print(element)

print ("\nTargets")
print ("-------------")

targ_row = 0 
targ_col = 0 
targ_pair = 1 

for i in range (0, len(targets), 1):
    if (i % 2 == 0):
        targ_row = targets[i] - 1
    elif (i % 2 != 0):
        targ_col = targets[i] - 1 
        if (targ_row >= int(rows) or targ_col >= int(cols)):
            print("Target " + str(targ_pair) + ": ERROR - Target out of bounds")
            targ_pair += 1
        else: 
            print ("Target " + str(targ_pair) + ": " + str(list[targ_row][targ_col]))
            targ_pair += 1 


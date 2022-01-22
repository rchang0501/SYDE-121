import sys

lines = 0 # line counter 
start = 0 # start index holder 
end = 0 # end index holder 
stride = 0 # stride holder 

# loop to iterate through text documennt 
for curr in sys.stdin: 
    lines += 1 # increment the number of lines to track which line we're reading 

    # setting the start, end, and stride numbers 
    if (lines == 1):
        start = int(curr) + 3 # we add three to adjust for the lines the parameters take up 
    elif (lines == 2):
        end = int(curr) + 3 # we add three to adjust for the lines the parameters take up
    elif (lines == 3):
        stride = int(curr)

    # check if the start and end indexes are formatted correctly 
    if (lines == 3 and start > end):
        print("ERROR - not sequenced properly") 
        break # end the loop and program 

    # print lines based on parameters 
    if ((lines >= start) and ((lines-start) % stride == 0) and (lines <= end)):
        print(curr)
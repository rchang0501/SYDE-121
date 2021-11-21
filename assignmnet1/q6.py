import sys 

a = False  # let a be the first pair value 
b = False  # let b be the second pair value 
lines = 0 # line counter for file reader 
pair = 0 # pair counter for output 

# file reader 
for curr in sys.stdin:

    lines += 1

    # assign proper boolean based on input
    if (lines % 2 == 1): #odd number lines represent the a (first pair) value 
        # check for empty line 
        if (curr == "" or curr == "\n"):
            a = False
        else:
            a = True
    elif (lines % 2 == 0):  #even number lines represent the b (second pair) value 
        # check for empty line 
        if (curr == "" or curr == "\n"):
            b = False
        else:
            b = True

    # output (only occurs for each pair)
    if (lines % 2 == 0):
        pair += 1 #increment the pair number 

        print ("Pair number: " + str(pair))
        print ("-----------------------------")
        
        # first case of De Morgan's Law 
        print("not (a and b)")
        if (not( a and b)):
            print ("true\n")
        else: 
            print ("false\n")

        # second case of De Morgan's Law 
        print("not(a) or not(b))")
        if (not(a) or not(b)):
            print ("true\n")
        else: 
            print ("false\n")

        # third case of De Morgan's Law 
        print("not (a or b)")
        if (not(a or b)):
            print("true\n")
        else: 
            print ("false\n")

        # fourth case of De Morgan's Law 
        print("not(a) and not(b))")
        if (not(a) and not(b)):
            print ("true\n")
        else:
            print ("false\n")
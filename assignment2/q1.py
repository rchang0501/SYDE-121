import sys

f = sys.stdin
flag = True

global_line_number = 0
number_of_paramters = 2

while flag:
    current_line = f.readline()

    if(current_line == ""):
        flag = False

    global_line_number += 1

    if global_line_number == 1:
        start_highlighting = int( current_line.strip() )
    elif global_line_number == 2:
        stop_highlighting = int( current_line.strip() )
    else:
        if ( ( ( global_line_number - number_of_paramters ) >= start_highlighting ) 
         and ( ( global_line_number - number_of_paramters ) <= stop_highlighting  ) ) :
            print ( "\033[1;33m" + current_line + "\033[0m", end="" )
        else:
            print ( current_line, end="" )

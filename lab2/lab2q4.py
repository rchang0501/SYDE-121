import sys

# Variable declaration 
prev_line = 0
curr_trend = "increasing"
first_element = True 
inc_sec_count = 0
dec_sec_count = 0
longest_inc_seq = 0
longest_dec_seq = 0
start_increasing = 0	
last_increasing = 0
star_decreasing = 0
last_decreasing = 0

for current_line in sys.stdin:

    current_line = current_line.strip()

    if (first_element):
        previous_element = int(current_line) 
        start_increasing = first_element
        star_decreasing = first_element
        first_element = False 

    else:
        if (int(current_line) > int(prev_line)):

            if (curr_trend == "decreasing"):
                if (longest_dec_seq <= dec_sec_count):
                    longest_dec_seq = dec_sec_count
                    decreasing_sequence_last_value = prev_line

                dec_sec_count = 0
                inc_sec_count = 1

                start_increasing = prev_line

                curr_trend = "increasing"

            # increment if trend continues 
            else:
                inc_sec_count += 1

            prev_line = current_line

        elif (int(current_line) < int(prev_line)):

            if (curr_trend == "increasing"):
                if (longest_inc_seq <= inc_sec_count):

                    longest_inc_seq = inc_sec_count
                    inc_last_val = prev_line

                dec_sec_count = 1
                inc_sec_count = 0
                star_decreasing = prev_line
                curr_trend = "decreasing"

            else:
                dec_sec_count += 1

            prev_line = current_line

# final checks 
if (curr_trend == "increasing"):
    inc_last_val = current_line
    if (longest_inc_seq < inc_sec_count):
        longest_inc_seq = inc_sec_count
else:
    decreasing_sequence_last_value = current_line
    if (longest_dec_seq < dec_sec_count):
        longest_dec_seq = dec_sec_count

# output 
if (longest_inc_seq > longest_dec_seq):
    print ("start: " + str(start_increasing) + "\t" + "end: " + str(inc_last_val) + "\t" + "length: " + str(longest_inc_seq+1) + "\t" + "direction: increasing")
else:
    print ("start: " + str(star_decreasing) + "\t" + "end: " + str(decreasing_sequence_last_value) + "\t" + "length: " + str(longest_dec_seq+1) + "\t" + "direction: decreasing")

import sys

num_read = 0
total_lines = 0
avg_length = 0

for current_line in sys.stdin:
	num_read += 1 #increment 

	strip_line = current_line.strip()
	strip_length = len( strip_line )

	total_lines += strip_length #add curent length to total legnth 
	length_as_string = str( strip_length )
	output_string = length_as_string + "\t" + current_line
	
	print( output_string, end='' )

# find average length of line 
avg_length = total_lines/num_read

# convert all variables to strings 
lines_string = str(num_read)
total_lengths_string = str(total_lines)
average_length_string = str(avg_length)

# output footer 
print ("lines: " + lines_string + "\t" + "total length: " + total_lengths_string + "\t" + "average length: " + average_length_string)

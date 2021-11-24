import sys

num_read = 0
total_lines = 0
avg_length = 0
short_length = 1000
long_length = 0

for current_line in sys.stdin:
	num_read += 1 #increment 

	strip_line = current_line.strip()
	strip_length = len( strip_line )

	total_lines += strip_length #add curent length to total legnth 
	length_as_string = str( strip_length )
	output_string = length_as_string + "\t" + current_line
	
	# is current line shorter than shortest line? 
	if (strip_length < short_length):
		short_length = strip_length
	
	# is current line longer than longest line 
	if (strip_length > long_length):
		long_length = strip_length
	
	print( output_string, end='' )

# find average length of line 
avg_length = total_lines/num_read

# convert all variables to strings 
lines_string = str(num_read)
total_lengths_string = str(total_lines)
average_length_string = str(avg_length)
long_length_string = str(long_length)
short_length_string = str(short_length)

# output footer 
print ("lines: " + lines_string + "\t" + "total length: " + total_lengths_string + "\t" + "average length: " + average_length_string)
print ("length of shortest line: " + short_length_string + "\t" + "length of longest line: " + long_length_string)

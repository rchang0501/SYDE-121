import sys

for current_line in sys.stdin:

	# Convert the number into integer so we can do math operations
	current_line_value = int(current_line)

	# If statements to determine whether it is divisible by 3, 5, or 5 and 5
	if (current_line_value % 3) == 0 and (current_line_value % 5) == 0:
		print (str(current_line_value) + "\t" + " Fizz Buzz")
	elif (current_line_value % 3) == 0:
		print (str(current_line_value) + "\t" + " Fizz")
	elif (current_line_value % 5) == 0:
		print (str(current_line_value) + "\t" + " Buzz")
	else:
		print (str(current_line_value))


#Assignment: (Homework 2)
#Description: (Turtle program)
#Author: (Elliott Villars)
#WSU ID: (11463956)
#Completion Time: 8 HOURS
#In completing this program, I obtained help or worked with the following: Brandon Menge, Osble, Google
from turtle import*
input_file = open('movements.txt','r')
lines = input_file.readlines()
#dist = 0
#dir_line = ""
print(lines)
for line in lines:
	lines = line.strip()
	if lines == 'F':
		dir_line = lines
	elif lines == 'B':
		dir_line = lines
	elif lines == 'L':
		dir_line = lines
	elif lines == 'R':
		dir_line = lines
	else:
		if lines == '100':
			dist = lines	
			if dir_line == 'F':
				forward(100)
			elif dir_line == 'B':
				backward(100)
		elif lines == '90':
			dist = lines
			if dir_line == 'L':
				left(90)
			elif dir_line == 'R':
				right(90)
	
input_file.close()

###
#Essay
###
'''
This was a very difficult program to write.
Thing were constantly breaking whenever i tried to make a coding correction.
When I originally got the program to compile, it did nto make a square. It made a shape similar to a three-year-old scribbling on a piece of paper. After 3 hours, of trying to get the damn thing to draw a square, I went and got help from Brandon Menge. He was very helpful in helping me to find where the errors in my code were.  Turns out i had a misassigned variable. I am glad I just manage to get this program to work properly. It was a vvery large time-sink. Now that I know how to perform this program again, I feel that i am ready for the next assignment. This was an exercise in patience and comprehension. I will most likely archive this program as a note for future refrence.
'''


#Assignment: Homework 7

#Description: File processing

#Author: Elliott Villars
#WSU ID:11463956
#Completion Time : 5 hours

#In completing this program, I obtained help from the following: Maxwell Tuttle, Stackoverflow.com, Google, docs.python.org

def main():
	parse_file()
def parse_file():
	global input_file
	input_file = open(input('Enter an input file: '))
	global output_file
	output_file = open(input('Enter an output file: '),'w')
	global lines
	lines = input_file.readlines()
	get_char_count_nospace()
	get_char_count_space()
	get_words()
	is_para()
	line_counts()
	overflow_count()
	output_file.write(str(lines))
	output_file.write('\n')
	output_file.write('Paragraphs: ')
	output_file.write(str(para_count))
	output_file.write('\n')
	output_file.write('Word Count: ')
	output_file.write(str(word_count))
	output_file.write('\n')
	output_file.write('Character with spaces: ')
	output_file.write(str(char_count))
	output_file.write('\n')
	output_file.write('Space Count: ')
	output_file.write(str(spc_count))
	output_file.write('\n')
	output_file.write('Line Count: ')
	output_file.write(str(line_count))
	output_file.write('\n')
	output_file.write('Overflow Lines: ')
	output_file.write(str(overflow))
	output_file.write('\n')
	
def get_char_count_nospace():
	global char_count
	char_count=0
	for line in lines:
		char_count += len(line)
	return char_count
def get_char_count_space():
	global spc_count
	spc_count=0
	for line in lines:
		spc_count += line.count(' ')
	return spc_count
def get_words():
	global word_count
	word_count=0
	for line in lines:
		word = line.split()
		word_count += len(word)
	return word_count
def is_para():
	global para_count
	para_count=0
	for line in lines:
		if line == '\n':
			para_count += 1
	return para_count
def line_counts():
	global line_count
	line_count=0
	for line in lines:
		line_count+=1
	return line_count
def overflow_count():
	global overflow
	overflow =0 
	for line in lines:
		if len(line) > 80:
			overflow +=1

main()
'''
This project was ok. I was not to difficult. With help of the internet I was able to finish this project.One struggle i overcame was calling varibles in functions. I used the global command to allivate the call before definition problem. Onne problem i was unable to over come was finding characters without spaces. I could only find the number of space characters. One piece of advice to future student: stackoverflow.com is your friend. The most fun aspect of this program was finishing it. Most challenging aspect of this was dealing with the functions.Nothing was really hard to understand as i had access to the internet. The assingment was alright, i cant think of anything to think of.
'''



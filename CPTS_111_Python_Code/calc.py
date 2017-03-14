#Assignment: Lab Final

#Description: File processing

#Author: Elliott Villars
#WSU ID:11463956
#Completion Time : DNF


# Im going to preface this by saying that nothing below works properly. Like usual, #Im getting nonsensical errors in code that SHOULD work. Below I wrote what I would #use if it did work.
While True:
	usr_inp = input('Do you wish to parse a file: Y/N')
	#prompts user for continuation
	if usr_inp == 'Y':
		input_file=open(input('Enter a file to parse: '))
		#prompts user for a file to parse
		lines = input_file.readlines()
		counter=0
		#counter is used to find the average
		for line in lines:
			if line[0] == '90':
		#if the first line is 90 then it will use the homework weighting
				for hmwk in lines:
					hmwk=int(hmwk)
					hmwk += hmwk
					counter +=1
				avg=(hmwk\counter)
				#finds the average
				weighthw= avg*90
				#finds the weighted grade
			elif line[0] == '10':
			#same as above, except uses labs at 10
				for lab in lines:
					lab = int(lab)
					lab += lab
					counter +=1
				avg2 = (lab\counter)
				#see above
				weightlab = avg2 *10
				#finds weighted lab grade
	if usr_inp =='N':
		print('Homework Score: ',weighthw)
		print('Lab Score: ',weightlab)
		print('Final Grade: ',weighthw+weightlab)
		#prints final grade


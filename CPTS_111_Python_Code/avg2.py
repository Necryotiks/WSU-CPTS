user_input= 9
big = 0
while user_input >0:
	user_input= float(input('Enter a number: '))
	if user_input <0:
		break
	if user_input > big:
		big = user_input		
print(big)
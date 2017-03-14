
user_input= 9
total = 0
count = 1
while user_input >0:
	user_input= float(input('Enter a number: '))
	if user_input <0:
		break
	else:
		total+= user_input
		count+=1
		
print(total/count)

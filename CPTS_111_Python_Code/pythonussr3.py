###Task1
import random
guess = random.randint(0,100)
print('Let\'s play the guessing game!')
print('Think of a number between 1 and 100, Press Enter to continue.')

while True:  
	subguess = random.randint(1,10)             
	if guess <=100 and guess >=1:
		print('The computer guesses: ',guess)
		print('Was guess too high(H),too low(L) or correct(C)?')
		usr = input()
		if usr == 'H':
			guess = guess - subguess
		if usr == 'L':
			guess = guess + subguess
		if usr == 'C':
			print('I win yet again, showcasing the superiority of machines over man.')
			break


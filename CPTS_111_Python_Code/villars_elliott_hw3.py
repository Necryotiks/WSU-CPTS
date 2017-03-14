#Assignment: (Guess 1)
#
#Description: (Computer guess)
#
#Author: (Elliott Villars)
#WSU ID: (11463956)
#Completion Time: (3)
#
#In completing this program, I obtained help or worked with the following:Casey HUnter, Google
###Task1
import random
#imports the random function
import time
#imports time function to allow user to guess a number
guess = random.randint(0,100)
#random varible
print('Let\'s play the guessing game!')
time.sleep(3)
print('Think of a number between 1 and 100.')
time.sleep(5)
#loops until a correct number is guessed.
while True:  
	subguess = random.randint(1,10) 
	# a subrandom variable           
	if guess <=100 and guess >=1:
		print('The computer guesses: ',guess)
		print('Was guess too high(H),too low(L) or correct(C)?')
		usr = input()
		#various user inputs
		if usr == 'H':
			guess = guess - subguess
		if usr == 'L':
			guess = guess + subguess
		if usr == 'C':
			print('I win yet again, showcasing the superiority of machines over man.')
			break
#Breaks while loop



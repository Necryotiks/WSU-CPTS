#Assignment: (Guess 2)
#
#Description: (Human guess)
#
#Author: (Elliott Villars)
#WSU ID: (11463956)
#Completion Time: (3)
#
#In completing this program, I obtained help or worked with the following:Casey HUnter, Google
###Task 2
import random
#import random varible
import time
#iimport time varible
guess = random.randint(0,100)
#rrandom varible
print ('Let\'s play a guessing game!')
time.sleep(3)
print ('Im going to think of a whole number from 0 to 100 and you will guess it!')
time.sleep(5)
#delay commands to give user time to think.
while True:  
#while loop until correct number is guessed            
		print('What is your guess?')
		usr = int(input())
		#user input goes here
		if usr == guess:
			print('You won! Thanks for playing!')
			break
		#breaks the while loop
		if usr < guess:
			print('Sorry too low! Guess again!')
		if usr > guess:
			print('Sorry too high! Guess again!')


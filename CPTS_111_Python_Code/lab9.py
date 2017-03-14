from random import *

#5,000 of the most common words imported into the variable "possible_words"
from words import *
    
#randomly pick a word to have the user guess
random_word = choice(possible_words)
underscore=[]
correct_word=[]
for a in range(len(random_word)):
	underscore.append('_')
for a in random_word:
	correct_word.append(a)
correct = False
incorrect_guess = len(random_word)
while incorrect_guess >0 and correct == False:
	print('Word Progress: ', underscore)
	print('You have', incorrect_guess, 'guesses remaining.')
	user_input = input("Enter a letter: ")
	place=0
	u=ord(user_input)
	match= False
	for x in random_word:
		place= 0
		y=ord(x)
		if u == y:
			x=correct_word[place]
			correct_word.remove(x)
			underscore.insert((place+1),x)
			underscore.remove('_')
			match=True
		place+=1
	if match == True:
		print('Correct')
	else:
		print('Incorrect')
		incorrect_guess -= 1

			


#Assignment: (Homework 6)
#
#Description: (Blackjack)
#
#Author: (Elliott Villars)
#WSU ID: (11463956)
#Completion Time: (8 hours)
#In completing this program, I obtained help or worked with the following:Google, Maxwell Tuttle

from random import*

def main():
	print('Let\'s play a game...')
	play_game()
def play_game():
	game=True
	while game == True:
		get_next_card_value()
		q=input('Continue? (y)es or (n)o.')
		if q== 'y':
			game = True
		if q== 'n':
			game = False
def get_next_card_value():
	x= randint(2,11)
	print('You have been dealt: ',x)
	player_turn=input('(H)it or (S)tand')
	count = 1
	while player_turn == 'H':
		y=randint(2,11)
		print('You have been dealt: ',y)
		if count ==1:
			z=x+y
			counter=2
		else:
			z+=y
		print('Your total is: ',z)
		if z==21:
			print('Blackjack')
			z='bj'
			break
		elif z<21:
			player_turn=input('(H)it or (S)tand')
		elif z>21:
			print('Bust')
			z='bust'
			break
	print('CPU turn')
	x= randint(2,11)
	print('CPU was dealt: ',x)
	count=1
	while True:
		y=randint(2,11)
		print('CPU was dealt: ',y)
		if count==1:
			m=x+y
			count=2
		else:
			m+=y
		print('CPU total: ',m)
		if m==21:
			print('CPU Blackjack')
			m='bj'
			break
		elif m>21:
			print('CPU Bust')
			m='bust'
			break
		elif m>17:
			cpu_turn='S'
			break
		elif m<=17:
			cpu_turn='H'
	if z=='bj':
		if m=='bj':
			print('Tie')
		else:
			print('Victory')
	elif m=='bj':
		if z=='bj':
			print('Tie')
		else:
			print('CPU victory')
	elif z=='bust':
		if m=='bust':
			print('Tie')
		else:
			print('CPU Victory')
	elif m =='bust':
		if z=='bust':
			print('Tie')
		else:
			print('Victory')
	elif z>m:
		print('Victory')
	elif z<m:
		print('CPU Victory')
	elif z==m:
		print('Tie')
main()
#THIS WAS TERRIBLE
#IGNORE ALL LOWERCASE TEXT
#MAX AND I WORKED FOR 8 DAMN HOURS TRYING TO FIGURE OUT THESE DAMN FUNCTIONS
#I WAS SO SALTY, I COULD SALT AN ENTIRE BAG OF LAYS POTATO CHIPS
#THIS WAS THE HARDEST HOMEWORK YET
#TEARS OF BLOOD WERE SHED
#I DIED ON THE INSIDE
#WE SHOULD GO OVER FUNCTIONS MORE
#This homework was easy
#This was even easier than homework three and four. I can't really talk about this project.
#This programming assignment went welll. It was pretty easy, 
#I dont have much to say in the topic. other than google was an invaluable asset.
# This excerpt for the first assignment sums up how it went:
#All and all this was not too difficult as I only ran into two problems:
#Keeping track of parenthesis and using proper operands.
#Thank god for friendship and Google (Thank You Casey Hunter).
#This was a  low difficulty project.
#Well these are my thoughts on this assignment
#Didnt shed tears of blood this time.
# Not gonna lie, the reflection essay is the hardest part.
#It was worth.
#I thoughtthat the process was mostly straight-forward.
#Was pretty easy. 
#I am running out of things to say about this.      
#learned many things out of this project
#such as how to use sleep commands and while loops 
#I feel pretty goodd about this assignment.

	
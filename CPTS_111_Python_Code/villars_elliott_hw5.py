#Assignment: (Rock, Paper,Scissors)
#
#Description: (RPS Game)
#
#Author: (Elliott Villars)
#WSU ID: (11463956)
#Completion Time: (3 hours)
#In completing this program, I obtained help or worked with the following:Google
rock = 0
scissors = 0 
paper = 0
game = True
cpu_win= 0
ties=0
player_win=0
cp_choice= 'r'
while game == True:
	choice = input('(r)ock,(p)aper,(s)cissors, or (q)uit')	
	if choice == 'r':
		rock+=1
		if cp_choice == 'r':
			rock +=1
			ties +=1
			print('This round is  a tie')
		elif cp_choice == 's':
			scissors += 1
			player_win +=1
			print('You win... for now')
		elif cp_choice == 'p':
			paper +=1
			cpu_win +=1
			print('You lose this round, git gud')
	if choice == 's':
		scissors += 1
		if cp_choice == 'r':
			rock +=1
			cpu_win +=1
			print('You lose this round, git gud')
		elif cp_choice == 's':
			scissors +=1
			ties +=1
			print('This round is a tie')
		elif cp_choice == 'p':
			paper +=1
			player_win += 1
			print('You win... for now')
	if choice == 'p':
		paper += 1
		if cp_choice =='r':
			rock +=1
			player_win +=1
			print('You win... for now')
		elif cp_choice == 's':
			scissors +=1
			cpu_win += 1
			print('You lose this round, git gud')
		elif cp_choice =='p':
			paper += 1
			ties += 1
			print('This round is a tie')
	
	if choice == 'q':
		print('Rock selected: ',rock)
		print('Paper selected: ',paper)
		print('Scissors selected: ',scissors)
		print('Ties: ',ties)
		print('Computer wins: ',cpu_win)
		print('Player wins: ',player_win)
		break
	if rock > scissors and rock > paper:
		cp_choice = 'p'
	if scissors > rock and scissors > paper:
		cp_choice = 'r'
	if paper>rock and paper>scissors:
		cp_choice= 's'
# This homework was easy
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
		
	


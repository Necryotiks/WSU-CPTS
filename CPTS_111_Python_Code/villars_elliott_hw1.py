#Assignment: (Homework 1)
#
#Description: (Loan Calculator)
#
#Author: (Elliott Moon Villars)
#WSU ID: (11463956)
#Completion Time: 4 hours
#
#In completing this program, I obtained help or worked with the following:Casey Hunter

#Task 1
#Turn list_of_numbers into a float
#float(list_of_numbers)
#Add all numbers in list
#Divide by number of entries in list_of_numbers
#Store in list_of_numbers
#print list_of_numbers

#Task 2
#user input
#determine type of user input.
#If user input is int or float 
#then print "true"
#else print "false"

#Task 3
loan = float(input('Enter your loan amount:'))
int_rate = float(input('Enter your annual interest rate:'))
loanyears = float(input('Enter loan duration (in years):'))
pay = int(input('Payment Number(Loan Duration multiplied by 12):'))
mir = (int_rate) / (12 * 100)
mp = (loan*mir) / (1 - (1 + mir)**-pay) 
print('Monthly Interest Rate:',mir)

print('Monthly Payment:',mp)

total_pay = mp * pay

print('Total amount payed over duration of loan:',total_pay)

int_pay = total_pay - loan
print('Total interest payed:',int_pay)

#Reflection Rant
#This damn program was driving me up a bloody wall.
#For 4 hours we hunted and searched for nonexistant syntax errors.
#Terminal was not being very useful in the debug process.
#Turns out ^ DOES NOT EQUAL EXPONENTS. ** DOES.
#I mean come on, why does there have to be this strange exception.
#Especially when dealing with an interest formula.
#I guess youy can say that debugging was my greatest challenge.
#It would have very beneficial to learn what the exponent command was ahead of time.
#To say that this was a frustration experience would be an understatement.
#My friend and I lost years of our lives to this cancerous assignment.
#Mathematical symbols were the bane of my existence.
#I feel that we should have put more time into going over the advanced math operations
#Such as exponents and square roots.
#All and all this was not too difficult as I only ran into two problems:
#Keeping track of parenthesis and using proper operands.
#R.I.P
#Thank god for friendship and Google (Thank You Casey Hunter).
#This was a moderate difficulty project.
#Well these are my thoughts on this assignment
#Not going to lie, I shed tears of blood.
#It was worth.



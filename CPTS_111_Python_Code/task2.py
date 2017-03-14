from turtle import *
from random import *

#question: How can we keep the turtle in "bounds"?

#--------------------------------------------------------
#step 1: define boundary
min_x = -200
max_x = 200
min_y = -200
max_y = 200

#draw box for debugging

#turn off line drawing
up()

#goto, top right
goto(max_x, max_y)

#turn on line drawing
down()

#begin drawing boundary
goto(max_x, min_y)
goto(min_x, min_y)
goto(min_x, max_y)
goto(max_x, max_y)

#turn off line drawing, go back to center
up()
goto(0,0)
down()
#---------------------------------------------------------

#define variables
x_position = 0
y_position = 0
x_speed = 3
y_speed = 3
move_x_positive = True
move_y_positive = True


#loop forever
while True:
    
    #LAB 3 TODO: put your turtle "bounce" code here
	if x_position >=200:
		move_x_positive = False
		x_speed = randint(2,5)
	elif y_position >= 200 :
		move_y_positive= False
		x_speed = randint(2,5)
	elif x_position <= -200:
		move_x_positive=True
		x_speed = randint(2,5)
	elif y_position <=-200:
		move_y_positive=True
		x_speed = randint(2,5)
	
    #NOTE: Requires several IF statements!
    #  To solve, you will need to manipulate the following variables:
    # x_speed
    # y_speed
    #move_x_positive
    #move_y_positive

    #increment location based on whether
    #we're moving right or left
	if move_x_positive == True:
		x_position += x_speed
	else:
		x_position -= x_speed

    #increment y location based on whether
    #we're moving up or down
	if move_y_positive == True:
		y_position += y_speed
	else:
		y_position -= y_speed

    #finally, move turtle
	goto(x_position, y_position)
    


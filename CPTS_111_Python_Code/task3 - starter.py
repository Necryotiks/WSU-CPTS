from turtle import *
from random import *

#question: How can we keep the turtle in "bounds"?

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

right(21)
starting_angle = 21

#loop forever
while True:
    
    #get x, y coordinates of our turtle
    turtle_x = xcor()
    turtle_y = ycor()

    #LAB 3 TODO: figure out how to rotate turtle
    #so that it stays in bounds!
    #note that you can only use left() or right()
    #functions to solve!
            
    #move in direction
    move_amount = 1
    forward(move_amount)
    

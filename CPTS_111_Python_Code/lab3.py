#Task 1
"""
from turtle import*
def graph():
	forward(200)
	back(400)
	forward(200)
	left(90)
	forward(200)
	back(400)
	return  
def inputs():
	x1 = int(input("Enter first x-coord"))
	y1 = int(input("Enter first y-coord"))
	x2 = int(input("Enter second x-coord"))
	y2 = int(input("Enter second y-coord"))
	m=(y2-y1)/(x2-x1)
	up()
	goto(x1,y1)
	down()
	goto(x2,y2)

	return x1,y1,x2,y2
def main():
	x1,y1,x2,y2 = inputs();
	graph();
main()
def draw_circle(x,y,r)
up()
goto(x-r,y-r)
down()
circle(r)
"""
#Task 2
from turtle import*
input_file = open('coordinates.txt','r')
lines = input_file.readlines()
for liine in lines:
pieces = line.split(',')
x = int(pieces[0])
y = int(pieces[1])
goto(x,y)
input_file.close()


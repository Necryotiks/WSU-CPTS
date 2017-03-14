import turtle
user_input= int(input('Enter loop count'))
go = int(1)
for i in range(user_input):
	turtle.forward(go)
	turtle.left(90)
	go= go+1
	

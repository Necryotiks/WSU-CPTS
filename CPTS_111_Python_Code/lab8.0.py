expression = list()
equation = input('Enter an expression: ')
pieces = equation.split(" "t)
for i in pieces:
	if i.isnumeric():
		i = int(i)
		expression.append(i)
	else:
		x= expression.pop()
		y= expression.pop()
		if i == '+':
			z = x+y
			expression.append(z)
		elif i == '-':
			z = x-y
			expression.append(z)
		elif i == '*':
			z = x*y
			expression.append(z)
		elif i == '/':
			z = x/y
			expression.append(z)
print(expression)
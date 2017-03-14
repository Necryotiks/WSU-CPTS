import math
inp=input('Enter a file name: ')
files = open(inp)

num_list2=list()
for line in files:
	line=float(line)
	num_list2.append(line)
'''
def get_median():
	median = num_list2
	list_len= float(len(median))
	print((list_len+1)/2)
get_median()
'''
'''
def get_frequency():
def get_mode():
'''
def get_mean():
	mean=num_list2
	avg=float(len(mean))
	for i in mean:
		i += i
	i = float(i)
	print(i/avg)
get_mean()



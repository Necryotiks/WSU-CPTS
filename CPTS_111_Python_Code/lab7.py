'''
list= [1,2,3,4,-1,10,11,12]
total = 0
counter = 0
for x in list:
	total += x
	counter += 1
	avg = total/counter
print(avg)
'''
list = [1,2,3,4,-1,10,11,12]
small = 0
for i in list:
	list.sort()
print(list[0])

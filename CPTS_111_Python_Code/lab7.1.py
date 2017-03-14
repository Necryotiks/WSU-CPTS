o_list = [1,2,3,4,-1,10,11,12]
small = 999
sorted_list= list()
counter = 0	
while len(o_list) > 0:
	for i in o_list:
		if i < small:
			small = i
			smallest_pos = counter
		counter +=1
	del o_list[smallest_pos]
	sorted_list.append(small)
	counter = 0	
print(o_list)
print(sorted_list)

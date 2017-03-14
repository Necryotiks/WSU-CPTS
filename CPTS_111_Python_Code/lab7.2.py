o_list = [1,2,3,4,-1,10,11,12]
print('list: ',o_list)
sorted_list = []
counter = 0	
while len(o_list) > 0:
	small = 999
	counter = 0	
	smallest_pos = 0
	for i in o_list:
		if i < small:
			small = i
			smallest_pos = counter
		counter +=1
	del o_list[smallest_pos]
	sorted_list.append(small)
print(sorted_list)

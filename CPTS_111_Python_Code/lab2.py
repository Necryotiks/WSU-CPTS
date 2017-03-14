###
#Task 1
###
"""
some_string = "My first string"
type(some_string)
print(some_string)
input("ENTER TO CONTINUE")
some_string = input("Type something: ")
type(some_string)
print(some_string)
input("ENTER TO CONTINUE")
numeric_string = "5.0"
type(numeric_string)
print(numeric_string)
print("what happens if we try to add a number to a numeric string")

input("ENTER TO CONTINUE")
a_number = 5
#an example of casting a number to a
#string
a_number = str(a_number)
type(a_number)
print(a_number)
input("eENTER TO CONTINUE")
#joining two strings together
string_one = "I like "
string_two = "apples"
joined_string = string_one + string_two
print(joined_string)
input("ENTER TO CONTINUE")
#find the length of a string using len()
test_string = "Hello, World!"
string_length = len(test_string)
print(string_length)
input("ENTER TO CONTINUE")
#Print the 1st character in the string.
#Note that the first character is at
#location "0".
print(test_string[0])
input("ENTER TO CONTINUE")
#print the 3rd character in the string
print(test_string[2])
input("ENTER TO CONTINUE")
#print characters 1 through 5
print(test_string[1:5])
input("ENTER TO CONTINUE")
#print everything after the 3rd character
print(test_string[3:])
input("ENTER TO CONTINUE")
#grab the last two characters from the
#string. Using a "-" means start at the
#end of the string.
print(test_string[-2:])
input("ENTER TO CONTINUE")
"""
###
#Task 2
###
"""
say1 = input("Say something:")
say2 = input("Say something:")

len3 = len(say1)
len4 = len(say2)

print("The first thing you typed is",len3,"characters long")
print("The second thing you typed is",len4,"characters long")
len5 = len3 + len4
int(len5)
print("Your two strings put together are:")
print(say1 + say2)
print("Program Complete")
"""
###
#Task 3
###

temp1 = int(input("Enter the starting time hour:"))
temp2 = int(input("Enter the starting time minute:"))
temp3 = int(input("Enter the duration:"))
end = (temp1*60) + temp2 + temp3
end2 = end//60
end2 = end2%12
if end2 == 0:
	end2 = 12
end3 = end%60
endstr =(str(end2),":",str(end3))
print(endstr)
 
	






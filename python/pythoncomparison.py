#[]--> list 
#{1,2,3}--> set 
#{key:value}--> dictionary

list = [1, 2, 3, 4, 5]
print(list)
#list comprehension use []
prim_num = [i for i in list if i % 2 != 0]
print(prim_num)

print()
#creating list of sequernce of numbers
seq_num = [i**2 for i in range(1, 4)]
print(seq_num)

#dic
my_dict = [{"Name":"Ambrish", "Age":22, "RollNo":123, "College":"ABC College"}]
print(my_dict)

#creating dictionary of sequence of numbers
my_dict2 = {i: i**2 for i in range(1, 10)}
print(my_dict2)

#set comprehension no 
# set==>duplicates and unordered
my_set = {1,2,3,4,5,6,1,2,3,4,5}
print(my_set) # remove the duplicates and print the unique values
result = {i**2 for i in my_set}
print(sorted(result))

#check comprehension vs generator expression



#[]--> list 
#{1,2,3}--> set 
#{key:value}--> dictionary

def printMyDist():
    students = [
                 {"Name": "ambrish","Age": 22,"RollNo": 123,"College": "ABC College"},
                 {"Name": "Ramesh", "Age": 23, "RollNo": 456, "College": "XYZ College"},
                 {"Name": "Suresh", "Age": 21, "RollNo": 789, "College": "PQR College"}
                ]
    

    #keys --returns the keys of the dictionary
    print("Keys:", list(students[0].keys()))
    #values --returns the values of the dictionary
    print("Values:", list(students[0].values()))
    #items --returns the key and value of the dictionary
    print("Items:", list(students[0].items()))     
    students[0]["Name"] = "Pandey"

    for student_id, student_info in students[0].items(): #items will return key and value of dictionary
        print(f"Student ID: {student_id}")
        for key, value in student_info[0].items():      
            print(f"{key}: {value}")
        print()  # Print a newline for better readability
    print(students)

def printMylist():
    mylist = [1,2,3,3,45,6,7,8,9]
    print(f"first element of this:{mylist[0]}")
    print(mylist[::-1])
    print(mylist)

    mydict = {1,2,2,3,4,5,6,7,8,9}
    print(mydict)

def printtuple():
    mytuple = (4,1,2,3,4,6,7,8,9)
    print(mytuple)

if __name__ == "__main__":
    printMyDist()
    printMylist()
    printtuple()



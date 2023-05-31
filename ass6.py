userdata=[
    ["user1", "user1@gmail.com",12],
    ["user2", "user2@gmail.com",15],
    ["user3", "user3@gmail.com",19],
    ["user3", "user3@gmail.com",19],
    ["user4", "user4@gmail.com",30],
    ["user5", "user5@gmail.com",-21],
    ["user6", "user6@gmail.com",67],
    ["user7", "user7@gmail.com",18],
    ["user8", "user8gmail.com",19]
]
user_dict={}
for user in userdata:
    try:
        if(user[0] in user_dict.keys()):
            raise Exception("The username is not unique for: " +user[0])
        elif(user[2] <0):
            raise Exception("The age is not a positive integer for: "+user[0])
        elif(user[2]<16):
            raise Exception("The user is under 16 for: "+user[0])
        elif '@' not in user[1] or '.com' not in user[1]:
            raise Exception("The email address is not valid for: "+user[0])
        else:
            user_dict[user[0]]= user[1]
    except Exception as e:
        print("Exception occured!!!",str(e))
        continue
print("\nValid users are: ")
print(user_dict)	 
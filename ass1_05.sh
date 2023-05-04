file="/etc/passwd"

echo "Enter the user login name:"
read user

user_info=$(grep "^${user}:" $file)

if [ -z "${user_info}" ];
then
    echo "User $user not found!"
    exit 0
fi

fields=(
    "Username"
    "Password"
    "User Id"
    "Group Id"
    "User Id Info"
    "Home Directory"
    "Login Shell"
)

echo -e "\nDetailed user login information of user $user:"

for i in {0..6}
do
    echo "${fields[$i]}: $(echo $user_info | cut -d ":" -f $[$i + 1])"
done
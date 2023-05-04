echo "Enter the basic salary:"
read basic
echo $basic

da=`expr $basic \* 30 / 100`
echo -e "\nDearness Allowance: $da"

hra=`expr $basic \* 25 / 100`
echo -e "\nHouse Rent Allowance: $hra"

net=$[$da + $hra + $basic]
echo -e "\nNet Salary: $net"

echo "Enter the five digit number:"
read num

echo $num

num1=num
rev=0

while [ $num -ne 0 ]
do
    rev=$[($rev * 10) + ($num % 10)]
    num=$[$num / 10]
done

echo -e "\nReverse of digits of $num1: $rev"

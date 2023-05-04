echo "Enter the five digit number:"
read num
echo $num

num1=num
sum=0

while [ $num -ne 0 ]
do
    sum=$[$sum + ($num % 10)]
    num=$[$num / 10]
done

echo -e "\nSum of digits of $num1: $sum"
files="num.txt"
while read -r line
do
	sum=0
	for num in $line
	do
		sum=$(( sum + num))
	done
	echo "Sum is $sum"
done <$files

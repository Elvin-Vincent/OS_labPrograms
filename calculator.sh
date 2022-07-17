echo "Enter the 1st number"
read n1
echo "Enter the 2nd number"
read n2

echo -e "Enter the option:\n +:Add\n -:Subtract\n x:Multiply\n /:Divide"
#echo "+ , - , x , /"
read op

case $op in
	+)ans=$((n1+n2))
	;;
	-)ans=$((n1-n2))
	;;
	x)ans=$((n1*n2))
	;;
	/)ans=$((n1/n2))
	;;
	*)echo "Invalid Operation"
	exit;;
esac

echo "Answer: $ans"
echo "Enter number:"
read num
cpy_num=$num
sum=0
rem=0
for((i=0;num!=0;i++))
do
	num=$((num/10))
done

num=$cpy_num
while [ $num -ne 0 ]
do
   	rem=$((num%10))
	sum=$((sum+(rem**i)))               
  	num=$((num/10))
done

if(($sum==$cpy_num))
then 	echo "The given number is an Armstrong number."
else
	echo "The given number is not an Armstrong number."
fi
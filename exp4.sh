echo "Enter the number:"
read num
fact=1

i=1
#while((i <= num))
while [ $i -le $num ]
do
    fact=$((fact * i))
    i=$((i+1))
done

#for((i=1; i<=num; i++)) 
#do
#   fact=$((fact * i))
#done

echo "The factorial of $num is $fact"
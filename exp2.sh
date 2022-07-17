echo "Enter the number:"
read num
if [ `expr $num % 2` -eq 0 ]
#if(($((num % 2)) == 0 ))
    then echo "Even"
else
    echo "Odd"
fi
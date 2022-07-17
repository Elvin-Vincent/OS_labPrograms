echo "Enter 1st number:"
read a
echo "Enter 2nd number:"
read b
echo "Enter 3rd number:"
read c
if(($a > $b && $a > $c))
    then echo "$a is largest"
elif(($b > $c))
    then echo "$b is largest"
else
    echo "$c is largest"
fi
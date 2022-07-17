echo "Enter the limit"
read lim
ini=0
fin=1
echo "The first $lim fibonacci series are:"
if(($lim == 1))
	then echo "$ini"
elif(($lim >= 2))
	then echo "$ini"
	echo "$fin"
fi
for((i=3; i<=lim; i++))
do
	next=$((ini + fin))
	echo "$next"
	ini=$fin
	fin=$next
done
g++ -std=c++11 ../main.cpp
for i in 1 2 3 4 5 6 7 8
do
	echo -e "\033[1m  Test Case $i \033[0m"
	echo    "  Our solution:      "
	cat     "in$i" | ./a.out
	echo    "  Provided solution: "
	cat     "out$i"
	echo    "----------------------------"
done
rm a.out

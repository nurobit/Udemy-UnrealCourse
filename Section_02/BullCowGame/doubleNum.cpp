#include <iostream>

int		doubleMe(int num)
{
	return (num * 2);
}

void	doubleNum()
{
	int num;

	num = 0;
	std::cout << "Please enter a number.\n";
	std::cin >> num;
	std::cout << "You entered " << num << '.' << '\n';
	std::cout << "I have doubled the value to " << doubleMe(num) << '\n';
}
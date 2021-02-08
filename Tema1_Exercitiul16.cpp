#include <iostream>

int Factorial_Recursiv(int numar)
{
	if (!numar)
	{
		return 1;
	}
	else
	{
		return numar * Factorial_Recursiv(numar - 1);
	}
}

int Factorial_Iterativ(int numar)
{
	int factorial = 1;

	for (int i = 1;i <= numar;i++)
	{
		factorial *= i;
	}

	return factorial;
}

int main()
{
	int numar;

	std::cout << "Introduceti numarul: ";
	std::cin >> numar;

	std::cout << Factorial_Recursiv(numar) << "\n";
	std::cout << Factorial_Iterativ(numar) << "\n";

	return 0;
}
#include <iostream>

void Farey(int n)
{
	double x, y = 0, x1 = 0, y1 = 1, x2 = 1, y2 = n;

	std::cout << "Sirul Farey de ordin " << n << " este: \n";
	std::cout << x1 << "/" << y1 << " " << x2 << "/" << y2;

	while (y != 1.0)
	{
		x = floor((y1 + n) / y2) * x2 - x1;
		y = floor((y1 + n) / y2) * y2 - y1;

		std::cout << " " << x << "/" << y;

		x1 = x2;
		x2 = x;
		y1 = y2;
		y2 = y;
	}

	std::cout << "\n";
}

int main()
{
	int n;

	std::cout << "Introduceti n:";
	std::cin >> n;

	Farey(n);

	return 0;
}
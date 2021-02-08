#include <iostream>

int Akerman(int m, int n)
{
	if (!m)
		return n + 1;
	else if (!n)
		return Akerman(m - 1, 1);
	else
		return Akerman(m - 1, Akerman(m, n - 1));
}

int main()
{
	int m, n;

	std::cout << "Introduceti m si n: ";
	std::cin >> m >> n;

	std::cout <<"A("<<m<<","<<n<<")= "<< Akerman(m, n) << std::endl;

	return 0;
}
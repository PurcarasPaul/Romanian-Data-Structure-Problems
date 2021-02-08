#include <iostream>
#include <vector>

void Perioada(int X, std::vector<int> vector_frecventa, int& ct)
{
	int Y = X * X;
	int X1 = Y;

	if (Y > 100)
	{
		X1 = 10 * ((Y / 100) % 10) + (Y / 10) % 10;
	}

	vector_frecventa[X1]++;

	if (vector_frecventa[X1] == 2)
	{
		ct++;
	}
	else if (vector_frecventa[X1] == 3)
	{
		std::cout << "Perioada este: " << ct << "\n\n";
		return;
	}

	Perioada(X1, vector_frecventa, ct);
}

void Perioada_Max_Min(int ct, int& perioada_maxima, int& perioada_minima)
{
	if (ct > perioada_maxima)
	{
		perioada_maxima = ct;
	}

	if (ct < perioada_minima)
	{
		perioada_minima = ct;
	}
}

int main()
{
	int perioada_maxima = 1, perioada_minima = 99;

	for (int i = 10;i <= 99;i++)
	{
		int ct = 0;
		std::vector<int> vector_frecventa(101);

		std::cout << "Numarul: " << i << "\n";
		Perioada(i, vector_frecventa, ct);
		Perioada_Max_Min(ct, perioada_maxima, perioada_minima);
	}

	std::cout << "Perioada maxima este: " << perioada_maxima << "\n";
	std::cout << "Perioada minima este: " << perioada_minima << "\n";

	return 0;
}
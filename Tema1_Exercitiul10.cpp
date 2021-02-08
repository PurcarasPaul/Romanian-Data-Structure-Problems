#include <iostream>
#include <vector>

void Citire(std::vector<int> &v_numere)
{
	int n;
	
	std::cout << "Introduceti numarul de coeficienti, n = ";
	std::cin >> n;

	for (int i = 0;i <= n;i++)
	{
		int temp;

		std::cout << "Introduceti numarul " << i + 1 << ": ";
		std::cin >> temp;

		v_numere.push_back(temp);
	}
}

int Polinoame(std::vector<int> v_numere, int x)
{
	int putere = x;
	int rezultat = v_numere[0];

	for (int i = 1;i < v_numere.size();i++)
	{
		rezultat += x * v_numere[i];
		x *= putere;
	}

	return rezultat;
}

int Polinoame_Horner(std::vector<int> v_numere, int x)
{
	int rezultat = v_numere[v_numere.size() - 1];

	for (int i = v_numere.size() - 2;i >= 0;i--)
	{
		rezultat =rezultat * x + v_numere[i];
	}

	return rezultat;
}

int main()
{
	int x;
	std::vector<int> v_numere;

	Citire(v_numere);

	std::cout << "Introduceti x = ";
	std::cin >> x;

	std::cout << "Metoda 1: " << Polinoame(v_numere, x) << "\n";
	std::cout << "Metoda 2: " << Polinoame_Horner(v_numere, x) << "\n";

	return 0;
}
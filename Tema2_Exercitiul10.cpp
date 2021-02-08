#include <iostream>
#include <vector>

class Permutare
{
	int size;
	std::vector<double> data;

public:
	Permutare(int elem)
	{
		size = elem;
	}

	void Citire()
	{
		for (int i = 0; i < size; i++)
		{
			int temp;

			std::cout << "Introduceti elementul " << i + 1 << "=";
			std::cin >> temp;

			data.push_back(temp);
		}
	}

	double PermArea()
	{
		double rezultat = 0, arie_temp = 0;
		int anterior = data[0];

		for (int i = 1; i < size; i++)
		{
			arie_temp = anterior + data[i];
			arie_temp /= 2;
			rezultat += arie_temp;
			anterior = data[i];
		}

		return rezultat;
	}
};

int main()
{
	int elem;

	std::cout << "Cerinta i)\n";
	
	std::cout << "Introduceti numarul de elemente:";
	std::cin >> elem;

	Permutare p1(elem);
	p1.Citire();
	std::cout << "Aria permutarii este: " << p1.PermArea() << "\n";

	/*	
		Cerinta 2
		Aria (Fp) este maxima pentru o permutare p atunci cand in extreme se afla cele mai mici valori,adica 1 si 2,
		deoarece valorile din extreme sunt calculate doar o data.
	*/

	return 0;
}
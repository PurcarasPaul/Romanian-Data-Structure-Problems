#include <iostream>
#include <vector>

class element {
public:
	int lin;
	int col;

	element()
	{
		lin = 0;
		col = 0;
	}

	element(int l, int c)
	{
		lin = l;
		col = c;
	}
};

class Matrice_Banda {
	int dimensiune, k, nr_elem;
	std::vector<element> data;
public:
	void Citire()
	{
		nr_elem = 0;
		std::cout << "Introduceti dimensiune matricii: ";
		std::cin >> dimensiune;
		std::cout << "Introduceti inaltimea benzii: ";
		std::cin >> k;

		int deasupra = 1, sub = 0;

		for (int banda = 0; banda < k; banda++)
		{
			if (banda % 2)
			{
				for (int i = sub; i < dimensiune; i++)
				{
					int lin_temp = i;
					int col_temp = i - sub;

					data.push_back({ lin_temp,col_temp });
					nr_elem++;
				}

				sub++;
			}
			else
			{
				for (int i = 0; i < dimensiune - deasupra; i++)
				{
					int lin_temp = i;
					int col_temp = i + deasupra;

					data.push_back({ lin_temp,col_temp });
					nr_elem++;
				}

				deasupra++;
			}
		}
	}

	void Tiparire()
	{
		std::cout << "\n";

		for (int i = 0; i < dimensiune; i++)
		{
			for (int j = 0; j < dimensiune; j++)
			{
				bool gasit = 0;

				for (int k = 0; k < nr_elem; k++)
					if ((data[k].lin == i) && (data[k].col == j))
					{
						std::cout << 1 << " ";
						gasit = 1;
						break;
					}

				if (!gasit)
				{
					std::cout << "0 ";
				}
			}

			std::cout << "\n";
		}

		std::cout << "\n";
	}
};

int main()
{
	Matrice_Banda M;
	M.Citire();
	M.Tiparire();

	return 0;
}
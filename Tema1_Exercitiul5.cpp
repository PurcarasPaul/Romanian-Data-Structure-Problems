#include <iostream>
#include <vector>

struct two
{
	int linie, coloana;
};

void Tiparire(std::vector<std::vector<int>> grid)
{
	std::cout << "\n";

	for (int i = 1;i < grid.size()-1;i++)
	{
		for (int j = 1;j < grid[i].size()-1;j++)
		{
			std::cout << grid[i][j];
		}
		std::cout << "\n";
	}

	std::cout << "\n";
}

void Bordura(std::vector<std::vector<int>>& grid)
{
	for (int i = 0;i < grid.size();i++)
	{
		for (int j = 0;j < grid[i].size();j++)
		{
			if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[i].size() - 1)
			{
				grid[i][j] = -1;
			}
		}
	}
}

void Citire(std::vector<std::vector<int>> &grid)
{
	int linii, coloane;

	std::cout << "Introduceti numarul de linii si coloane a careului: ";
	std::cin >> linii >> coloane;

	grid.resize(coloane + 2, std::vector<int>(linii + 2));

	Bordura(grid);
	Tiparire(grid);

	while(true)
	{
		int linie_celula_vie, coloana_celula_vie,alegere;

		std::cout << "Introduceti linia celulei vii: ";
		std::cin >> linie_celula_vie;

		std::cout << "Introduceti coloana celulei vii: ";
		std::cin>> coloana_celula_vie;

		grid[linie_celula_vie][coloana_celula_vie] = 1;

		system("cls");
		Tiparire(grid);

		std::cout << "1.Introduceti mai multe casute vii.";
		std::cout << "\n2.Rulati jocul.\n";

		std::cin >> alegere;

		if (alegere == 1)
		{
			continue;
		}
		else if (alegere == 2)
		{
			break;
		}
	}
}

int Decizie(int numar_vecini,int valoare)
{
	if (numar_vecini >= 4)
	{
		return false;
	}
	else if (numar_vecini <= 1)
	{
		return false;
	}
	else if (numar_vecini == 3)
	{
		return true;
	}
	else
	{
		return valoare;
	}
}

int Numarare_Vecini(std::vector<std::vector<int>> grid, int linie, int coloana)
{
	two directii[8] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
	int vecini = 0;

	for (int i = 0;i < 8;i++)
	{
		int linie_vecin = linie + directii[i].linie;
		int coloana_vecin = coloana + directii[i].coloana;

		if (grid[linie_vecin][coloana_vecin] == 1)
		{
			vecini++;
		}
	}

	return vecini;
}

void Joc(std::vector<std::vector<int>> &grid)
{
	system("cls");
	std::vector<std::vector<int>> grid2 = grid;

	for (int i = 1;i < grid.size() - 1;i++)
	{
		for (int j = 1;j < grid[i].size() - 1;j++)
		{
			int numar_vecini = Numarare_Vecini(grid, i, j);
			grid2[i][j] = Decizie(numar_vecini,grid[i][j]);
		}
	}

	grid = grid2;
}

int main()
{
	int alegere,generatie = 0;
	std::vector<std::vector<int>> grid;

	Citire(grid);

	do
	{
		Joc(grid);
		Tiparire(grid);

		generatie++;

		std::cout << "Generatia curenta este: " << generatie << "\n";
		std::cout << "1.Continuare\n2.Iesire\n";

		std::cin >> alegere;

	} while (alegere == 1);

	return 0;
}
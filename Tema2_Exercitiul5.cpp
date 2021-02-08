#include <iostream>
#include <vector>

bool Este_Symetric(std::vector<std::vector<int>> m_temp)
{
	for (int i = 0; i < m_temp.size(); i++)
	{
		for (int j = 0; j < m_temp[i].size(); j++)
		{
			if (m_temp[i][j] != m_temp[j][i])
			{
				return false;
			}
		}
	}

	return true;
}

bool Este_Reflexiv(std::vector<std::vector<int>> m_temp)
{
	for (int i = 0; i < m_temp.size(); i++)
	{
		if (!m_temp[i][i])
		{
			return false;
		}
	}

	return true;
}

bool Este_Tranzitiv(std::vector<std::vector<int>> m_temp)
{
	for (int i = 0; i < m_temp.size(); i++)
	{
		for (int j = 0; j < m_temp[i].size(); j++)
		{
			if (m_temp[i][j])
			{
				bool ok = false;

				for (int k = 0; k < m_temp.size(); k++)
				{
					if (m_temp[j][k] && k != i)
					{
						ok = true;
						break;
					}
				}

				if (!ok)
				{
					return false;
				}
			}
		}
	}

	return true;
}

void Rezultat(std::vector<std::vector<int>> m_temp)
{
	bool Rezultat = false;

	if (Este_Symetric(m_temp))
	{
		std::cout << "Relatia este simetrica\n";
		Rezultat = true;
	}

	if (Este_Reflexiv(m_temp))
	{
		std::cout << "Relatia este reflexiva\n";
		Rezultat = true;
	}

	if (Este_Tranzitiv(m_temp))
	{
		std::cout << "Relatia este tranzitiva\n";
		Rezultat = true;
	}

	if (!Rezultat)
	{
		std::cout << "Relatia nu este reflexiva,simetrica sau tranzitiva\n";
	}

	std::cout<< "\n";
}

void Citire(std::vector<std::vector<int>>& m_temp)
{
	int n;

	std::cout << "Dati dimensiunea matricii: ";
	std::cin >> n;

	std::cout << "Dati elementele matricii: \n\n";

	for (int i = 0; i < n; i++)
	{
		std::vector<int> v_temp;

		for (int j = 0; j < n; j++)
		{
			int temp;

			std::cout << "M[" << i + 1 << "][" << j + 1 << "]=";
			std::cin >> temp;

			v_temp.push_back(temp);
		}

		m_temp.push_back(v_temp);
	}

	std::cout << "\n";
}

int main()
{
	std::vector<std::vector<int>> M;

	Citire(M);
	Rezultat(M);

	return 0;
}
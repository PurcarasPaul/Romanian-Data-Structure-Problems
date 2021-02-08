#include <iostream>
#include <vector>

void Read(std::vector<std::vector<int>>& v_temp)
{
	int i_m, i_n;

	std::cout << "Introduceti m:";
	std::cin >> i_m;

	std::cout << "Introduceti n:";
	std::cin >> i_n;

	v_temp.resize(i_m, std::vector<int>(i_n));

	for (int i = 0;i < v_temp.size();i++)
	{
		for (int j = 0;j < v_temp[i].size();j++)
		{
			std::cout << "M[" << i + 1 << "][" << j + 1 << "]=";
			std::cin >> v_temp[i][j];
		}
	}

	std::cout << "\n";
}

void Print(std::vector<std::vector<int>> v_temp)
{
	for (int i = 0;i < v_temp.size();i++)
	{
		for (int j = 0;j < v_temp[i].size();j++)
		{
			std::cout << v_temp[i][j] << " ";
		}

		std::cout << "\n";
	}

	std::cout << "\n";
}

void Reverse(std::vector<std::vector<int>> &v_temp, int i, int j, int k)
{
	while (v_temp[i].size() - 1 >= k && v_temp[i].size() - 1 >= j)
	{
		v_temp[i][k] += v_temp[i][j];
		v_temp[i][j] = v_temp[i][k] - v_temp[i][j];
		v_temp[i][k] -= v_temp[i][j];

		j++;
		k++;
	}
}

int Find_one(std::vector<std::vector<int>> v_temp, int i ,int j)
{
	for (j;j < v_temp[i].size();j++)
	{
		if (v_temp[i][j])
		{
			return j;
		}
	}

	return -1;
}

void Cerinta_ii(std::vector<std::vector<int>>& v_temp)
{
	for (int i = 0;i < v_temp.size();i++)
	{
		for (int j = 0;j < v_temp[i].size();j++)
		{
			if (!v_temp[i][j])
			{
				int k = Find_one(v_temp, i ,j+1);
				
				if (k >= 0)
				{
					Reverse(v_temp, i, j, k);
				}
			}
		}
	}
}

int main()
{
	std::vector<std::vector<int>> M;

	Read(M);
	Print(M);

	int i, j, k;
	std::cout << "Cerinta i.\n";
	std::cout << "Introduceti i,j si k:";
	std::cin >> i >> j >> k;

	Reverse(M,i,j,k);
	Print(M);

	std::cout << "Cerinta ii.\n";
	Cerinta_ii(M);
	Print(M);

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int Rezolvare(std::vector<int> v_temp1, std::vector<int> v_temp2)
{
	if (v_temp1.size() != v_temp2.size())
	{
		if (v_temp1.size() < v_temp2.size())
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		for (int i = 0;i < v_temp1.size();i++)
		{
			if (v_temp1[i] < v_temp2[i])
			{
				return 1;
			}
			else if(v_temp1[i] > v_temp2[i])
			{
				return -1;
			}
		}
		return 0;
	}
}

void Tiparire(std::vector<int> v_temp)
{
	for (int i = 0;i < v_temp.size();i++)
	{
		std::cout << v_temp[i] << " ";
	}

	std::cout << "\n";
}

void Citire(std::vector<int>& v_temp,char c_temp)
{
	int nr_elem;
	std::cout << "Introduceti numar elemente pentru lista "<<(char)toupper(c_temp)<<":";
	std::cin >> nr_elem;

	for (int i = 0;i < nr_elem;i++)
	{
		int temp;

		std::cout << "Introduceti " << c_temp << i + 1 << "=";
		std::cin >> temp;

		v_temp.push_back(temp);
	}

	std::cout << "\n";
}

int main()
{
	std::vector<int> A, B;

	Citire(A,'a');
	Citire(B,'b');

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	Tiparire(A);
	Tiparire(B);

	std::cout << "\nRezultatul este: " << Rezolvare(A, B) << "\n\n";

	return 0;
}
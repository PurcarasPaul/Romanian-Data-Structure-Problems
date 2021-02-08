#include <iostream>
#include <vector>
#include <algorithm>

int MatrixDet(std::vector<std::vector<int>> A)
{
    int num1, num2, k, det = 1, total = 1, n = A.size();
    std::vector<int> temp(n + 1);

    A.push_back(std::vector<int>(A.size()));

    for (int i = 0; i < n; i++)
    {
        k = i;

        while (!A[k][i] && k < n)
        {
            k++;
        }

        if (k == n)
        {
            continue;
        }

        if (k != i)
        {
            for (int j = 0; j < n; j++)
            {
                std::swap(A[k][j], A[i][j]);
            }

            det *= pow(-1, k - i);
        }

        for (int j = 0; j < n; j++)
        {
            temp[j] = A[i][j];
        }

        for (int j = i + 1; j < n; j++)
        {
            num1 = temp[i];
            num2 = A[j][i];

            for (int k = 0; k < n; k++)
            {
                A[j][k] = (num1 * A[j][k]) - (num2 * temp[k]);
            }

            total *= num1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        det *= A[i][i];
    }

    return (det / total);
}

void Print(std::vector<std::vector<int>> A)
{
	for (int i = 0;i < A.size();i++)
	{
		for (int j = 0;j < A[i].size();j++)
		{
			std::cout << A[i][j] << " ";
		}

		std::cout << "\n";
	}
	
	std::cout << "\n";
}

void Read(std::vector<std::vector<int>> &A)
{
	int n;
	
	std::cout << "Introduceti ordinul n al Matricii:";
	std::cin >> n;

	std::cout << "\n";

	for (int i = 0;i < n;i++)
	{
		std::vector<int> v_temp;

		for (int j = 0;j < n;j++)
		{
			int temp;

			std::cout << "Introduceti A[" << i+1 << "][" << j+1 << "]=";
			std::cin >> temp;

			v_temp.push_back(temp);
		}

		A.push_back(v_temp);
	}

	std::cout << "\n";
}

int main()
{
	std::vector<std::vector<int>> A;

	Read(A);
	Print(A);
	std::cout << "Determinantul Matricii A este:" << MatrixDet(A) << "\n";

	return 0;
}
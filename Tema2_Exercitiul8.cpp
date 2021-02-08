#include <iostream>
#include <vector>
#include <algorithm>

struct polinom
{
	double grad, coef;
};

bool Sorting_Method(polinom a, polinom b)
{
	return (a.grad > b.grad);
}

std::vector<polinom> adPol(std::vector<polinom> p1,std::vector<polinom> p2)
{
	std::vector<polinom> data(p1.size());

	for (int i = 0;i < p1.size();i++)
		data[i] = p1[i];
	for (int j = 0;j < p2.size();j++)
	{
		int ok = 0;
		for (int i = 0;i < data.size();i++)
		{
			if (data[i].grad == p2[j].grad)
			{
				data[i].coef += p2[j].coef;
				ok = 1;
			}
		}
		if (ok == 0)
		{
			data.push_back(p2[j]);
		}
	}

	int k = 0;
	while (k != data.size())
	{
		if (data[k].coef == 0)
		{
			data.erase(data.begin() + k);
			k = 0;
		}
		k++;
	}

	return data;
}

std::vector<polinom> Calcul_CMMDC(std::vector<polinom> &p1, std::vector<polinom> &p2)
{
	std::vector<polinom> rezultat;

	do
	{
		std::vector<polinom> rest(p1.size());
		int i = 0;

		while (p1[0].grad >= p2[0].grad)
		{
			rest[i].grad = p1[0].grad - p2[0].grad;
			rest[i].coef = p1[0].coef / p2[0].coef;

			std::vector<polinom> temp(p2.size());
			for (int j = 0;j < p2.size();j++)
			{
				temp[j].grad = rest[i].grad + p2[j].grad;
				temp[j].coef = -(rest[i].coef * p2[j].coef);
			}

			p1 = adPol(p1, temp);
			sort(p1.begin(), p1.end(), Sorting_Method);

			int k = 0;
			while(k != p1.size())
			{
				if (p1[k].coef == 0)
				{
					p1.erase(p1.begin() + k);
					k = 0;
				}
				k++;
			}

			i++;
		}

		rest = p1;
		p1 = p2;
		p2 = rest;

		if (rest[0].coef)
		{
			rezultat = rest;
		}

	} while (!p2[0].coef);

	return rezultat;
}

void Print(std::vector<polinom> p)
{
	if (p.size() == 1)
	{
		std::cout << p[0].coef << "X^" << p[0].grad;
		std::cout << "\n\n";
		return;
	}

	for (int i = 0;i < p.size() ;i++)
	{
		if (p[i].coef != 0)
		{
			if (i == p.size() - 1)
			{
				std::cout << p[i].coef << "X^" << p[i].grad;
			}
			else
			{
				std::cout << p[i].coef << "X^" << p[i].grad << " + ";
			}
		}
	}

	std::cout << "\n\n";
}

void Read(std::vector<polinom> &p)
{
	int elem;

	std::cout << "Introduceti numarul de elemente din polinom:";
	std::cin >> elem;

	for (int i = 0;i < elem;i++)
	{
		double grad_temp, coef_temp;
		p.push_back(polinom());

		std::cout << "Introduceti grad:";
		std::cin >> grad_temp;
		p[i].grad = grad_temp;

		std::cout << "Introduceti coeficient:";
		std::cin >> coef_temp;
		p[i].coef = coef_temp;
	}
	p.push_back(polinom());
	p[p.size() - 1].coef = 0;

	sort(p.begin(), p.end(), Sorting_Method);

	std::cout << "\n";
}

int main()
{
	std::vector<polinom> P, Q, CMMDC;
	
	Read(P);
	Print(P);

	Read(Q);
	Print(Q);

	CMMDC = Calcul_CMMDC(P, Q);
	Print(CMMDC);

	return 0;
}
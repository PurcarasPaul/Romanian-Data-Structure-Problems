#include <iostream>

void Tiparire(char numar[], int ct_cifre)
{
	std::cout << "\nRezultatul este: \n";

	for (int i = ct_cifre - 1;i >= 0;i--)
	{
		std::cout << numar[i];
	}

	std::cout << "\n\n";
}

int Determinare_Numar_Cifre(char numar[])
{
	int cifre = 0;

	while (numar[cifre] != 'Ì')
	{
		cifre++;
	}

	return cifre;
}

void Calcul(char numar[], int putere)
{
	numar[0] = '2';

	for (int i = 0;i < putere - 1;i++)
	{
		int j = 0, rest = 0, ct_cifre = 0;

		while (numar[j] != 'Ì' || rest)
		{
			if (numar[j] == 'Ì')
			{
				numar[j] = rest + '0';
				break;
			}

			int cifra = (numar[j] - '0') * 2 + rest;

			numar[ct_cifre++] = (cifra % 10) + '0';
			rest = cifra / 10;

			j++;
		}
	}
}

int main()
{
	int putere, cifre;
	char numar[10002];

	std::cout << "Introduceti puterea: ";
	std::cin >> putere;

	Calcul(numar, putere);
	cifre = Determinare_Numar_Cifre(numar);
	Tiparire(numar, cifre);

	return 0;
}
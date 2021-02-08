#include <iostream>

#define MAX_SIZE 1001

template <class T>
class DoubleStack
{
	int top_A = 0, top_B = MAX_SIZE - 1;

public:
	T AB[MAX_SIZE];

	void PushA(T value)
	{
		if (top_A + 1 == top_B - 1)
		{
			std::cout << "Limita atinsa,nu s-a efectuat adaugarea.\n";
		}
		else
		{
			AB[top_A++] = value;
		}
	}

	void PushB(T value)
	{
		if (top_A + 1 == top_B - 1)
		{
			std::cout << "Limita atinsa,nu s-a efectuat adaugarea.\n";
		}
		else
		{
			AB[top_B--] = value;
		}
	}

	int PopA()
	{
		if (top_A >= 0)
		{
			return AB[--top_A];
		}
		else
		{
			std::cout << "Stiva este goala.\n";
		}
	}

	int PopB()
	{
		if (top_B < MAX_SIZE - 1)
		{
			return AB[++top_B];
		}
		else
		{
			std::cout << "Stiva este goala.\n";
		}
	}

	void Read()
	{
		T elem;
		
		std::cout << "Introduceti numarul de elemente din Stiva A:";
		std::cin >> elem;

		for (int i = 0;i < elem;i++)
		{
			T temp;

			std::cout << "Elementul cu numarul " << i + 1 << "=";
			std::cin >> temp;

			PushA(temp);
		}

		std::cout << "\nIntroduceti numarul de elemente din Stiva B:";
		std::cin >> elem;

		for (int i = MAX_SIZE - 1;i >= MAX_SIZE - elem;i--)
		{
			T temp;

			std::cout << "Elementul cu numarul " << i + 1 << "=";
			std::cin >> temp;
			
			PushB(temp);
		}
	}

	void PrintA()
	{
		std::cout << "\nStiva A:\n";

		for (int i = top_A - 1;i >= 0;i--)
		{
			std::cout << AB[i] << "\n";
		}
	}

	void PrintB()
	{
		std::cout << "\nStiva B:\n";

		for (int i = top_B + 1;i < MAX_SIZE;i++)
		{
			std::cout << AB[i] << "\n";
		}
	}
};

int main()
{
	DoubleStack<int> Double_Stack_AB;

	Double_Stack_AB.Read();
	Double_Stack_AB.PrintA();
	Double_Stack_AB.PrintB();

	std::cout << "\nElementul extras din stiva A este:" << Double_Stack_AB.PopA();
	std::cout << "\nElementul extras sin stiva A este:" << Double_Stack_AB.PopA();
	Double_Stack_AB.PrintA();

	std::cout << "\nElementul extras din stiva B este:" << Double_Stack_AB.PopB();
	std::cout << "\nElementul extras din stiva B este:" << Double_Stack_AB.PopB();
	Double_Stack_AB.PrintB();

	return 0;
}	
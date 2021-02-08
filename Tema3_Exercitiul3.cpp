#include <iostream>

class Stack
{
	int i_value;
	Stack* pstack_next;

public:
	Stack* pstack_top;

	Stack()
	{
		i_value = 0;
		pstack_next = NULL;
		pstack_top = NULL;
	}

	void Read()
	{
		int i_temp_number;
		std::cout << "Introduceti numarul:";
		std::cin >> i_temp_number;
		std::cout << "\n";

		Push(i_temp_number);
	}

	void Push(int i_value_temp)
	{
		Stack* pstack_temp = new Stack();
		pstack_temp->i_value = i_value_temp;
		pstack_temp->pstack_next = pstack_top;
		pstack_top = pstack_temp;
	}

	void Print_Divisors()
	{
		std::cout << "Divizorii primi ai numarului "<<pstack_top->i_value<<" sunt:\n";

		pstack_top = pstack_top->pstack_next;
		while (pstack_top != NULL)
		{
			std::cout << pstack_top->i_value << "\n";
			pstack_top = pstack_top->pstack_next;
		}

		std::cout << "\n";
	}

	void Find_All_Prime_Divisors()
	{
		int i_number = pstack_top->i_value;

		for (int i = 2;i <= i_number / 2;i++)
		{
			if (!(i_number % i) && isPrime(i))
			{
				this->Push(i);
			}
		}
	}

	bool isPrime(int i_number_temp)
	{
		for (int i = 2;i <= i_number_temp / 2;i++)
		{
			if (!(i_number_temp % i))
			{
				return false;
			}
		}

		return true;
	}

	void Reverse_Stack()
	{
		Stack pstack_temp;
		while (pstack_top != NULL)
		{
			pstack_temp.Push(pstack_top->i_value);
			pstack_top = pstack_top->pstack_next;
		}

		pstack_top = pstack_temp.pstack_top;
	}

};

int main()
{
	Stack Stack1;
	
	Stack1.Read();

	Stack1.Find_All_Prime_Divisors();
	Stack1.Reverse_Stack();
	Stack1.Print_Divisors();

	return 0;
}
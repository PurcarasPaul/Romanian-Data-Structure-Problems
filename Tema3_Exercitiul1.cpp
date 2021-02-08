#include <iostream>

class Stack
{
	int value;
	Stack* next;

public:
	Stack* top = NULL;

	void Push(int val)
	{
		Stack* temp_stack = new Stack();
		temp_stack->value = val;
		temp_stack->next = top;
		top = temp_stack;
	}

	void Print()
	{
		Stack* temp = top;

		std::cout << "\nStiva este urmatoarea:\n";

		while (temp != NULL)
		{
			std::cout << temp->value << "\n";
			temp = temp->next;
		}
	}

	int Pop()
	{
		int popped_value = top->value;
		top = top->next;
		return popped_value;
	}

	bool isEmpty()
	{
		if (top == NULL)
		{
			return true;
		}
		return false;
	}

	void Citire()
	{
		int elem;

		std::cout << "Introduceti numarul de elemente:";
		std::cin >> elem;

		for (int i = 0;i < elem;i++)
		{
			int temp;

			std::cout << "Elementul cu numarul " << i + 1 << "=";
			std::cin >> temp;

			this->Push(temp);
		}

	}

	void Cerinta_a(int& x_temp)
	{
		if (isEmpty())
		{
			x_temp = INT_MAX;
		}
		else
		{
			x_temp = top->value;
		}
	}

	int Count_Elements()
	{
		int elements = 0;
		Stack* temp = top;
		while (temp != NULL)
		{
			temp = temp->next;
			elements++;
		}

		return elements;
	}

	void Cerinta_b(int& x_temp)
	{
		if (Count_Elements() >= 3)
		{
			x_temp = top->next->next->value;
		}
		else
		{
			x_temp = INT_MAX;
		}
	}

	void Cerinta_c(int& x_temp)
	{
		if (isEmpty())
		{
			x_temp = INT_MAX;
		}
		else
		{
			Stack* stack_temp = top;

			while (stack_temp->next != NULL)
			{
				stack_temp = stack_temp->next;
			}

			x_temp = stack_temp->value;
		}
	}

	void Cerinta_d(int x)
	{
		Stack stack_temp;

		while (top != NULL)
		{
			if (top->value == x)
			{
				top = top->next;
			}
			else
			{
				stack_temp.Push(top->value);
				top = top->next;
			}
		}

		while (stack_temp.top != NULL)
		{
			Push(stack_temp.top->value);
			stack_temp.top = stack_temp.top->next;
		}
	}
};

int main()
{
	int x;
	Stack S;

	S.Citire();
	S.Print();

	S.Cerinta_a(x);
	std::cout << "\nCerinta a:\n";
	std::cout << "x=" << x << "\n";

	S.Cerinta_b(x);
	std::cout << "\nCerinta b:\n";
	std::cout << "x=" << x << "\n";

	S.Cerinta_c(x);
	std::cout << "\nCerinta c:\n";
	std::cout << "x=" << x << "\n";

	std::cout << "\nIntroduceti valoarea lui x pentru cerinta d:";
	std::cin >> x;
	S.Cerinta_d(x);
	std::cout << "Cerinta d:";
	S.Print();

	std::cout << "\n";

	return 0;
}
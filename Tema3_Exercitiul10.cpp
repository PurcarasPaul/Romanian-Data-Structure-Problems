#include <iostream>
#include <vector>
#include <string>

class Stack
{
	char c_color = NULL;
	Stack* pstack_next = NULL;

public:
	Stack* pstack_top;

	Stack()
	{
		pstack_top = NULL;
	}

	Stack(char c_temp_color)
	{
		pstack_top = NULL;
		c_color = c_temp_color;
	}

	void Push(char c_temp_color)
	{
		Stack* pstack_temp = new Stack;
		pstack_temp->c_color = c_temp_color;
		pstack_temp->pstack_next = pstack_top;
		pstack_top = pstack_temp;
	}

	char Pop()
	{
		char c_temp_color = pstack_top->c_color;

		pstack_top = pstack_top->pstack_next;

		return c_temp_color;
	}
};

void Read(std::vector<Stack> &vstack_temp_Tije)
{
	int i_n;

	std::cout << "Introduceti n:";
	std::cin >> i_n;

	std::cout << "\n";

	for (int i = 0;i < i_n;i++)
	{
		std::string s_temp_color;

		std::cout << "Introduceti culoarea:";
		std::cin >> s_temp_color;

		Stack stack_temp(s_temp_color[0]);
		for (int i = 0;i < i_n;i++)
		{
			stack_temp.Push(s_temp_color[0]);
		}

		vstack_temp_Tije.push_back(stack_temp);
	}

	vstack_temp_Tije.push_back(Stack());

	std::cout << "\n";
}

void Print(std::vector<Stack> vstack_temp_Tije)
{
	std::cout << "Stivele sunt:\n";

	for (int i = 0;i < vstack_temp_Tije.size();i++)
	{
		for (int j = 0;j < vstack_temp_Tije.size() - 1;j++)
		{
			if (vstack_temp_Tije[j].pstack_top)
			{
				std::cout << vstack_temp_Tije[j].Pop() << " ";
			}
		}

		std::cout << "\n";
	}
}

void Solution(std::vector<Stack>& vstack_temp_Tije)
{
	int i_last_stack = vstack_temp_Tije.size() - 1;

	for (int i = 0;i < vstack_temp_Tije.size() - 1;i++)
	{
		for (int j = 0;j < vstack_temp_Tije.size() - 2;j++)
		{
			vstack_temp_Tije[i_last_stack].Push(vstack_temp_Tije[i].Pop());
		}
	}

	int i = 0;
	while (vstack_temp_Tije[i_last_stack].pstack_top != NULL)
	{
		if (i == vstack_temp_Tije.size())
		{
			i = 0;
		}

		vstack_temp_Tije[i].Push(vstack_temp_Tije[i_last_stack].Pop());
		i++;
	}
}

int main()
{
	std::vector<Stack> Tije;

	Read(Tije);
	Print(Tije);

	Solution(Tije);
	Print(Tije);

	return 0;
}
#include <iostream>
#include <string>

class Stack
{
	std::string s_value;
	Stack* ps_next = NULL;

public:
	Stack* ps_top = NULL;

	void Push(std::string s_temp)
	{
		Stack* ps_temp = new Stack;
		ps_temp->s_value = s_temp;
		ps_temp->ps_next = ps_top;
		ps_top = ps_temp;
	}

	bool isOperator(char c_temp)
	{
		switch (c_temp)
		{
		case '+':
		case '-':
		case '/':
		case '*':
			return true;
		}

		return false;
	}

	std::string Pop()
	{
		std::string s_temp = ps_top->s_value;
		ps_top = ps_top->ps_next;

		return s_temp;
	}

	std::string Solution()
	{
		std::string s_expression, s_temp;

		std::cout << "Introduceti expresia prefixata:";
		std::cin >> s_expression;

		for (int i = s_expression.length() - 1;i >= 0;i--)
		{
			if (!isOperator(s_expression[i]))
			{
				Push(std::string(1, s_expression[i]));
			}
			else
			{
				s_temp = Pop();
				s_temp += Pop() + s_expression[i];
				Push(s_temp);
			}
		}

		return s_temp;
	}
};

int main()
{
	Stack Stack1;

	std::cout << "Expresia postfixata este:" << Stack1.Solution() << "\n";

	return 0;
}
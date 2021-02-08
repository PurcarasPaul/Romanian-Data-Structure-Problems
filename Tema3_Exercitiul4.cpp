#include <iostream>
#include <vector>

template <class T>
class Stack
{
	T T_value;
	Stack* pstack_next = NULL;

public:
	Stack* pstack_top = NULL;

	void Push(T T_temp_value)
	{
		Stack* pstack_temp = new Stack();
		pstack_temp->T_value = T_temp_value;
		pstack_temp->pstack_next = pstack_top;
		pstack_top = pstack_temp;
	}

	T Pop()
	{
		T T_temp_value = pstack_top->T_value;

		pstack_top = pstack_top->pstack_next;

		return T_temp_value;
	}

	void Print()
	{
		std::cout << "\n";

		while (pstack_top)
		{
			std::cout << pstack_top->T_value << "\n";
			pstack_top = pstack_top->pstack_next;
		}
	}

	bool Verify(int i_pos, std::vector<int> v_answer)
	{
		for (int i = 0;i < i_pos;i++)
		{
			if (v_answer[i] == v_answer[i_pos])
			{
				return false;
			}
		}

		return true;
	}

	int VectorToInt(std::vector<int> v_temp)
	{
		reverse(v_temp.begin(), v_temp.end());
		int i_decimal = 1, i_total = 0;

		for (auto& it : v_temp)
		{
			i_total += it * i_decimal;
			i_decimal *= 10;
		}

		return i_total;
	}

	void bkt(int i_pos, std::vector<int> v_answer,std::vector<int> v_nums)
	{
		if (i_pos == v_nums.size())
		{
			Push(VectorToInt(v_answer));
		}
		else
		{
			for (int i = 0;i < v_nums.size();i++)
			{
				v_answer[i_pos] = v_nums[i];

				if (Verify(i_pos, v_answer) == 1)
				{
					bkt(i_pos + 1, v_answer, v_nums);
				}
			}
		}
	}

	void Read()
	{
		int i_n;
		std::vector<int> v_temp;

		std::cout << "Introduceti n:";
		std::cin >> i_n;

		for (int i = 1;i <= i_n;i++)
		{
			Push(i);
			v_temp.push_back(i);
		}

		std::vector<int> v_answer(v_temp.size());

		bkt(0, v_answer, v_temp);
	}

};

int main()
{
	Stack<int> Stack1;

	Stack1.Read();
	Stack1.Print();

	std::cout << "\n";

	return 0;
}
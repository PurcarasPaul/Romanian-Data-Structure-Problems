#include <iostream>

template <class T>
class Stack
{
	T T_value = NULL;
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
		T t_temp_value = pstack_top->T_value;
		pstack_top = pstack_top->pstack_next;

		return t_temp_value;
	}

	template <class T>
	friend class Queue;
};

template <class T>
class Queue
{
public:
	Stack<int> S1, S2;

	//O(N)
	void EnQueue(T T_temp_value)
	{
		while (S2.pstack_top)
		{
			S1.Push(S2.Pop());
		}

		S1.Push(T_temp_value);
	}

	//O(N)
	void DeQueue()
	{
		if (!S1.pstack_top && !S2.pstack_top)
		{
			std::cout << "\nCoada este goala\n";
		}
		else if (!S2.pstack_top)
		{
			while (S1.pstack_top)
			{
				S2.Push(S1.Pop());
			}
		}

		if (S2.pstack_top)
		{
			S2.Pop();
		}
	}

	void Read()
	{
		int i_elem;

		std::cout << "Introduceti numarul de elemente din coada:";
		std::cin >> i_elem;

		for (int i = 0;i < i_elem;i++)
		{
			int i_temp_value;

			std::cout << "Elementul cu numarul " << i + 1 << " :";
			std::cin >> i_temp_value;

			EnQueue(i_temp_value);
		}

	}

	//O(N)
	void Print()
	{
		if (!S1.pstack_top && !S2.pstack_top)
		{
			std::cout << "\nCoada este goala\n";
		}
		else
		{
			while (S1.pstack_top)
			{
				S2.Push(S1.Pop());
			}
		}

		Stack<T>* pstack_temp = S2.pstack_top;

		if (pstack_temp)
		{
			std::cout << "\nCoada este:\n";
			while (pstack_temp)
			{
				std::cout << pstack_temp->T_value << "\n";
				pstack_temp = pstack_temp->pstack_next;
			}
		}
	}
};

int main()
{
	Queue<int> Q;

	Q.Read();
	Q.Print();

	Q.DeQueue();
	Q.Print();

	Q.EnQueue(5);
	Q.EnQueue(6);
	Q.EnQueue(7);

	Q.Print();
	Q.DeQueue();
	Q.Print();

	std::cout << "\n";

	return 0;
}
#include <iostream>

template <class T>
class Stack
{
	Stack* pstack_next = NULL;

public:
	T T_value = NULL;
	Stack* pstack_top = NULL;

	void Push(T T_temp_value)
	{
		Stack* pstack_temp = new Stack();
		pstack_temp->T_value = T_temp_value;
		pstack_temp->pstack_next = pstack_top;
		pstack_top = pstack_temp;
	}

	void Pop()
	{
		pstack_top = pstack_top->pstack_next;
	}

	void Print()
	{
		Stack* pstack_temp = pstack_top;

		while (pstack_temp)
		{
			std::cout << pstack_temp->T_value << "\n";
			pstack_temp = pstack_temp->pstack_next;
		}

		std::cout << "\n";
	}

	void Read()
	{
		int i_elem;

		std::cout << "Introduceti numarul de elemente din stiva:";
		std::cin >> i_elem;

		for (int i = 0;i < i_elem;i++)
		{
			int i_temp;

			std::cout << "Introduceti elementul " << i + 1 << " :";
			std::cin >> i_temp;

			Push(i_temp);
		}

		std::cout << "\n";
	}
};

template <class T>
class Queue
{
	T T_value = NULL;
	Queue* pqueue_next = NULL;

public:
	Queue* pqueue_front = NULL;
	Queue* pqueue_rear = NULL;

	void EnQueue(T T_temp_value)
	{
		Queue* pqueue_temp = new Queue;
		pqueue_temp->T_value = T_temp_value;

		if (!pqueue_front)
		{
			pqueue_front = pqueue_rear = pqueue_temp;
		}
		else
		{
			pqueue_rear->pqueue_next = pqueue_temp;
			pqueue_rear = pqueue_temp;
		}
	}

	void Print()
	{
		Queue* pqueue_temp = pqueue_front;

		std::cout << "Coada este:\n";
		while (pqueue_temp)
		{
			std::cout << pqueue_temp->T_value << "\n";
			pqueue_temp = pqueue_temp->pqueue_next;
		}

		std::cout << "\n";
	}
};

template <class T>
void Solution(Queue<T> &queue_temp,Stack<T> stack1_temp,Stack<T> stack2_temp)
{
	while (stack1_temp.pstack_top || stack2_temp.pstack_top)
	{
		if (stack1_temp.pstack_top && stack2_temp.pstack_top)
		{
			if (stack1_temp.pstack_top->T_value <= stack2_temp.pstack_top->T_value)
			{
				queue_temp.EnQueue(stack1_temp.pstack_top->T_value);
				stack1_temp.Pop();
			}
			else
			{
				queue_temp.EnQueue(stack2_temp.pstack_top->T_value);
				stack2_temp.Pop();
			}
		}
		else if(stack1_temp.pstack_top)
		{
			queue_temp.EnQueue(stack1_temp.pstack_top->T_value);
			stack1_temp.Pop();
		}
		else
		{
			queue_temp.EnQueue(stack2_temp.pstack_top->T_value);
			stack2_temp.Pop();
		}
	}
}

int main()
{
	Stack<int> S1, S2;
	Queue<int> Q;

	S1.Read();
	S2.Read();

	std::cout << "Stiva S1 este:\n";
	S1.Print();

	std::cout << "Stiva S2 este:\n";
	S2.Print();

	Solution(Q, S1, S2);
	Q.Print();

	return 0;
}
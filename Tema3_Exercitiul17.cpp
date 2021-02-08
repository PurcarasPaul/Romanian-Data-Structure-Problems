#include <iostream>

template <class T>
class Queue
{
	T T_value = NULL;
	Queue* pqueue_next = NULL;
	Queue* pqueue_prev = NULL;

public:
	Queue* pqueue_front = NULL;
	Queue* pqueue_rear = NULL;

	void EnQueue(T T_temp_value)
	{
		Queue* pqueue_temp = new Queue;
		pqueue_temp->T_value = T_temp_value;

		if (!pqueue_front || !pqueue_rear)
		{
			pqueue_front = pqueue_rear = pqueue_temp;
		}
		else
		{
			pqueue_rear->pqueue_next = pqueue_temp;
			pqueue_temp->pqueue_prev = pqueue_rear;
			pqueue_rear = pqueue_temp;
		}
	}

	T DeQueue_Rear()
	{
		T T_temp_value = pqueue_rear->T_value;
		pqueue_rear = pqueue_rear->pqueue_prev;

		return T_temp_value;
	}

	void DeQueue_Front()
	{
		pqueue_front = pqueue_front->pqueue_next;
	}

	template <class T>
	friend class Stack;
};

template <class T>
class Stack
{
public:
	Queue<T> Queue1, Queue2;

	void Push(T T_temp_value)
	{
		while (Queue2.pqueue_rear)
		{
			Queue1.EnQueue(Queue2.DeQueue_Rear());
		}

		Queue1.EnQueue(T_temp_value);
	}

	void Pop()
	{
		if (!Queue1.pqueue_front && !Queue2.pqueue_front)
		{
			std::cout << "Stiva este goala\n";
		}
		else
		{
			while (Queue1.pqueue_rear)
			{
				Queue2.EnQueue(Queue1.DeQueue_Rear());
				Queue1.DeQueue_Front();
			}
		}

		if (Queue2.pqueue_front)
		{
			Queue2.DeQueue_Front();
		}
	}

	void Read()
	{
		int i_elem;

		std::cout << "Introduceti numarul de elemente din stiva:";
		std::cin >> i_elem;

		for (int i = 0;i < i_elem;i++)
		{
			int i_temp_value;

			std::cout << "Elementul cu numarul " << i + 1 << " :";
			std::cin >> i_temp_value;

			Push(i_temp_value);
		}

	}

	void Print()
	{
		if (!Queue1.pqueue_front && !Queue2.pqueue_front)
		{
			std::cout << "Stiva este goala\n";
		}
		else
		{
			while (Queue1.pqueue_rear)
			{
				Queue2.EnQueue(Queue1.DeQueue_Rear());
				Queue1.DeQueue_Front();
			}
		}

		Queue<T>* pqueue_temp = Queue2.pqueue_front;

		std::cout << "\nStiva este:\n";
		while (pqueue_temp)
		{
			std::cout << pqueue_temp->T_value << "\n";
			pqueue_temp = pqueue_temp->pqueue_next;
		}
	}
};

int main()
{
	Stack<int> Stack1;

	Stack1.Read();
	Stack1.Print();

	Stack1.Pop();
	Stack1.Print();

	Stack1.Push(4);
	Stack1.Push(5);

	Stack1.Print();
	Stack1.Pop();
	Stack1.Print();

	std::cout << "\n";

	return 0;
}
#include <iostream>

template <class T>
class List
{
	T T_value = NULL;
	List* plist_next = NULL;
	List* plist_prev = NULL;
	List* plist_front = NULL;
	List* plist_rear = NULL;
public:

	void Push(T T_temp_value)
	{
		List* plist_temp = new List();
		plist_temp->T_value = T_temp_value;

		if (plist_front == NULL || plist_rear == NULL)
		{
			plist_front = plist_rear = plist_temp;
		}
		else if (plist_temp->T_value < plist_rear->T_value)
		{
			T T_temp_value = Pop_Rear();

			Push(plist_temp->T_value);

			Push(T_temp_value);
		}
		else
		{
			plist_temp->plist_prev = plist_rear;
			plist_rear->plist_next = plist_temp;
			plist_rear = plist_temp;
		}
	}

	T Pop_Rear()
	{
		T T_temp_value = plist_rear->T_value;

		plist_rear = plist_rear->plist_prev;

		return T_temp_value;
	}

	void Print()
	{
		List* plist_temp = plist_front;

		std::cout << "\nLista este:\n";
		while (plist_temp)
		{
			std::cout << plist_temp->T_value << " ";
			plist_temp = plist_temp->plist_next;
		}

		std::cout << "\n";
	}

	void Read()
	{
		int i_elem;

		std::cout << "Introduceti numarul de elemente din lista:";
		std::cin >> i_elem;

		for (int i = 0;i < i_elem;i++)
		{
			T T_temp_elem;

			std::cout << "\nIntroduceti elementul cu numarul " << i + 1 << ":";
			std::cin >> T_temp_elem;

			Push(T_temp_elem);
			Print();
		}

		std::cout << "\n";
	}
};

int main()
{
	List<int> List1;

	List1.Read();

	return 0;
}
#include <iostream>

template <class T>
class List
{
	T T_value = NULL;
	List* plist_next = NULL;
	List* plist_rear = NULL;
public:
	List* plist_front = NULL;

	void Push(T T_temp_value)
	{
		List* plist_temp = new List();
		plist_temp->T_value = T_temp_value;

		if (plist_front == NULL)
		{
			plist_front = plist_rear = plist_temp;
		}
		else
		{
			plist_rear->plist_next = plist_temp;
			plist_rear = plist_temp;
		}
	}

	T Pop()
	{
		T T_temp_value = plist_front->T_value;

		plist_front = plist_front->plist_next;

		return T_temp_value;
	}

	void Print()
	{
		List* plist_temp = plist_front;

		while (plist_temp)
		{
			std::cout << plist_temp->T_value << " ";
			plist_temp = plist_temp->plist_next;
		}

		std::cout << "\n\n";
	}

	void Read()
	{
		int i_elem;

		std::cout << "Introduceti numarul de elemente din lista:";
		std::cin >> i_elem;

		std::cout << "\n";

		for (int i = 0;i < i_elem;i++)
		{
			T T_temp_elem;

			std::cout << "Introduceti elementul cu numarul " << i + 1 << " :";
			std::cin >> T_temp_elem;

			Push(T_temp_elem);
		}

		std::cout << "\nLista 1 este:\n";
		Print();
	}

	int List_Length(List<int>* list)
	{
		int i_length = 0;

		List<int>* plist_temp = list;

		while (plist_temp)
		{
			i_length++;
			plist_temp = plist_temp->plist_next;
		}

		return i_length;
	}
};

int main()
{
	List<int> List1;

	List1.Read();

	std::cout << "In lista sunt " << List1.List_Length(List1.plist_front) << " elemente.\n\n";

	return 0;
}
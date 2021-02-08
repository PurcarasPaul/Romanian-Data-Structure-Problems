#include <iostream>

template <class T>
class List
{
	T T_value = NULL;
	List* plist_next = NULL;
	List* plist_front = NULL;
	List* plist_rear = NULL;
public:
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

	void Split_List(List& List1, List& List2)
	{
		int i_list = 1;

		while (plist_front)
		{
			if (i_list == 1)
			{
				List1.Push(Pop());
				i_list = 2;
			}
			else
			{
				List2.Push(Pop());
				i_list = 1;
			}
		}
	}
};

int main()
{
	List<int> List1, List2, List3;

	List1.Read();

	List1.Split_List(List2, List3);

	std::cout << "Lista 2 este:\n";
	List2.Print();

	std::cout << "Lista 3 este:\n";
	List3.Print();

	return 0;
}
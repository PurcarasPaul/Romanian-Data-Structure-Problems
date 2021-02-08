#include <iostream>

template <class T>
class List
{
	T T_value = NULL;
	List* plist_next = NULL;
	List* plist_rear = NULL;
	List* plist_front = NULL;
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
	}

	void Add_Elements(List* list_temp)
	{
		while (list_temp)
		{
			Push(list_temp->T_value);
			list_temp = list_temp->plist_next;
		}
	}

	void Combine_lists(List List1, List List2)
	{
		List* plist_temp = List1.plist_front;
		Add_Elements(plist_temp);

		plist_temp = List2.plist_front;
		Add_Elements(plist_temp);
	}
};

int main()
{
	List<int> X, Y, XY;

	X.Read();
	std::cout << "\nElementele din lista X sunt:\n";
	X.Print();

	Y.Read();
	std::cout << "\nElementele din lista Y sunt:\n";
	Y.Print();

	XY.Combine_lists(X, Y);
	std::cout << "Elementele din lista XY sunt:\n";
	XY.Print();

	return 0;
}
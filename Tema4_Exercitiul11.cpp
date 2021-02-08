#include <iostream>

template <class T>
class List
{
	T T_info = NULL;
	List* plist_link = NULL;

public:
	List* plist_head = NULL;
	List* plist_tail = NULL;

	void Insert(T T_value)
	{
		List* plist_temp = new List();
		plist_temp->T_info = T_value;

		if (!plist_head)
		{
			plist_head = plist_tail = plist_temp;
		}
		else
		{
			plist_tail->plist_link = (List*)((uintptr_t)plist_tail->plist_link ^ (uintptr_t)plist_temp);
			plist_temp->plist_link = plist_tail;
			plist_tail = plist_temp;
		}
	}

	void Print_Left_To_Right()
	{
		List* plist_temp = plist_head;
		List* plist_temp_prev = NULL;

		std::cout << "Lista este:\n";
		while (plist_temp)
		{
			std::cout << plist_temp->T_info << " ";

			List* plist_temp_list = plist_temp;
			plist_temp = (List*)((uintptr_t)plist_temp->plist_link ^ (uintptr_t)plist_temp_prev);

			plist_temp_prev = plist_temp_list;
		}

		std::cout << "\n\n";
	}

	void Print_Right_To_Left()
	{
		List* plist_temp = plist_tail;
		List* plist_temp_next = NULL;

		std::cout << "Lista este:\n";
		while (plist_temp)
		{
			std::cout << plist_temp->T_info << " ";

			List* plist_temp_list = plist_temp;
			plist_temp = (List*)((uintptr_t)plist_temp->plist_link ^ (uintptr_t)plist_temp_next);

			plist_temp_next = plist_temp_list;
		}
	}

	void Read()
	{
		int i_elem;

		std::cout << "Introduceti numarul de elemente:";
		std::cin >> i_elem;

		std::cout << "\n";

		for (int i = 0;i < i_elem;i++)
		{
			T T_temp;

			std::cout << "Elementul cu numarul " << i + 1 << ":";
			std::cin >> T_temp;

			Insert(T_temp);
		}
	}
};

int main()
{
	List<int> Lista_dublu_inlantuita;

	Lista_dublu_inlantuita.Read();

	std::cout << "\na)";
	Lista_dublu_inlantuita.Print_Left_To_Right();

	std::cout << "b)";
	Lista_dublu_inlantuita.Print_Right_To_Left();

	std::cout << "\n\n";

	return 0;
}
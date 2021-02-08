#include <iostream>

template <class T>
class List
{
	T T_value = NULL;
	List* plist_next = NULL;
	List* plist_prev = NULL;

public:
	List* plist_head = NULL;
	List* plist_tail = NULL;

	void Add_begin(T T_value)
	{
		List* plist_temp = new List();
		plist_temp->T_value = T_value;

		if (!plist_head)
		{
			plist_head = plist_tail = plist_temp;
		}
		else
		{
			plist_temp->plist_next = plist_head;
			plist_head->plist_prev = plist_temp;
			plist_head = plist_temp;
		}
	}

	void Add_end(T T_value)
	{
		List* plist_temp = new List();
		plist_temp->T_value = T_value;

		if (!plist_head)
		{
			plist_head = plist_tail = plist_temp;
		}
		else
		{
			plist_tail->plist_next = plist_temp;
			plist_temp->plist_prev = plist_tail;
			plist_tail = plist_temp;
		}
	}

	List* Search(T T_search_value)
	{
		List* plist_temp_search = plist_head;

		while (plist_temp_search->T_value != T_search_value && plist_temp_search != plist_tail)
		{
			plist_temp_search = plist_temp_search->plist_next;
		}

		if (plist_temp_search->T_value == T_search_value)
		{
			return plist_temp_search;
		}
		else
		{
			return NULL;
		}
	}

	void Add_after_element(T T_value, T T_search_value)
	{
		List* plist_temp = new List();
		plist_temp->T_value = T_value;

		if (!plist_head)
		{
			plist_head = plist_tail = plist_temp;
		}
		else
		{
			List* plist_temp_search = Search(T_search_value);

			if (plist_temp_search)
			{
				plist_temp->plist_prev = plist_temp_search;
				plist_temp->plist_next = plist_temp_search->plist_next;

				if (plist_temp_search != plist_tail)
				{
					plist_temp_search->plist_next->plist_prev = plist_temp;
					plist_temp_search->plist_next = plist_temp;
				}
				else
				{
					Add_end(T_value);
				}
			}
			else
			{
				std::cout << "Elementul cautat nu exista in lista.\n";
			}
		}
	}

	void Delete_begin()
	{
		List* plist_temp = plist_head;

		plist_head = plist_head->plist_next;
		plist_head->plist_prev = NULL;

		delete plist_temp;
	}

	void Delete_end()
	{
		List* plist_temp = plist_tail;

		plist_tail = plist_tail->plist_prev;
		plist_tail->plist_next = NULL;

		delete plist_temp;
	}

	void Delete_element(T T_element_to_delete)
	{
		List* plist_temp = Search(T_element_to_delete);

		plist_temp->plist_prev->plist_next = plist_temp->plist_next;
		plist_temp->plist_next->plist_prev = plist_temp->plist_prev;

		delete plist_temp;
	}

	void Modify(T T_value, int i_position)
	{
		int i_temp_position = 0;

		List* plist_temp = plist_head;

		while (plist_temp && i_temp_position != i_position)
		{
			i_temp_position++;
			plist_temp = plist_temp->plist_next;
		}

		plist_temp->T_value = T_value;
	}

	void Print()
	{
		List* plist_temp = plist_head;

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

		std::cout << "Introduceti numarul de elemente:";
		std::cin >> i_elem;

		std::cout << "\n";

		for (int i = 0;i < i_elem;i++)
		{
			T T_temp;

			std::cout << "Elementul cu numarul " << i + 1 << ":";
			std::cin >> T_temp;

			Add_end(T_temp);
		}

		std::cout << "\nAdaugare final:";
	}
};

int main()
{
	List<int> Lista_Dubla_Inlantuire;

	Lista_Dubla_Inlantuire.Read();
	Lista_Dubla_Inlantuire.Print();

	std::cout << "\nAdaugare inceput:";
	Lista_Dubla_Inlantuire.Add_begin(3);
	Lista_Dubla_Inlantuire.Add_begin(5);
	Lista_Dubla_Inlantuire.Print();

	std::cout << "\nAdaugare dupa element:";
	Lista_Dubla_Inlantuire.Add_after_element(10, 4);
	Lista_Dubla_Inlantuire.Print();
	Lista_Dubla_Inlantuire.Add_after_element(15, 10);
	Lista_Dubla_Inlantuire.Print();

	std::cout << "\nStergere inceput:";
	Lista_Dubla_Inlantuire.Delete_begin();
	Lista_Dubla_Inlantuire.Print();

	std::cout << "\nStergere final:";
	Lista_Dubla_Inlantuire.Delete_end();
	Lista_Dubla_Inlantuire.Print();

	std::cout << "\nStergere element:";
	Lista_Dubla_Inlantuire.Delete_element(4);
	Lista_Dubla_Inlantuire.Print();

	std::cout << "\nModificare element:";
	Lista_Dubla_Inlantuire.Modify(-6, 2);
	Lista_Dubla_Inlantuire.Print();

	std::cout << "\n";

	return 0;
}
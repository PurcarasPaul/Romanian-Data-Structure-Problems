#include <iostream>

template <class T>
class CircularList
{
	T T_value = NULL;
	CircularList* pclist_next = NULL;
	CircularList* pclist_rear = NULL;
	CircularList* pclist_front = NULL;
public:
	void Push(T T_temp_value)
	{
		CircularList* pclist_temp = new CircularList();
		pclist_temp->T_value = T_temp_value;

		if (pclist_front == NULL)
		{
			pclist_front = pclist_rear = pclist_temp;
		}
		else
		{
			pclist_rear->pclist_next = pclist_temp;
			pclist_rear = pclist_temp;
			pclist_rear->pclist_next = pclist_front;
		}
	}

	T Next()
	{
		T T_temp_value = pclist_front->T_value;

		pclist_front = pclist_front->pclist_next;

		return T_temp_value;
	}

	void Split_List(CircularList& List1, CircularList& List2)
	{
		int i_list = 1;

		do
		{
			if (i_list == 1)
			{
				List1.Push(Next());
				i_list = 2;
			}
			else
			{
				List2.Push(Next());
				i_list = 1;
			}
		} while (pclist_front != pclist_rear->pclist_next);
	}

	void Print()
	{
		CircularList* pclist_temp = pclist_front;

		if (pclist_temp)
		{
			std::cout << "\nLista circulara este:\n";

			do
			{
				std::cout << pclist_temp->T_value << " ";
				pclist_temp = pclist_temp->pclist_next;
			} while (pclist_temp != pclist_rear->pclist_next);
		}
		else
		{
			std::cout << "\nLista este goala.";
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
};

int main()
{
	CircularList<int> List1, List2, List3;

	std::cout << "Lista 1\n";
	List1.Read();
	List1.Print();
	List1.Split_List(List2, List3);

	std::cout << "Lista 2\n";
	List2.Print();

	std::cout << "Lista 3\n";
	List3.Print();

	return 0;
}
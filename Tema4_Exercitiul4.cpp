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

	void Delete()
	{
		int i_value_to_delete;
		CircularList* pclist_delete;

		std::cout << "Introduceti valoarea care sa fie stearsa:";
		std::cin >> i_value_to_delete;

		if (!pclist_front)
		{
			std::cout << "Lista este goala.\n";
			return;
		}
		else if (pclist_front == pclist_rear && pclist_front->T_value == i_value_to_delete)
		{
			pclist_delete = pclist_front;
			pclist_front = pclist_rear = NULL;

			free(pclist_delete);
		}
		else if (pclist_front->T_value == i_value_to_delete)
		{
			pclist_rear->pclist_next = pclist_front->pclist_next;
			pclist_delete = pclist_front;
			pclist_front = pclist_front->pclist_next;

			free(pclist_delete);
		}
		else
		{
			CircularList* pclist_temp = pclist_front;

			while (pclist_temp->pclist_next != pclist_front && pclist_temp->pclist_next->T_value != i_value_to_delete)
			{
				pclist_temp = pclist_temp->pclist_next;
			}

			if (pclist_temp->pclist_next->T_value == i_value_to_delete)
			{
				pclist_delete = pclist_temp->pclist_next;
				pclist_temp->pclist_next = pclist_temp->pclist_next->pclist_next;

				if (pclist_delete == pclist_rear)
				{
					pclist_rear = pclist_temp;
				}

				free(pclist_delete);
			}
			else
			{
				std::cout << "Valoarea introdusa nu se afla in lista.\n";
			}
		}
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
	CircularList<int> List1;

	List1.Read();
	List1.Print();

	List1.Delete();
	List1.Print();

	return 0;
}
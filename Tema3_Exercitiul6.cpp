#include <iostream>

template <class T>
class Scroll
{
	T T_value = NULL;
	Scroll* next = NULL;
	Scroll* prev = NULL;

public:
	Scroll* last = NULL;
	Scroll* first = NULL;
	
	void Push(int T_temp_value)
	{
		Scroll* temp_scroll = new Scroll;
		temp_scroll->T_value = T_temp_value;
		temp_scroll->prev = last;

		if (first == NULL)
		{
			last = first = temp_scroll;
		}
		else
		{
			last->next = temp_scroll;
			last = temp_scroll;
		}
	}

	void Print()
	{
		Scroll* temp_scroll = first;

		if (temp_scroll)
		{
			std::cout << "\nScroll-ul este:\n\n";
			while (temp_scroll != NULL)
			{
				std::cout << temp_scroll->T_value << "\n";
				temp_scroll = temp_scroll->next;
			}
		}
		else
		{
			std::cout << "\nScroll-ul este gol\n";
		}

	}

	void Pop_Last()
	{
		if (last)
		{
			if (last == first)
			{
				last = first = NULL;
			}
			else
			{
				last = last->prev;
			}

			if (last)
			{
				last->next = NULL;
			}
		}
	}

	void Pop_First()
	{
		if (first)
		{
			if (last == first)
			{
				last = first = NULL;
			}
			else
			{
				first = first->next;
			}

			if (first)
			{
				first->prev = NULL;
			}
		}
	}

	void Read()
	{
		int i_elem;
		
		std::cout << "Introduceti numarul de elemente din scroll:";
		std::cin >> i_elem;

		std::cout << "\n";

		for (int i = 0;i < i_elem;i++)
		{
			int i_temp;

			std::cout << "Elementul cu numarul " << i + 1 << " :";
			std::cin >> i_temp;

			Push(i_temp);
		}
	}
};

int main()
{
	Scroll<int> Scroll1;

	Scroll1.Read();
	Scroll1.Print();

	std::cout << "\nStergere la inceputul scroll-ului";
	Scroll1.Pop_First();
	Scroll1.Print();

	std::cout << "\nStergere la finalul scroll-ului";
	Scroll1.Pop_Last();
	Scroll1.Print();

	std::cout << "\n";

	return 0;
}
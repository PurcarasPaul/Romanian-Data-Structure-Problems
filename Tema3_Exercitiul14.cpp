#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>

template <class T>
class Stack
{
	T T_value;
	Stack* pstack_next = NULL;

public:
	Stack* pstack_top = NULL;

	void Push(T T_temp_value)
	{
		Stack* pstack_temp = new Stack();
		pstack_temp->T_value = T_temp_value;
		pstack_temp->pstack_next = pstack_top;
		pstack_top = pstack_temp;
	}

	T Pop()
	{
		T T_temp_value = pstack_top->T_value;

		pstack_top = pstack_top->pstack_next;

		return T_temp_value;
	}

	void Print()
	{
		while (pstack_top)
		{
			std::cout << pstack_top->T_value << "\n";
			pstack_top = pstack_top->pstack_next;
		}
	}

	template <class T>
	friend class Program;
};

template <class T>
class Queue
{
	T T_value;
	Queue* pqueue_next = NULL;

public:
	Queue* pqueue_front = NULL;
	Queue* pqueue_rear = NULL;

	void EnQueue(T T_temp_value)
	{
		Queue* pqueue_temp = new Queue();
		pqueue_temp->T_value = T_temp_value;

		if (!pqueue_front)
		{
			pqueue_front = pqueue_rear = pqueue_temp;
		}
		else
		{
			pqueue_rear->pqueue_next = pqueue_temp;
			pqueue_rear = pqueue_temp;
		}
	}

	T DeQueue()
	{
		T T_temp_value = pqueue_front->T_value;

		pqueue_front = pqueue_front->pqueue_next;

		return T_temp_value;
	}

	void Print()
	{
		while (pqueue_front)
		{
			std::cout << pqueue_front->T_value << "\n";
			pqueue_front = pqueue_front->pqueue_next;
		}
	}

	template <class T>
	friend class Program;
};

template <class T>
class Program
{
	std::map<std::string, Stack<T>> map_stack;
	std::map<std::string, Queue<T>> map_queue;

public:

	std::string Get_identifier(std::string s_temp)
	{
		std::string s_temp_identifier;

		for (int i = 2;i < s_temp.length();i++)
		{
			if (s_temp[i] == ' ')
			{
				break;
			}

			s_temp_identifier += s_temp[i];
		}

		return s_temp_identifier;
	}

	void Get_Identifiers(std::string s_temp, std::string &s_identifier2, std::string &s_identifier3)
	{
		std::string s_value;

		for (int i = 2;i < s_temp.length();i++)
		{
			if (s_temp[i] != ' ')
			{
				s_value += s_temp[i];
			}
			else
			{
				s_identifier2 = s_value;
				s_value = "";
			}
		}
		s_identifier3 = s_value;
	}

	void S(std::string s_temp_identifier)
	{
		Stack<T> Stack_identifier;

		map_stack.insert(std::make_pair(s_temp_identifier, Stack_identifier));
	}

	void Q(std::string s_temp_identifier)
	{
		Queue<T> Queue_identifier;

		map_queue.insert(std::make_pair(s_temp_identifier, Queue_identifier));
	}

	void D(std::string s_temp_identifier)
	{
		if (map_stack.find(s_temp_identifier) != map_stack.end())
		{
			map_stack.erase(s_temp_identifier);
		}

		if (map_queue.find(s_temp_identifier) != map_queue.end())
		{
			map_queue.erase(s_temp_identifier);
		}
	}

	void A(std::string s_temp_identifier, std::string s_temp_values)
	{
		std::vector<T> T_temp_vector;
		std::string s_value;

		for (int i = 0;i < s_temp_values.length();i++)
		{
			if (s_temp_values[i] != ' ')
			{
				s_value += s_temp_values[i];
			}
			else
			{
				T_temp_vector.push_back(s_value);
				s_value = "";
			}
		}
		T_temp_vector.push_back(s_value);

		if (map_stack.find(s_temp_identifier) != map_stack.end())
		{
			for (int i = 0;i < T_temp_vector.size();i++)
			{
				if (T_temp_vector[i] != "")
				{
					map_stack[s_temp_identifier].Push(T_temp_vector[i]);
				}
			}
		}

		if (map_queue.find(s_temp_identifier) != map_queue.end())
		{
			for (int i = 0;i < T_temp_vector.size();i++)
			{
				if (T_temp_vector[i] != "")
				{
					map_queue[s_temp_identifier].EnQueue(T_temp_vector[i]);
				}
			}
		}
	}

	void X(std::string s_temp_identifier,int i_temp_number)
	{
		if (map_stack.find(s_temp_identifier) != map_stack.end())
		{
			for (int i = 0;i < i_temp_number;i++)
			{
				if (map_stack[s_temp_identifier].pstack_top)
				{
					map_stack[s_temp_identifier].Pop();
				}
			}
		}

		if (map_queue.find(s_temp_identifier) != map_queue.end())
		{
			for (int i = 0;i < i_temp_number;i++)
			{
				if (map_queue[s_temp_identifier].pqueue_front)
				{
					map_queue[s_temp_identifier].DeQueue();
				}
			}
		}
	}

	void P(std::string s_temp_identifier)
	{
		if (map_stack.find(s_temp_identifier) != map_stack.end())
		{
			if (map_stack[s_temp_identifier].pstack_top)
			{
				std::cout << "\nStiva cu identificatorul " << s_temp_identifier << " este urmatoarea:\n";
				map_stack[s_temp_identifier].Print();
			}
			else
			{
				std::cout << "\nStiva este goala.\n";
			}
		}

		if (map_queue.find(s_temp_identifier) != map_queue.end())
		{
			if (map_queue[s_temp_identifier].pqueue_front)
			{
				std::cout << "\nCoada cu identificatorul " << s_temp_identifier << " este urmatoarea:\n";
				map_queue[s_temp_identifier].Print();
			}
			else
			{
				std::cout << "\nCoada este goala.\n";
			}
		}

		std::cout << "\n";
	}

	void Stack_Concatenation(std::string s_temp_identifier3,std::string s_temp_identifier)
	{
		Stack<T>* pstack_temp = map_stack[s_temp_identifier].pstack_top;

		while (pstack_temp)
		{
			map_stack[s_temp_identifier3].Push(pstack_temp->T_value);
			pstack_temp = pstack_temp->pstack_next;
		}
	}

	void Queue_Concatenation(std::string s_temp_identifier3, std::string s_temp_identifier)
	{
		Queue<T>* pqueue_temp = map_queue[s_temp_identifier].pqueue_front;

		while (pqueue_temp)
		{
			map_queue[s_temp_identifier3].EnQueue(pqueue_temp->T_value);
			pqueue_temp = pqueue_temp->pqueue_next;
		}
	}

	void M(std::string s_temp_identifier1, std::string s_temp_identifier2, std::string s_temp_identifier3)
	{
		if (map_stack.find(s_temp_identifier1) != map_stack.end())
		{
			S(s_temp_identifier3);
			Stack_Concatenation(s_temp_identifier3, s_temp_identifier1);
			Stack_Concatenation(s_temp_identifier3, s_temp_identifier2);
		}
		else if (map_queue.find(s_temp_identifier1) != map_queue.end())
		{
			Q(s_temp_identifier3);
			Queue_Concatenation(s_temp_identifier3, s_temp_identifier1);
			Queue_Concatenation(s_temp_identifier3, s_temp_identifier2);
		}
	}

	void Read()
	{
		char c_command;

		do
		{
			std::string s_temp;

			std::cout << ">";
			std::getline(std::cin, s_temp);
			c_command = s_temp[0];

			std::string s_identifier = Get_identifier(s_temp);

			switch (c_command)
			{
			case 'S':
				S(s_identifier);
				break;
			case 'Q':
				Q(s_identifier);
				break;
			case 'D':
				D(s_identifier);
				break;
			case 'A':
			{
				std::string s_values_list = s_temp.substr(3 + s_identifier.length(), s_temp.length());
				A(s_identifier, s_values_list);
				break;
			}
			case 'X':
			{
				int i_number = stoi(s_temp.substr(3 + s_identifier.length(), s_temp.length()));
				X(s_identifier, i_number);
				break;
			}
			case 'P':
				P(s_identifier);
				break;
			case 'M':
			{
				std::string s_identifier2, s_identifier3;
				Get_Identifiers(s_temp, s_identifier2, s_identifier3);
				M(s_identifier, s_identifier2, s_identifier3);
				break;
			}
			case 'E':
				break;
			default:
				std::cout << "Nu exista comanda " << c_command << "\n";
			}
		} while (c_command != 'E');
	}
};

int main()
{
	Program<std::string> Program1;

	Program1.Read();

	/*Exemplu:
	  Q abcd
	  Q qwer
          A abcd 1 2 3 4 5 
          A qwer 6 7 8 9 10
	  M abcd qwer xaxa
	  P abcd
	  P qwer
	  X xaxa 3
	  P xaxa
	  S stac
	  S stac2
	  A stac a b c d
	  A stac2 e f g h
	  M stac stac2 stac3
	  P stac
	  P stac2
	  X stac3 2
	  P stac3
	  D xaxa
	  D stac3
	  E
	*/

	return 0;
}
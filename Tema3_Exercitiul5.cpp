#include <iostream>

template <class T>
class CQueue
{
	T T_value;
	CQueue* pqueue_next;

public:
	CQueue* cq_front = NULL;
	CQueue* cq_rear = NULL;

	CQueue()
	{
		T_value = 0;
		pqueue_next = NULL;
	}

	void Enqueue(T i_temp_value)
	{
		CQueue* pcqueue_temp = new CQueue;
		pcqueue_temp->T_value = i_temp_value;

		if (cq_front == NULL)
		{
			cq_front = pcqueue_temp;
		}
		else
		{
			cq_rear->pqueue_next = pcqueue_temp;
		}

		cq_rear = pcqueue_temp;
		cq_rear->pqueue_next = cq_front;
	}

	void Read()
	{
		std::string s_temp;

		std::cout << "Introduceti linia de caractere:";
		std::cin >> s_temp;

		for (int i = 0;i < s_temp.length();i++)
		{
			Enqueue(s_temp[i]);
		}
	}

	int Check_Less_Than_Sign()
	{
		CQueue* pcqueue_temp = cq_front;

		//Primul caracter din sir este "<"
		if (pcqueue_temp->T_value == '<')
		{
			return 5;
		}
		else
		{
			pcqueue_temp = pcqueue_temp->pqueue_next;
		}

		while (pcqueue_temp->pqueue_next != cq_front)
		{
			if (pcqueue_temp->T_value == '<')
			{
				//Caracterul "<" exista in sir
				return 0;
			}

			pcqueue_temp = pcqueue_temp->pqueue_next;
		}

		//Ultimul caracter din sir este "<"
		if (pcqueue_temp->T_value == '<')
		{
			return 5;
		}

		//Caracterul "<" nu exista in sir
		return 1;
	}

	bool is_Same_String(CQueue* pcqueue_temp_string2)
	{
		CQueue* pcqueue_temp_string1 = cq_front;

		while (pcqueue_temp_string1->T_value != '<')
		{
			if (pcqueue_temp_string1->T_value != pcqueue_temp_string2->T_value)
			{
				return false;
			}

			pcqueue_temp_string1 = pcqueue_temp_string1->pqueue_next;
			pcqueue_temp_string2 = pcqueue_temp_string2->pqueue_next;
		}

		return true;
	}

	void Dequeue(CQueue* &cq_front_temp)
	{
		cq_front_temp = cq_front_temp->pqueue_next;
		cq_rear->pqueue_next = cq_front_temp;
	}

	int Check_Length()
	{
		CQueue* pcqueue_temp = cq_front;
		int i_length1 = 0, i_length2 = 1;

		while (pcqueue_temp->T_value != '<')
		{
			i_length1++;
			Dequeue(pcqueue_temp);
		}
		Dequeue(pcqueue_temp);

		CQueue* pc_queue_temp2 = pcqueue_temp;
		while (pcqueue_temp->pqueue_next != pc_queue_temp2)
		{
			i_length2++;
			pcqueue_temp = pcqueue_temp->pqueue_next;
		}
		pcqueue_temp = pcqueue_temp->pqueue_next;

		if (i_length1 > i_length2)
		{
			return 2;
		}
		else if (i_length1 < i_length2)
		{
			return 3;
		}
		else
		{
			if (is_Same_String(pcqueue_temp))
			{
				return 0;
			}
			else
			{
				return 4;
			}
		}
	}

	int Answer()
	{
		int i_less_than_sign = Check_Less_Than_Sign();

		//Exista "<"
		if (!i_less_than_sign)
		{
			return Check_Length();
		}
		else
		{
			return i_less_than_sign;
		}
	}

	void PrintAnswer()
	{
		int i_answer = Answer();

		std::cout << "\n";

		if (!i_answer)
		{
			std::cout << "Raspunsul este 0,partea din stanga este identica cu partea din dreapta\n";
		}
		else if (i_answer == 1)
		{
			std::cout << "Raspunsul este 1,nu exista \"<\" in sirul de intrare\n";
		}
		else if (i_answer == 2)
		{
			std::cout << "Raspusul este 2,partea dinaintea lui \"<\" este mai lunga decat cea de dupa \"<\" \n";
		}
		else if (i_answer == 3)
		{
			std::cout << "Raspusul este 3,partea dinaintea lui \"<\" este mai scurta decat cea de dupa \"<\" \n";
		}
		else if (i_answer == 4)
		{
			std::cout << "Raspusul este 4,partile din stanga si din dreapta a lui \"<\" au aceeasi lungime,dar sunt diferite\n";
		}
		else if (i_answer == 5)
		{
			std::cout << "Raspunsul este 5,exista \"<\" in sirul de intrare,dar sirul nu are doua parti\n";
		}

		std::cout << "\n";
	}
};

int main()
{
	CQueue<char> Queue1;

	Queue1.Read();
	Queue1.PrintAnswer();

	return 0;
}
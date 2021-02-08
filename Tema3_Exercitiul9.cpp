#include <stdio.h>

struct Queue
{
private:
	int i_value = 0;
	Queue* pqueue_next = NULL;
public:
	int i_planes_in_queue = 0;
	Queue* pqueue_front;
	Queue* pqueue_rear;

	Queue()
	{
		pqueue_front = pqueue_rear = NULL;
	}

	void EnQueue()
	{
		Queue* pqueue_temp = new Queue;
		pqueue_temp->i_value = 1;

		if (!pqueue_front)
		{
			pqueue_front = pqueue_rear = pqueue_temp;
		}
		else
		{
			pqueue_rear->pqueue_next = pqueue_temp;
			pqueue_rear = pqueue_temp;
		}

		i_planes_in_queue++;
	}

	void DeQueue()
	{
		pqueue_front = pqueue_front->pqueue_next;
		i_planes_in_queue--;
	}
};

void Read(Queue &queue_temp_planes_landing, Queue &queue_temp_planes_taking_off,int &i_temp_max_planes)
{
	int i_planes;

	printf_s("Introduceti numarul maxim de avioane care pot fi la sol:");
	scanf_s("%d", &i_temp_max_planes);

	printf_s("Introduceti numarul de avioane care vor sa aterizeze:");
	scanf_s("%d", &i_planes);

	for (int i = 0;i < i_planes;i++)
	{
		queue_temp_planes_landing.EnQueue();
	}

	TOOMANY:
	printf_s("Introduceti numarul de avioane care vor sa decoleze:");
	scanf_s("%d", &i_planes);

	if (i_planes > i_temp_max_planes)
	{
		printf_s("\nNumarul de avioane de la sol nu poate fi mai mare decat numarul maxim de avioane care pot fi la sol.\n\n");
		goto TOOMANY;
	}

	for (int i = 0;i < i_planes;i++)
	{
		queue_temp_planes_taking_off.EnQueue();
	}

	printf_s("\n");
}

void Take_Off(Queue& queue_temp_planes_taking_off, int& i_temp_curent_planes_on_ground)
{
	queue_temp_planes_taking_off.DeQueue();
	i_temp_curent_planes_on_ground--;
}

void Land(Queue& queue_temp_planes_landing, int& i_temp_curent_planes_on_ground)
{
	queue_temp_planes_landing.DeQueue();
	i_temp_curent_planes_on_ground++;
}

void Print_Taking_Off(Queue& queue_temp_planes_taking_off, int i_temp_curent_planes_on_ground)
{
	printf_s("A decolat un avion,numarul de avioane de la sol este %d", i_temp_curent_planes_on_ground);
	if (queue_temp_planes_taking_off.i_planes_in_queue == 1)
	{
		printf_s(",inca este un avion care vrea sa decoleze.\n");
	}
	else if (queue_temp_planes_taking_off.i_planes_in_queue > 0)
	{
		printf_s(",inca sunt %d avioane care vor sa decoleze.\n", queue_temp_planes_taking_off.i_planes_in_queue);
	}
	else if (queue_temp_planes_taking_off.i_planes_in_queue == 0)
	{
		printf_s(",nu mai sunt avioane care vor sa decoleze.\n");
	}
}

void Print_Landing(Queue& queue_temp_planes_landing, int i_temp_curent_planes_on_ground)
{
	printf_s("A aterizat un avion,numarul de avioane de la sol este %d", i_temp_curent_planes_on_ground);
	if (queue_temp_planes_landing.i_planes_in_queue == 1)
	{
		printf_s(",inca este un avion care vrea sa aterizeze.\n");
	}
	else if (queue_temp_planes_landing.i_planes_in_queue > 0)
	{
		printf_s(",inca sunt %d avioane care vor sa aterizeze.\n", queue_temp_planes_landing.i_planes_in_queue);
	}
	else if (queue_temp_planes_landing.i_planes_in_queue == 0)
	{
		printf_s(",nu mai sunt avioane care vor sa aterizeze.\n");
	}
}

void Solution(Queue& queue_temp_planes_landing, Queue& queue_temp_planes_taking_off, int& i_temp_max_planes)
{
	int i_curent_planes_on_ground = queue_temp_planes_taking_off.i_planes_in_queue;

	while (queue_temp_planes_landing.pqueue_front != NULL || queue_temp_planes_taking_off.pqueue_front != NULL)
	{
		if (i_temp_max_planes == i_curent_planes_on_ground && queue_temp_planes_taking_off.pqueue_front == NULL)
		{
			printf_s("Nu mai sunt locuri pentru avioane in aeroport.\n");
			break;
		}
		else if (i_temp_max_planes == i_curent_planes_on_ground || queue_temp_planes_landing.pqueue_front == NULL)
		{
			Take_Off(queue_temp_planes_taking_off, i_curent_planes_on_ground);
			Print_Taking_Off(queue_temp_planes_taking_off, i_curent_planes_on_ground);
		}
		else if(i_temp_max_planes > i_curent_planes_on_ground)
		{
			Land(queue_temp_planes_landing, i_curent_planes_on_ground);
			Print_Landing(queue_temp_planes_landing, i_curent_planes_on_ground);
		}
	}

	printf_s("\n");
}

int main()
{
	Queue queue_planes_landing, queue_planes_taking_off;
	int i_max_planes_on_ground;

	Read(queue_planes_landing, queue_planes_taking_off, i_max_planes_on_ground);
	Solution(queue_planes_landing, queue_planes_taking_off, i_max_planes_on_ground);

	return 0;
}
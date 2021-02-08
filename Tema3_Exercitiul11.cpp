#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
class Stack
{
	T T_value = 0;
	Stack* pstack_next = NULL;
	int i_size = 0;
public:
	Stack* pstack_top = NULL;

	void Push(T T_temp_value)
	{
		Stack* pstack_temp = new Stack();
		pstack_temp->T_value = T_temp_value;
		pstack_temp->pstack_next = pstack_top;
		pstack_top = pstack_temp;
		i_size++;
	}

	void Pop()
	{
		pstack_top = pstack_top->pstack_next;
		i_size--;
	}

	void Print()
	{
		std::cout << pstack_top->T_value << " ";
	}

	friend class Tetris;
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

	T Peek()
	{
		return pqueue_front->T_value;
	}

};

class Tetris
{
	std::vector<Stack<int>> v_grid;
	std::vector<std::vector<std::vector<int>>>v_geometric_figures =
	{
		{
			{1}
		},
		{
			{1,1},
			{1,1}
		},
		{
			{1},
			{1,1}
		},
		{
			{1},
			{1,1},
			{0,1}
		}
	};
	Queue <std::vector<std::vector<int>>> queue_geometric_figures;

public:
	void Init(int i_m)
	{
		for (int i = 0;i < v_geometric_figures.size();i++)
		{
			queue_geometric_figures.EnQueue(v_geometric_figures[i]);
		}
		
		std::cout << "\n";
		v_grid.resize(i_m);
		Add_Zero(i_m);
		Print_Grid(i_m);
		Delete_Zero();
	}

	void Add_Zero(int i_m)
	{
		for (int i = 0;i < v_grid.size();i++)
		{
			if (v_grid[i].i_size != i_m)
			{
				int i_curent_size = v_grid[i].i_size;

				for (int j = 0;j < i_m - i_curent_size;j++)
				{
					v_grid[i].Push(0);
				}
			}
		}
	}

	void Print_Figure(std::vector<std::vector<int>> v_temp_figure)
	{
		for (int i = 0;i < v_temp_figure.size();i++)
		{
			for (int j = 0;j < v_temp_figure[i].size();j++)
			{
				if (v_temp_figure[i][j != 0])
				{
					std::cout << v_temp_figure[i][j] << " ";
				}
				else
				{
					std::cout << "  ";
				}
			}
			
			std::cout << "\n";
		}

		std::cout << "\n";
	}

	void Fix_Grid(std::vector<std::vector<int>> v_temp_figure,int i_temp_column)
	{
		int i_line = v_temp_figure.size() - 1;

		for (int i = 1;i < v_temp_figure[i_line].size();i++)
		{
			while(v_grid[i_temp_column + i].i_size > v_grid[i_temp_column].i_size)
			{
				v_grid[i_temp_column].Push(0);
			}

			while (v_grid[i_temp_column + i].i_size < v_grid[i_temp_column].i_size)
			{
				v_grid[i_temp_column + i].Push(0);
			}
		}
	}

	bool CanPlace(std::vector<std::vector<int>> v_temp_figure,int i_m,int i_column)
	{
		if (v_temp_figure.size() > 1)
		{
			if (v_temp_figure.size() + v_grid[i_column].i_size <= i_m && v_temp_figure.size() + v_grid[i_column+1].i_size <= i_m)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}

	void Push_figure(int i_m,int i_n)
	{
		int i_column;

		std::vector<std::vector<int>> v_temp_figure = queue_geometric_figures.DeQueue();
		queue_geometric_figures.EnQueue(v_temp_figure);

		std::vector<std::vector<int>> v_temp_figure2 = queue_geometric_figures.Peek();

		std::cout << "\nFigura curenta este:\n";
		Print_Figure(v_temp_figure);
		std::cout << "Figura urmatoare este:\n";
		Print_Figure(v_temp_figure2);

		CANTPLACE:
		std::cout << "Selectati coloana:";
		std::cin >> i_column;

		if (CanPlace(v_temp_figure, i_m, i_column))
		{
			for (int i = v_temp_figure.size() - 1;i >= 0;i--)
			{
				Fix_Grid(v_temp_figure, i_column);
				for (int j = 0;j < v_temp_figure[i].size();j++)
				{
					v_grid[i_column + j].Push(v_temp_figure[i][j]);
				}
			}
		}
		else
		{
			std::cout << "\nIncercati alta coloana\n\n";
			goto CANTPLACE;
		}

		Add_Zero(i_m);
	}

	void Print_Grid(int i_m)
	{
		std::vector<Stack<int>>pv_grid = v_grid;

		for (int i = 0;i < i_m;i++)
		{
			for (int j = 0;j < pv_grid.size();j++)
			{
				pv_grid[j].Print();
				pv_grid[j].pstack_top = pv_grid[j].pstack_top->pstack_next;
			}
			std::cout << "\n";
		}
	}

	void Delete_Zero()
	{
		for (int i = 0;i < v_grid.size();i++)
		{
			while (v_grid[i].pstack_top->T_value == 0)
			{
				v_grid[i].Pop();

				if (!v_grid[i].i_size)
				{
					break;
				}
			}
		}
	}

	bool isLose(int i_m)
	{
		for (int i = 0;i < v_grid.size();i++)
		{
			if (v_grid[i].i_size == i_m)
			{
				return true;
			}
		}

		return false;	
	}

	void Play()
	{
		int i_m, i_n;

		std::cout << "Introduceti m si n:";
		std::cin >> i_m >> i_n;

		Init(i_m);
		do
		{
			Push_figure(i_m, i_n);
			Print_Grid(i_m);
			Delete_Zero();
		} while (!isLose(i_m));

		std::cout << "\nGame over!\n\n";
	}
};

int main()
{
	Tetris Game;

	Game.Play();

	/*Exemplu:
	* 
	* 5 5
	* 1
	* 2
	* 3
	* 1
	*/

	return 0;
}
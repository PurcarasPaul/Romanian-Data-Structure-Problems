#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

class List
{
	float f_value_coef = NULL;
	float f_value_grad = NULL;
	List* plist_next = NULL;
	List* plist_prev = NULL;
	List* plist_rear = NULL;
public:
	List* plist_front = NULL;

	void Push(float f_value_coef, float f_value_grad)
	{
		List* plist_temp = new List();
		plist_temp->f_value_coef = f_value_coef;
		plist_temp->f_value_grad = f_value_grad;

		if (plist_front == NULL || plist_rear == NULL)
		{
			plist_front = plist_rear = plist_temp;
		}
		else if (plist_temp->f_value_grad > plist_rear->f_value_grad)
		{
			float f_temp_coef = plist_rear->f_value_coef;
			float f_temp_grad = plist_rear->f_value_grad;
			plist_rear = plist_rear->plist_prev;

			Push(plist_temp->f_value_coef, plist_temp->f_value_grad);

			Push(f_temp_coef, f_temp_grad);
		}
		else if (plist_temp->f_value_grad == plist_rear->f_value_grad)
		{
			plist_rear->f_value_coef += plist_temp->f_value_coef;
		}
		else
		{
			plist_temp->plist_prev = plist_rear;
			plist_rear->plist_next = plist_temp;
			plist_rear = plist_temp;
		}
	}

	void Print()
	{
		List* plist_temp = plist_front;

		if (plist_temp)
		{
			std::cout << "Polinomul este:\n";
			while (plist_temp->plist_next)
			{
				if (plist_temp->plist_next->f_value_coef > 0)
				{
					std::cout << plist_temp->f_value_coef << "x^" << plist_temp->f_value_grad << "+";
				}
				else
				{
					std::cout << plist_temp->f_value_coef << "x^" << plist_temp->f_value_grad;
				}

				plist_temp = plist_temp->plist_next;
			}

			std::cout << plist_temp->f_value_coef << "x^" << plist_temp->f_value_grad << "\n\n";
		}
	}

	void Read()
	{
		float f_elem;

		std::cout << "Introduceti numarul de elemente din polinom:";
		std::cin >> f_elem;

		for (float i = 0;i < f_elem;i++)
		{
			float f_temp_coef, f_temp_grad;

			std::cout << "\nIntroduceti elementul cu numarul " << i + 1 << ":";

			std::cout << "\nCoeficient:";
			std::cin >> f_temp_coef;;

			if (f_temp_coef)
			{
				std::cout << "Grad:";
				std::cin >> f_temp_grad;

				Push(f_temp_coef, f_temp_grad);
			}
		}

		std::cout << "\n";
	}

	friend class PolinomOperations;
};

class PolinomOperations: public List
{
public:
	void Addition(List Polinom1, List Polinom2)
	{
		plist_front = NULL;

		while (Polinom1.plist_front || Polinom2.plist_front)
		{
			if (Polinom1.plist_front && Polinom2.plist_front)
			{
				if (Polinom1.plist_front->f_value_grad == Polinom2.plist_front->f_value_grad)
				{
					float f_temp_coef = Polinom1.plist_front->f_value_coef + Polinom2.plist_front->f_value_coef;
					float f_temp_grad = Polinom1.plist_front->f_value_grad;

					if (f_temp_coef)
					{
						Push(f_temp_coef, f_temp_grad);
					}

					Polinom1.plist_front = Polinom1.plist_front->plist_next;
					Polinom2.plist_front = Polinom2.plist_front->plist_next;
				}
				else if (Polinom1.plist_front->f_value_grad > Polinom2.plist_front->f_value_grad)
				{
					Push(Polinom1.plist_front->f_value_coef, Polinom1.plist_front->f_value_grad);
					Polinom1.plist_front = Polinom1.plist_front->plist_next;
				}
				else
				{
					Push(Polinom2.plist_front->f_value_coef, Polinom2.plist_front->f_value_grad);
					Polinom2.plist_front = Polinom2.plist_front->plist_next;
				}
			}
			else if(Polinom1.plist_front)
			{
				Push(Polinom1.plist_front->f_value_coef, Polinom1.plist_front->f_value_grad);
				Polinom1.plist_front = Polinom1.plist_front->plist_next;
			}
			else if (Polinom2.plist_front)
			{
				Push(Polinom2.plist_front->f_value_coef, Polinom2.plist_front->f_value_grad);
				Polinom2.plist_front = Polinom2.plist_front->plist_next;
			}
		}
	}

	List Copy_List(List List_to_copy)
	{
		List list_temp;

		while (List_to_copy.plist_front)
		{
			list_temp.Push(List_to_copy.plist_front->f_value_coef, List_to_copy.plist_front->f_value_grad);
			List_to_copy.plist_front = List_to_copy.plist_front->plist_next;
		}

		return list_temp;
	}

	void Subtraction(List Polinom1, List Polinom2)
	{
		plist_front = NULL;

		List list_temp = Copy_List(Polinom2);
		List* plist_temp = list_temp.plist_front;
		while (plist_temp)
		{
			plist_temp->f_value_coef *= -1;
			plist_temp = plist_temp->plist_next;
		}

		Addition(Polinom1, list_temp);
	}

	void Multiplication(List Polinom1, List Polinom2)
	{
		plist_front = NULL;
		List* plist_temp1 = Polinom1.plist_front;

		while (plist_temp1)
		{
			List* plist_temp2 = Polinom2.plist_front;

			float f_temp_coef = plist_temp1->f_value_coef;
			float f_temp_grad = plist_temp1->f_value_grad;

			while (plist_temp2)
			{
				Push(f_temp_coef * plist_temp2->f_value_coef, f_temp_grad + plist_temp2->f_value_grad);
				plist_temp2 = plist_temp2->plist_next;
			}

			plist_temp1 = plist_temp1->plist_next;
		}
	}

	void Scalar_Multiplication(List Polinom, float f_scalar)
	{
		plist_front = NULL;
		List* plist_temp1 = Polinom.plist_front;

		while (plist_temp1)
		{
			Push(plist_temp1->f_value_coef * f_scalar, plist_temp1->f_value_grad);
			plist_temp1 = plist_temp1->plist_next;
		}
	}

	void Derivative(List Polinom)
	{
		plist_front = NULL;
		List* plist_temp1 = Polinom.plist_front;

		while (plist_temp1)
		{
			if (plist_temp1->f_value_grad - 1 >= 0)
			{
				Push(plist_temp1->f_value_coef * plist_temp1->f_value_grad, plist_temp1->f_value_grad - 1);
			}

			plist_temp1 = plist_temp1->plist_next;
		}
	}

	void Integral(List Polinom)
	{
		plist_front = NULL;
		List* plist_temp1 = Polinom.plist_front;

		while (plist_temp1)
		{
			Push(plist_temp1->f_value_coef / (plist_temp1->f_value_grad + 1), plist_temp1->f_value_grad + 1);
			plist_temp1 = plist_temp1->plist_next;
		}
	}

	std::vector<float> Find_Divisors(int i_number)
	{
		std::vector<float> v_temp_divisors;

		for (int i = 1;i <= abs(i_number);i++)
		{
			if (!(i_number % i))
			{
				v_temp_divisors.push_back(i);
				v_temp_divisors.push_back(-i);
			}
		}

		return v_temp_divisors;
	}

	std::vector<float> Find_Posibile_Solutions(std::vector<float> v_first_number_divisors, std::vector<float> v_last_number_divisors)
	{
		std::vector<float> v_temp_possible_solutions;

		for (int i = 0;i < v_first_number_divisors.size();i++)
		{
			for (int j = 0;j < v_last_number_divisors.size();j++)
			{
				v_temp_possible_solutions.push_back(v_last_number_divisors[j] / v_first_number_divisors[i]);
			}
		}

		sort(v_temp_possible_solutions.begin(), v_temp_possible_solutions.end());
		v_temp_possible_solutions.erase(unique(v_temp_possible_solutions.begin(), v_temp_possible_solutions.end()), v_temp_possible_solutions.end());

		return v_temp_possible_solutions;
	}

	void Solutions(std::vector<float> v_possible_solutions,List Polinom)
	{
		std::vector<float> v_solutions;

		for (int i = 0;i < v_possible_solutions.size();i++)
		{
			List* plist_temp = Polinom.plist_front;
			float f_result = 0;

			while (plist_temp)
			{
				f_result += pow(v_possible_solutions[i], plist_temp->f_value_grad) * plist_temp->f_value_coef;
				
				plist_temp = plist_temp->plist_next;
			}

			if (!f_result)
			{
				v_solutions.push_back(v_possible_solutions[i]);
			}
		}

		if (v_solutions.size())
		{
			std::cout << "Solutiile sunt: {";
			for (int i = 0;i < v_solutions.size() - 1;i++)
			{
				std::cout << v_solutions[i] << ",";
			}
			std::cout << v_solutions[v_solutions.size() - 1] << "}\n\n";
		}
		else
		{
			std::cout << "Polinomul nu are solutii reale.\n\n";
		}
	}

	void Real_Roots(List Polinom)
	{
		plist_front = NULL;
		List* plist_temp_front = Polinom.plist_front;
		List* plist_temp_rear = Polinom.plist_rear;

		if (!plist_temp_rear->f_value_grad)
		{
			std::vector<float> v_first_number_divisors = Find_Divisors((int)plist_temp_front->f_value_coef);
			std::vector<float> v_last_number_divisors = Find_Divisors((int)plist_temp_rear->f_value_coef);

			std::vector<float> v_possible_solutions = Find_Posibile_Solutions(v_first_number_divisors, v_last_number_divisors);

			Solutions(v_possible_solutions, Polinom);
		}
		else
		{
			std::cout << "Polinomul nu are radacini reale.\n\n";
		}
	}

	void Evaluation_Polynom_Point_Given(List Polinom,int i_point)
	{
		plist_front = NULL;
		List* plist_temp_front = Polinom.plist_front;
		float f_result = 0;

		while (plist_temp_front)
		{
			f_result += pow(i_point, plist_temp_front->f_value_grad) * plist_temp_front->f_value_coef;

			plist_temp_front = plist_temp_front->plist_next;
		}

		std::cout << "Rezultatul este:" << f_result << "\n\n";
	}
};

int main()
{
	List Polinom1,Polinom2;
	PolinomOperations Rezultat;

	std::cout << "Polinom 1:\n";
	Polinom1.Read();
	Polinom1.Print();

	std::cout << "Polinom 2:\n";
	Polinom2.Read();
	Polinom2.Print();

	std::cout << "Rezultat:\n";
	std::cout << "Adunare\n";
	Rezultat.Addition(Polinom1, Polinom2);
	Rezultat.Print();

	std::cout << "Scadere\n";
	Rezultat.Subtraction(Polinom1, Polinom2);
	Rezultat.Print();

	std::cout << "Inmultire\n";
	Rezultat.Multiplication(Polinom1, Polinom2);
	Rezultat.Print();

	std::cout << "Inmultire cu scalar\n";
	int i_scalar;
	std::cout << "Introduceti numarul:";
	std::cin >> i_scalar;
	Rezultat.Scalar_Multiplication(Polinom1, i_scalar);
	Rezultat.Print();

	std::cout << "Derivata\n";
	Rezultat.Derivative(Polinom1);
	Rezultat.Print();

	std::cout << "Integrala\n";
	Rezultat.Integral(Polinom1);
	Rezultat.Print();

	std::cout << "Radacini reale\n";
	Rezultat.Real_Roots(Polinom1);

	std::cout << "Evaluarea polinomului intr-un punct\n";
	int i_point;
	std::cout << "Introduceti numarul:";
	std::cin >> i_point;
	Rezultat.Evaluation_Polynom_Point_Given(Polinom1, i_point);

	return 0;
}
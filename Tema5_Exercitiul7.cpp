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

	void Print()
	{
		List* plist_temp = plist_head;

		std::cout << "Lista este:\n";
		while (plist_temp)
		{
			std::cout << plist_temp->T_value << " ";
			plist_temp = plist_temp->plist_next;
		}

		std::cout << "\n\n";
	}
};

template <class T>
class Tree
{
	T T_value;
public:
	Tree* ptree_left;
	Tree* ptree_right;

	Tree()
	{
		T_value = NULL;
		ptree_left = ptree_right = NULL;
	}

	Tree(T T_temp_value)
	{
		T_value = T_temp_value;
		ptree_left = ptree_right = NULL;
	}

	Tree* CreateNode(T T_temp_value)
	{
		Tree* ptree_temp = new Tree();
		ptree_temp->T_value = T_temp_value;

		return ptree_temp;
	}

	void Tree_To_List(List<T> &Lista)
	{
		if (ptree_left)
		{
			ptree_left->Tree_To_List(Lista);
		}

		Lista.Add_end(T_value);

		if (ptree_right)
		{
			ptree_right->Tree_To_List(Lista);
		}
	}
};

int main()
{
	Tree<int> tree_root(2);

	tree_root.ptree_left = tree_root.CreateNode(1);
	tree_root.ptree_left->ptree_left = tree_root.CreateNode(5);
	tree_root.ptree_left->ptree_right = tree_root.CreateNode(3);
	tree_root.ptree_left->ptree_right->ptree_right = tree_root.CreateNode(2);
	tree_root.ptree_left->ptree_right->ptree_right->ptree_left = tree_root.CreateNode(1);
	tree_root.ptree_left->ptree_right->ptree_right->ptree_right = tree_root.CreateNode(1);
	tree_root.ptree_right = tree_root.CreateNode(6);
	tree_root.ptree_right->ptree_left = tree_root.CreateNode(9);
	tree_root.ptree_right->ptree_right = tree_root.CreateNode(8);
	tree_root.ptree_left->ptree_left->ptree_left = tree_root.CreateNode(1);
	tree_root.ptree_left->ptree_left->ptree_right = tree_root.CreateNode(7);

	List<int>Lista_Dubla_Inlantuita;

	tree_root.Tree_To_List(Lista_Dubla_Inlantuita);

	Lista_Dubla_Inlantuita.Print();

	return 0;
}
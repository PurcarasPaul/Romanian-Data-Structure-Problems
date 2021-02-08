#include <iostream>

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

	int Count_Nodes()
	{
		if (T_value)
		{
			int i_nodes = 1;

			if (ptree_left)
			{
				i_nodes += ptree_left->Count_Nodes();
			}

			if (ptree_right)
			{
				i_nodes += ptree_right->Count_Nodes();
			}

			return i_nodes;
		}
		else
		{
			return 0;
		}
	}
};

int main()
{
	Tree<int> tree_root(2);

	tree_root.ptree_left=tree_root.CreateNode(1);
	tree_root.ptree_left->ptree_left=tree_root.CreateNode(5);
	tree_root.ptree_left->ptree_right = tree_root.CreateNode(3);
	tree_root.ptree_left->ptree_right->ptree_right = tree_root.CreateNode(2);
	tree_root.ptree_left->ptree_right->ptree_right->ptree_left = tree_root.CreateNode(1);
	tree_root.ptree_left->ptree_right->ptree_right->ptree_right = tree_root.CreateNode(1);
	tree_root.ptree_right = tree_root.CreateNode(6);
	tree_root.ptree_left->ptree_left->ptree_left = tree_root.CreateNode(1);
	tree_root.ptree_left->ptree_left->ptree_right = tree_root.CreateNode(7);

	std::cout << "Numarul de noduri din arbore este:" << tree_root.Count_Nodes() << "\n";

	return 0;
}
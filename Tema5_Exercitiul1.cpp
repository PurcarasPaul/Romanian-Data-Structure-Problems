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

	int Num_Of_Leaves()
	{
		int i_leaves = 0;

		if (!ptree_left && !ptree_right)
		{
			i_leaves++;
		}

		if (ptree_left)
		{
			i_leaves += ptree_left->Num_Of_Leaves();
		}

		if (ptree_right)
		{
			i_leaves += ptree_right->Num_Of_Leaves();
		}

		return i_leaves;
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

	std::cout << "Numarul de noduri frunza din arbore este:"<<tree_root.Num_Of_Leaves()<<"\n";

	return 0;
}
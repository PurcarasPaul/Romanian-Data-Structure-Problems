#include <iostream>
#include <algorithm>

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

	void Height(int i_temp_height,int &i_max_height)
	{
		if (!this)
		{
			return;
		}
		else
		{
			i_temp_height++;

			i_max_height = std::max(i_max_height, i_temp_height);

			if (ptree_left)
			{
				ptree_left->Height(i_temp_height, i_max_height);
			}

			if (ptree_right)
			{
				ptree_right->Height(i_temp_height, i_max_height);
			}
		}
	}
};

int main()
{
	Tree<int> tree_root(2);
	int i_max_height = 0;

	tree_root.ptree_left=tree_root.CreateNode(1);
	tree_root.ptree_left->ptree_left=tree_root.CreateNode(5);
	tree_root.ptree_left->ptree_right = tree_root.CreateNode(3);
	tree_root.ptree_left->ptree_right->ptree_right = tree_root.CreateNode(2);
	tree_root.ptree_left->ptree_right->ptree_right->ptree_left = tree_root.CreateNode(1);
	tree_root.ptree_left->ptree_right->ptree_right->ptree_right = tree_root.CreateNode(1);
	tree_root.ptree_right = tree_root.CreateNode(6);
	tree_root.ptree_left->ptree_left->ptree_left = tree_root.CreateNode(1);
	tree_root.ptree_left->ptree_left->ptree_right = tree_root.CreateNode(7);

	tree_root.Height(0, i_max_height);

	std::cout << "Inaltimea este:" << i_max_height << "\n";

	return 0;
}
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

	void Height(int i_temp_height, int& i_max_height)
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

	int Get_Width(int i_level)
	{
		if (!this)
		{
			return 0;
		}
		else if (!i_level)
		{
			return 1;
		}
		else if (i_level)
		{
			return ptree_left->Get_Width(i_level - 1) + ptree_right->Get_Width(i_level - 1);
		}
	}

	int Get_Max_Width()
	{
		int i_max_height, i_max_width = 0;
		Height(0, i_max_height);

		for (int i = 0;i < i_max_height;i++)
		{
			int i_temp_width = Get_Width(i);

			i_max_width = std::max(i_max_width, i_temp_width);
		}

		return i_max_width;
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

	std::cout << "Latimea maxima este:" << tree_root.Get_Max_Width() << "\n";

	return 0;
}
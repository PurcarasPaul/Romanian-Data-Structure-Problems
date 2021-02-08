#include <iostream>

template <class T>
class Tree
{
	T T_value;
public:
	Tree* ptree_left;
	Tree* ptree_right;
	Tree* ptree_parent;

	Tree()
	{
		T_value = 0;
		ptree_left = ptree_right = ptree_parent = NULL;
	}

	Tree(T T_temp_value)
	{
		T_value = T_temp_value;
		ptree_left = ptree_right = NULL;
		ptree_parent = NULL;
	}

	void Parent()
	{
		if (ptree_left)
		{
			ptree_left->ptree_parent = this;
			ptree_left->Parent();
		}

		if (ptree_right)
		{
			ptree_right->ptree_parent = this;
			ptree_right->Parent();
		}
	}

	Tree* CreateNode(T T_temp_value)
	{
		Tree* ptree_temp = new Tree();
		ptree_temp->T_value = T_temp_value;

		return ptree_temp;
	}

	void Print_Inorder()
	{
		Tree* ptree_root = this;
		bool IsLeftDone = false;

		std::cout << "\nArborele este:";

		while (ptree_root)
		{
			if (!IsLeftDone)
			{
				while (ptree_root->ptree_left)
				{
					ptree_root = ptree_root->ptree_left;
				}
			}

			std::cout << ptree_root->T_value << " ";

			IsLeftDone = ptree_root;

			if (ptree_root->ptree_right)
			{
				IsLeftDone = false;
				ptree_root = ptree_root->ptree_right;
			}
			else if (ptree_root->ptree_parent)
			{
				while (ptree_root->ptree_parent && ptree_root == ptree_root->ptree_parent->ptree_right)
				{
					ptree_root = ptree_root->ptree_parent;
				}

				if (!ptree_root->ptree_parent)
				{
					break;
				}

				ptree_root = ptree_root->ptree_parent;
			}
			else
			{
				break;
			}
		}

		std::cout << "\n\n";
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
	tree_root.ptree_left->ptree_left->ptree_left = tree_root.CreateNode(1);
	tree_root.ptree_left->ptree_left->ptree_right = tree_root.CreateNode(7);

	//Cerinta a)
	tree_root.Parent();

	std::cout << "Cerinta b)\n";
	tree_root.Print_Inorder();

	return 0;
}
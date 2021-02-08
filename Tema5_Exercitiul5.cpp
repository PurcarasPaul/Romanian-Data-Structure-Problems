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

	Tree* Insert(T T_temp_value)
	{
		if (!this)
		{
			return CreateNode(T_temp_value);
		}

		if (T_temp_value < T_value)
		{
			ptree_left = ptree_left->Insert(T_temp_value);
		}
		else
		{
			ptree_right = ptree_right->Insert(T_temp_value);
		}

		return this;
	}

	void Print_Inorder()
	{
		if (ptree_left)
		{
			ptree_left->Print_Inorder();
		}

		std::cout << T_value << " ";

		if (ptree_right)
		{
			ptree_right->Print_Inorder();
		}
	}

	Tree* Max_Value()
	{
		Tree* ptree_temp = this;

		while (ptree_temp && ptree_temp->ptree_right)
		{
			ptree_temp = ptree_temp->ptree_right;
		}

		return ptree_temp;
	}

	Tree* Delete_Node(T T_value_to_be_deleted)
	{
		if (!this)
		{
			return this;
		}

		if (T_value_to_be_deleted < T_value)
		{
			ptree_left = ptree_left->Delete_Node(T_value_to_be_deleted);
		}
		else if (T_value_to_be_deleted > T_value)
		{
			ptree_right = ptree_right->Delete_Node(T_value_to_be_deleted);
		}
		else 
		{
			if (!ptree_left)
			{
				Tree* ptree_temp = ptree_right;

				free(this);

				return ptree_temp;
			}
			else if (!ptree_right)
			{
				Tree* ptree_temp = ptree_left;

				free(this);

				return ptree_temp;
			}
			else if (ptree_left && ptree_right)
			{
				Tree* ptree_temp = ptree_left->Max_Value();

				T_value = ptree_temp->T_value;

				ptree_left = ptree_left->Delete_Node(ptree_temp->T_value);
			}
		}

		return this;
	}
};

int main()
{
	Tree<int>* tree_root = NULL;

	tree_root = tree_root->Insert(5);
	tree_root = tree_root->Insert(3);
	tree_root = tree_root->Insert(2);
	tree_root = tree_root->Insert(4);
	tree_root = tree_root->Insert(7);
	tree_root = tree_root->Insert(6);
	tree_root = tree_root->Insert(9);

	tree_root->Print_Inorder();
	std::cout << "\n";

	tree_root->Delete_Node(2);
	tree_root->Print_Inorder();
	std::cout << "\n";

	tree_root->Delete_Node(3);
	tree_root->Print_Inorder();
	std::cout << "\n";

	tree_root->Delete_Node(5);
	tree_root->Print_Inorder();
	std::cout << "\n";

	return 0;
}
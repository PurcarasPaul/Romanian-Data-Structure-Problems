#include <iostream>
#include <vector>

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

	Tree* TreeRecover(std::vector<int>& v_preorder, std::vector<int>& v_postorder,int &i_preorder_index,int &i_postorder_index)
	{
		Tree* ptree_temp = new Tree(v_preorder[i_preorder_index++]);

		if (ptree_temp->T_value != v_postorder[i_postorder_index])
		{
			ptree_temp->ptree_left = TreeRecover(v_preorder, v_postorder, i_preorder_index, i_postorder_index);
		}

		if (ptree_temp->T_value != v_postorder[i_postorder_index])
		{
			ptree_temp->ptree_right = TreeRecover(v_preorder, v_postorder, i_preorder_index, i_postorder_index);
		}

		i_postorder_index++;

		return ptree_temp;
	}
};

int main()
{
	std::vector<int> v_preorder = { 1, 2, 4, 8, 9, 5, 3, 6, 7 };
	std::vector<int> v_postorder = { 8, 9, 4, 5, 2, 6, 7, 3, 1 };

	int i_preorder_index = 0, i_postorder_index = 0;

	Tree<int>* tree_root = NULL;
	tree_root = tree_root->TreeRecover(v_preorder, v_postorder, i_preorder_index, i_postorder_index);

	std::cout << "Arborele este:";
	tree_root->Print_Inorder();
	std::cout << "\n\n";

	return 0;
}
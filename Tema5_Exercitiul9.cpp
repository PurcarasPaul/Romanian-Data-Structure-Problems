#include <iostream>
#include <vector>
#include <unordered_map>

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

	void Print_Preorder()
	{
		std::cout << T_value << " ";

		if (ptree_left)
		{
			ptree_left->Print_Preorder();
		}

		if (ptree_right)
		{
			ptree_right->Print_Preorder();
		}
	}

	Tree* TreeRecover(std::vector<int> v_inorder, std::vector<int> v_postorder, int i_start, int i_end,int *pi_index, std::unordered_map<int, int>& unordered_map_index)
	{
		if (i_start > i_end)
		{
			return NULL;
		}

		int i_temp = v_postorder[*pi_index];

		Tree* ptree_temp = CreateNode(i_temp);

		(*pi_index)--;

		if (i_start == i_end)
		{
			return ptree_temp;
		}

		int i_index = unordered_map_index[i_temp];

		ptree_temp->ptree_right = TreeRecover(v_inorder, v_postorder, i_index + 1, i_end, pi_index, unordered_map_index);
		ptree_temp->ptree_left = TreeRecover(v_inorder, v_postorder, i_start, i_index - 1, pi_index, unordered_map_index);

		return ptree_temp;
	}
};

int main()
{
	std::vector<int> v_inorder = { 4,2,5,1,3 };
	std::vector<int> v_postorder = { 4,5,2,3,1 };

	std::unordered_map<int, int>unordered_map_index;
	for (int i = 0;i < v_inorder.size();i++)
	{
		unordered_map_index[v_inorder[i]] = i;
	}
	int i_index = v_inorder.size() - 1;

	Tree<int>* tree_root = NULL;
	tree_root = tree_root->TreeRecover(v_inorder, v_postorder, 0, v_inorder.size() - 1, &i_index, unordered_map_index);

	std::cout << "Arborele este:";
	tree_root->Print_Preorder();
	std::cout << "\n\n";

	return 0;
}
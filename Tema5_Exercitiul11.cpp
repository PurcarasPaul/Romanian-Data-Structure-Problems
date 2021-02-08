#include <iostream>
#include <string>

class Tree
{
	std::string s_word, s_word_translation;
public:
	Tree* ptree_left;
	Tree* ptree_right;

	Tree()
	{
		ptree_left = ptree_right = NULL;
	}

	Tree* CreateNode(std::string s_temp_word, std::string s_temp_word_translation)
	{
		Tree* ptree_temp = new Tree();

		ptree_temp->s_word = s_temp_word;
		ptree_temp->s_word_translation = s_temp_word_translation;

		return ptree_temp;
	}

	Tree* Insert(std::string s_temp_word, std::string s_temp_word_translation)
	{
		if (!this)
		{
			return CreateNode(s_temp_word, s_temp_word_translation);
		}

		if (s_temp_word < s_word)
		{
			ptree_left = ptree_left->Insert(s_temp_word, s_temp_word_translation);
		}
		else
		{
			ptree_right = ptree_right->Insert(s_temp_word, s_temp_word_translation);
		}

		return this;
	}

	void Print_Preorder()
	{
		std::cout << s_word << "=" << s_word_translation << "\n";

		if (ptree_left)
		{
			ptree_left->Print_Preorder();
		}

		if (ptree_right)
		{
			ptree_right->Print_Preorder();
		}
	}

	std::string Search_Romanian_Word(std::string s_word_to_find)
	{
		if (!this || s_word == s_word_to_find)
		{
			return s_word_translation;
		}

		if (ptree_right)
		{
			return ptree_right->Search_Romanian_Word(s_word_to_find);
		}

		if (ptree_left)
		{
			return ptree_left->Search_Romanian_Word(s_word_to_find);
		}
	}

	std::string Search_English_Word(std::string s_word_to_find)
	{
		if (!this || s_word_translation == s_word_to_find)
		{
			return s_word;
		}

		if (ptree_right)
		{
			return ptree_right->Search_English_Word(s_word_to_find);
		}

		if (ptree_left)
		{
			return ptree_left->Search_English_Word(s_word_to_find);
		}
	}
};

void Read(Tree* &tree_root)
{
	int i_words;

	std::cout << "Introduceti numarul de cuvinte:";
	std::cin >> i_words;

	for (int i = 0;i < i_words;i++)
	{
		std::string s_temp_word, s_temp_word_translation;

		std::cout << "Introduceti cuvantul " << i + 1 << ":";
		std::cin >> s_temp_word;

		std::cout << "Introduceti traducerea in limba engleza:";
		std::cin >> s_temp_word_translation;

		tree_root=tree_root->Insert(s_temp_word, s_temp_word_translation);
	}
}

int main()
{
	Tree* tree_root = NULL;

	std::cout << "Cerinta a):\n";
	Read(tree_root);
	std::cout << "\nArborele este:\n";
	tree_root->Print_Preorder();

	std::string s_temp_word_to_find;
	std::cout << "\nIntroduceti cuvantul cautat:";
	std::cin >> s_temp_word_to_find;
	std::cout << "\nCuvantul cautat este " << s_temp_word_to_find << ",iar traducerea lui este " << tree_root->Search_Romanian_Word(s_temp_word_to_find);


	std::cout << "\n\nCerinta b):\n";
	std::cout << "Introduceti cuvantul cautat:";
	std::cin >> s_temp_word_to_find;
	std::cout << "\nCuvantul cautat este " << s_temp_word_to_find << ",iar traducerea lui este " << tree_root->Search_English_Word(s_temp_word_to_find);

	std::cout << "\n\n";

	return 0;
}
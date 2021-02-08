#include <iostream>
#include <vector>
#include <string>

class Alphabet
{
	std::vector<char> v_letters;
public:
	void Print()
	{
		std::cout << "\nAlfabetul este:";

		for (int i = 0;i < v_letters.size();i++)
		{
			std::cout << v_letters[i] << " ";
		}

		std::cout << "\n\n";
	}

	bool isDuplicate(char c_letter)
	{
		for (int i = 0;i < v_letters.size();i++)
		{
			if (c_letter == v_letters[i])
			{
				return true;
			}
		}

		return false;
	}

	void Read()
	{
		int i_words;

		std::cout << "Introduceti numarul de cuvinte din dictionar:";
		std::cin >> i_words;

		std::cin.ignore();

		for (int i = 0;i < i_words;i++)
		{
			std::string s_temp;

			std::getline(std::cin, s_temp);

			if (!isDuplicate(s_temp[0]))
			{
				v_letters.push_back(s_temp[0]);
			}
		}
	}
};

int main()
{
	Alphabet Dictionar;

	Dictionar.Read();
	Dictionar.Print();

	return 0;
}
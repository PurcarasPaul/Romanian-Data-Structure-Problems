#include <iostream>
#include <vector>
#include <algorithm>

void Citire(int& n, float& x, std::vector<float>& S)
{
    std::cout << "Introduceti n: ";
    std::cin >> n;

    std::cout << "Introduceti x: ";
    std::cin >> x;

    for (int i = 0;i < n;i++)
    {
        float temp;

        std::cout << "S[" << i << "] = ";
        std::cin >> temp;

        S.push_back(temp);
    }
}

bool Rezolvare(int n, float x, std::vector<float> S)
{
    sort(S.begin(), S.end());

    int i = 0, j = S.size() - 1;

    while (i < j) 
    {
        if (S[i] + S[j] == x)
        {
            return true;
        }
        else if(S[i] + S[j] > x)
        {
             j--;
        }
        else
        {
            i++;
        }
    }

    return false;
}

int main()
{
    int n;
    float x;
    std::vector<float> S;

    Citire(n, x, S);

    if (Rezolvare(n, x,S))
    {
        std::cout << "Exista suma.\n";
    }
    else
    {
        std::cout << "Nu exista suma.\n";
    }

    return 0;
}
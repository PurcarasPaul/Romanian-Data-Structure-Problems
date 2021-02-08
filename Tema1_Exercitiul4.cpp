#include <iostream>
#include <vector>

void Tiparire(std::vector<int> submultimi,std::vector<int> elem,int k)
{
    std::cout << "[";

    for (int i = 0; i <= k; i++)
    {
        std::cout << submultimi[i];

        if (i != k)
        {
            std::cout << ",";
        }
    }

    std::cout << "]\n";
}

bool Verificare(std::vector<int> submultimi,int k)
{
    if (k==0 || submultimi[k] > submultimi[k - 1])
        return true;
    return false;
}

void bkt(std::vector<int> &submultimi,std::vector<int> elem,int n, int k)
{
    for (int i = 0;i < n;i++)
    {
        submultimi[k] = elem[i];

        if (Verificare(submultimi, k))
        {
            Tiparire(submultimi, elem, k);
            bkt(submultimi, elem, n, k + 1);
        }
    }
}

void Citire(int &n,std::vector<int> &elem)
{
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;

        std::cin >> temp;

        elem.push_back(temp);
    }
}

int main()
{
    int n;
    std::vector<int> elem;

    Citire(n,elem);

    std::vector<int> submultimi(n+1);

    std::cout << "[]\n";
    bkt(submultimi, elem, n, 0);

    return 0;
}
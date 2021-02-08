#include <iostream>
#include <vector>
#include <algorithm>

int Coeficient_Binomial_Iterativ_Metoda1(int n, int k)
{
    int rezultat = 1;

    for (int i = 0;i < k;i++)
    {
        rezultat *= (n - i);
        rezultat /= (i + 1);
    }

    return rezultat;
}

int Coeficient_Binomial_Iterativ_Metoda2(int n, int k)
{
    std::vector<std::vector<int>> C;

    for (int i = 0; i <= n; i++)
    {
        C.push_back(std::vector<int>());

        for (int j = 0; j <= std::min(i, k); j++)
        {
            if (j == 0 || j == i)
            {
                C[i].push_back(1);
            }
            else
            {
                C[i].push_back(C[i - 1][j - 1] + C[i - 1][j]);
            }
        }
    }

    return C[n][k];
}

float Coeficient_Binomial_Recursiv_Metoda1(float n, float k)
{
    if (k == 0)
        return 1;
    return ((n - k + 1) / k) * Coeficient_Binomial_Recursiv_Metoda1(n, k - 1);
}

int Coeficient_Binomial_Recursiv_Metoda2(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return  Coeficient_Binomial_Recursiv_Metoda2(n - 1, k - 1) + Coeficient_Binomial_Recursiv_Metoda2(n - 1, k);
}

int main()
{
    int n, k;

    std::cout << "Dati valoare pentru n: ";
    std::cin >> n;
    
    std::cout << "Dati valoare pentru k: ";
    std::cin >> k;

    std::cout << Coeficient_Binomial_Iterativ_Metoda1(n, k) << "\n";
    std::cout << Coeficient_Binomial_Iterativ_Metoda2(n, k) << "\n";

    std::cout << Coeficient_Binomial_Recursiv_Metoda1(n, k) << "\n";
    std::cout << Coeficient_Binomial_Recursiv_Metoda2(n, k) << "\n";

    return 0;
}
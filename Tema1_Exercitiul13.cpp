#include <iostream>
#include <vector>

int fibonacci_iterativ(int n, int k)
{
    std::vector<int> v_fibonacci;
    int suma = 1;

    for (int i = 0; i < k - 1; i++)
    {
        v_fibonacci.push_back(0);
    }

    v_fibonacci.push_back(1);

    for (int i = k; i <= n; i++)
    {
        v_fibonacci.push_back(suma);
        suma += v_fibonacci[i];
    }

    return v_fibonacci[n];
}

int fibonacci_recursiv(int n, int k, int& suma)
{
    if (n < k - 1)
    {
        return 0;
    }
    else if (n == k - 1)
    {
        return 1;
    }
    else
    {
        suma += fibonacci_recursiv(n - 1, k, suma);
    }

    return suma;
}

int main()
{
    int n, k, suma = 0;

    std::cout << "Introduceti n = ";
    std::cin >> n;

    std::cout << "Introduceti k = ";
    std::cin >> k;

    std::cout << "Iterativ: "<< fibonacci_iterativ(n, k) << "\n";
    std::cout << "Recursiv: " << fibonacci_recursiv(n, k, suma) << "\n";

    return 0;
}
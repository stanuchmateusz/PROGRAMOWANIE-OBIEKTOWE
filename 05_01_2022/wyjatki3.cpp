#include <iostream>
#include <cstdlib>

double sredniaHarm(double, double);

int main()
{
    double x, y, sredHarm;
    std::cout << "Prosze podac dwie liczby zmiennopozycyjne."
              << std::endl;
    std::cin >> x;
    std::cin >> y;

    try
    {
        sredHarm = sredniaHarm(x, y);
        std::cout << "Srednia harmoniczna liczb: " << x << " oraz "
                  << y << " wynosi: " << sredHarm << std::endl;
    }
    catch (const char * wyjatek)
    {
        std::cout << wyjatek << std::endl;
    }

    return 0;
}

double sredniaHarm(double x1, double y1)
{
    if (x1 == -y1)
    {
        throw "Wystapilo dzielenie przez zero. x1 = -y1 jest niedozwolone.";
    }
    return 2.0 * x1 * y1 / (x1 + y1);
}
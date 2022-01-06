#include <iostream>
#include <cstdlib>

class DzieleniePrzezZero
{
};

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
    catch (DzieleniePrzezZero & wyjatek)
    {
        std::cout << "Wystapilo dzielenie przez zero. Tutaj x1 = -y1 jest niedozwolone." << std::endl;
    }

    return 0;
}

double sredniaHarm(double x1, double y1)
{
    if (x1 == -y1)
    {
        throw DzieleniePrzezZero();
    }
    return 2.0 * x1 * y1 / (x1 + y1);
}



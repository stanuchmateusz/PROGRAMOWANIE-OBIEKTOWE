#include <iostream>

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
    catch (int a)
    {
        std::cout << "Kod bledu: " << a 
                  << "\nWystapilo dzielenie przez zero. Tutaj x1 = -y1"
                  << "jest niedozwolone." << std::endl;
    }

    /* Nie zawsze potrzebujemy uzyc obiektu, ktory zostal "rzucony":
    catch (int)
    {
        std::cout << "Wystapilo dzielenie przez zero. Tutaj x1 = -y1"
                  << "jest niedozwolone." << std::endl;
    }
    */

    return 0;
}

double sredniaHarm(double x1, double y1)
{
    if (x1 == -y1)
    {
        throw 1;
    }
    return 2.0 * x1 * y1 / (x1 + y1);
}
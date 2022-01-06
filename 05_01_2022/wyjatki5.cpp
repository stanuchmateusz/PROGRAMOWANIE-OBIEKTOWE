#include <iostream>
#include <cstdlib>

class BledneDzialanie
{
public:
    void wypisz() { std::cout << "Blad - nie mozna wykonac takiego dzialania!" << std::endl; }
};

class DzieleniePrzezZero : public BledneDzialanie
{
public:
    void wypisz() { std::cout << "Blad dzielenia: nie da sie podzielic przez zero" << std::endl; }
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
        wyjatek.wypisz();
    }
    catch (BledneDzialanie & wyjatek)
    {
        wyjatek.wypisz();
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
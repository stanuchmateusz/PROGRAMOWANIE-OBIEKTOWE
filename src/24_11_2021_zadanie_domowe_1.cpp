// 1. Przenieść liczenie sumy pól różnych wielokątów do osobnej funkcji.
// Funkcja w argumentach otrzymuje tablicę wskaźników oraz rozmiar tej tablicy i zwraca wyliczoną sumę.
#include <iostream>

class Wielokat
{

public:
    Wielokat(){};
    ~Wielokat(){};
    virtual double oblicz_pole() { return 0; }
};
class Trojkat : public Wielokat
{
private:
    double a, h;

public:
    Trojkat(double podstawa, double wysokosc) : a(podstawa), h(wysokosc){};
    ~Trojkat(){};
    double oblicz_pole()
    {
        return 0.5 * a * h;
    }
};
class Prostakat : public Wielokat
{
private:
    double a, b;

public:
    Prostakat(double podstawa, double wysokosc) : a(podstawa), b(wysokosc){};
    ~Prostakat(){};
    double oblicz_pole()
    {
        return a * b;
    }
};

class Kwadrat : public Prostakat
{
public:
    Kwadrat(double a) : Prostakat(a, a) {}
    ~Kwadrat() {}
};

double suma_pol(Wielokat *tablica[], int rozmiar)
{
    double suma;
    for (int i = 0; i < rozmiar; i++)
    {
        suma += tablica[i]->oblicz_pole();
    }
    return suma;
}

int main()
{
    Wielokat *figury[3];
    figury[0] = new Trojkat(21, 37);
    figury[1] = new Prostakat(21, 37);
    figury[2] = new Kwadrat(21.37);
    std::cout << suma_pol(figury, 3) << std::endl;
    for (auto &&i : figury)
    {
        delete i;
    }

    return 0;
}
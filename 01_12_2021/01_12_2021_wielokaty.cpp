// 1. Przeanalizować przykład "klasy_abstrakcyjne.cpp" i "polimorfizm_destruktory.cpp".
// 2. Zmienić klasę Wielokat z zadania domowego tak, by była klasą abstrakcyjną. Sprawdzić, czy uda się utworzyć obiekt klasy Wielokat w funkcji main() i czy wcześniej napisany kod (funkcja licząca sumę różnych wielokątów) nadal działa.
// 3. Dopisać destruktory w dotychczas stworzonych programach używających dziedziczenia (wielokąty, pracownicy) tak, żeby pamięć była zwalniana w prawidłowy sposób.

#include <iostream>

class Wielokat
{

public:
    Wielokat(){};
    virtual ~Wielokat(){};
    virtual double oblicz_pole() = 0;
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

    // Wielokat test; <- zwraca błąd

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
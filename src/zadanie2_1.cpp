// Zad.1. Napisz klasę rezeprezentującą liczbę zespoloną (zawiera dwa pola całkowite).
// Stwórz konstruktor domyślny, który pozwoli też na przekazanie argumentów przez użytkownika oraz konstruktor kopiujący.
// Klasa ma też zawierać metodę do wypisywania danej liczby (w formacie: "a ± bi"),
// jak również funkcje pozwalające dodać i odjąć dwie liczby zespolone.
// Logika dodawania i odejmowania liczb zespolonych:
// (a±bi) ± (c±di) = (a±c) ± (b±d)i
// (zob. też: przykład 1. ze strony https://www.matemaks.pl/proste-dzialania-na-liczbach-zespolonych.html)

// W funkcji main stworzyć kilka instancji napisanej klasy, wykorzystać każdy typ konstruktora, przetestować działanie funkcji dodających i odejmujących liczby zespolone.

// Dodawanie i odejmowanie napisać zarówno jako metodę należącą do klasy, jak i zewnętrzną funkcję poza klasą.
// Zastanowić się, jakie są konsekwencje napisania takiej operacji dodawania lub mnożenia za pomocą zewnętrznej funkcji,
// w porównaniu do metody, która jest częścią klasy.
#include <iostream>
class zespolona
{
private:
    double a, b;

public:
    double getA() { return a; }
    double getB() { return b; }
    void wypisz()
    {
        std::cout << a << ((b > 0) ? "+" : "") << b << "i" << std::endl;
    };
    zespolona *dodaj(zespolona &druga)
    {
        return new zespolona(a + druga.a, b + druga.b);
    };
    zespolona *odejmij(zespolona &druga)
    {
        return new zespolona(a - druga.a, b - druga.b);
    };
    zespolona(double rzeczywista, double zespolona)
    {
        a = rzeczywista;
        b = zespolona;
    };
    zespolona(zespolona &z)
    {
        a = z.a;
        b = z.b;
    };
    ~zespolona(){};
};
zespolona *dodaj(zespolona &pierwsza, zespolona &druga)
{
    return new zespolona(pierwsza.getA() + druga.getA(), pierwsza.getB() + druga.getB());
};
zespolona *odejmij(zespolona &pierwsza, zespolona &druga)
{
    return new zespolona(pierwsza.getA() - druga.getA(), pierwsza.getB() - druga.getB());
};

double main()
{
    zespolona z1(1, 3);
    zespolona z2(z1);
    z1.wypisz();
    z2.wypisz();
    zespolona *wynik1 = z1.dodaj(z2);
    wynik1->wypisz();

    zespolona *wynik2 = odejmij(z1, *wynik1);
    wynik2->wypisz();

    delete wynik1, wynik2;

    return 0;
}
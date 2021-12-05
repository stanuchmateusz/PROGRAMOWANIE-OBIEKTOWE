// Wybierz i umieść w programie dwie dowolne z dotychczas napisanych konkretnych klas,
//  które nie są powiązane ze sobą relacją dziedziczenia (np. klasa Koło i Pracownik, Prostokat i Ulamek itd.)
// Stwórz klasę abstrakcyjną, która będzie umożliwiała stworzenie interfejsu służącego do zapisywania dowolnej klasy do pliku tekstowego.
//  Klasa ma jedną metodę, która realizuje zapis do pliku przekazanego w jej argumencie.
// Zmień dwie pierwotne klasy tak, by dziedziczyły z tej klasy abstrakcyjnej.
// Przetestuj w programie zapis do jednego pliku tekstowego wielu obiektów z różnych klas
// , np. w pętli (analogicznie do zadania z sumowaniem pól wielokątów).
#include <iostream>
#include <fstream>

class Zapisywanie // klasa abstrakcyjna
{
public:
    Zapisywanie() {}
    virtual ~Zapisywanie() {}
    virtual void zapisz_do_pliku(std::ofstream &plik_do_zapisu) = 0;
};

class Fraction : public Zapisywanie // klasa ułamek
{
private:
    int nominator, denominator;
    double *dvalue;

public:
    Fraction(int n, int d) : nominator(n), denominator(d)
    {
        double dou = (double)n / d;
        dvalue = new double(dou);
    };
    ~Fraction() { delete dvalue; }
    void print()
    {
        std::cout << "Ulamek " << nominator << "/" << denominator << " (" << *dvalue << ")\n";
    }
    void zapisz_do_pliku(std::ofstream &plik_do_zapisu)
    {
        plik_do_zapisu << "Ułamek " << nominator << "/" << denominator << " (" << *dvalue << ")\n";
    };
};

class Trojkat : public Zapisywanie // klasa trójkąt
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
    void zapisz_do_pliku(std::ofstream &plik_do_zapisu)
    {
        plik_do_zapisu << "Trójkąt a = " << a << ", h = " << h << " | Pole = " << 0.5 * a * h << "\n";
    };
};

int main()
{
    std::ofstream plik;
    plik.open("out_klasy.txt");

    if (!plik.is_open())
        return -1;

    Zapisywanie *klasy_do_wypisania[4];
    klasy_do_wypisania[0] = new Fraction(13, 37);
    klasy_do_wypisania[1] = new Trojkat(6, 9);
    klasy_do_wypisania[2] = new Fraction(4, 20);
    klasy_do_wypisania[3] = new Trojkat(21, 37);

    for (auto &&i : klasy_do_wypisania)
        i->zapisz_do_pliku(plik);

    for (auto &&i : klasy_do_wypisania)
        delete i;

    plik.close();
    return 0;
}
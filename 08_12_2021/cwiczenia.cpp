// Przeciążyć dla klasy Ulamek operatory:
// - dodawania,
// - odejmowania,
// - mnożenia,
// - dzielenia,
// - jednoargumentowy operator-,
// - operator[]
// - operatory porównania (==, !=, >, >= itd.).
//  Część (około połowę) z nich napisać jako zewnętrzne funkcje zaprzyjaźnione, a pozostałe jako metody klasy.
#include <iostream>

class Fraction // klasa ułamek
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
    int getNominator() { return nominator; };
    int getDenominator() { return denominator; };
    double *getDvalue() { return dvalue; };
    ~Fraction() { delete dvalue; }
    void print()
    {
        std::cout << "Ulamek " << nominator << "/" << denominator << " (" << *dvalue << ")\n";
    }
    void skroc()
    {
        bool dodatni = this->nominator > 0 ? true : false;
        int a = dodatni ? this->nominator : -1 * this->nominator;
        int b = this->denominator;

        while (a != b)
            if (a > b)
                a -= b; // lub a = a - b;
            else
                b -= a; // lub b = b-a
        this->nominator /= a;
        this->denominator /= b;
        if (!dodatni)
            this->nominator *= -1;
    }

    Fraction operator+(const Fraction &f)
    {

        if (this->denominator == f.denominator)
        {
            Fraction *x = new Fraction(this->nominator + f.nominator, this->denominator);
            x->skroc();
            return *x;
        }
        else
        {
            Fraction *x = new Fraction(
                this->nominator * f.denominator + f.nominator * this->denominator,
                this->denominator * f.denominator);
            x->skroc();
            return *x;
        }
    }
    Fraction operator-(const Fraction &f)
    {

        if (this->denominator == f.denominator)
        {
            Fraction *x = new Fraction(this->nominator - f.nominator, this->denominator);
            x->skroc();
            return *x;
        }
        else
        {
            Fraction *x = new Fraction(
                this->nominator * f.denominator - f.nominator * this->denominator,
                this->denominator * f.denominator);
            x->skroc();
            return *x;
        }
    }
    Fraction operator*(const Fraction &f)
    {
        Fraction *x = new Fraction(
            this->nominator * f.nominator,
            this->denominator * f.denominator);
        x->skroc();
        return *x;
    }
    Fraction operator/(const Fraction &f)
    {
        Fraction odwrotnoscf(f.denominator, f.nominator);
        return *this * odwrotnoscf;
    }
    Fraction operator-()
    {
        return *(new Fraction(
            -this->nominator,
            this->denominator));
    }
    int operator[](int i)
    {
        if (i == 0)
            return this->nominator;
        else if (i == 1)
            return this->denominator;
        else
        {
            std::cout << "Bad index" << std::endl;
            return -1;
        }
    }
    friend bool operator==(const Fraction &t, const Fraction &f);
    friend bool operator<=(const Fraction &t, const Fraction &f);
    friend bool operator<(const Fraction &t, const Fraction &f);
    friend bool operator>=(const Fraction &t, const Fraction &f);
    bool operator>(const Fraction &f)
    {
        if (this->dvalue > f.dvalue)
            return true;
        return false;
    };
    bool operator!=(const Fraction &f)
    {
        Fraction t(*this);
        t.skroc();

        Fraction y(f);
        y.skroc();

        if (t.getNominator() != y.getNominator() || t.getDenominator() != y.getDenominator())
            return true;
        return false;
    };
};
bool operator==(const Fraction &t, const Fraction &f)
{
    Fraction x(t);
    x.skroc();

    Fraction y(f);
    y.skroc();

    if (x.getNominator() == y.getNominator() && x.getDenominator() == y.getDenominator())
        return true;
    return false;
};
bool operator<=(const Fraction &t, const Fraction &f)
{
    Fraction x(t.nominator, t.denominator);
    x.skroc();

    Fraction y(f.nominator, f.denominator);
    y.skroc();

    if (x.getDvalue() <= y.getDvalue() || (x.getNominator() == y.getNominator() && x.getDenominator() == y.getDenominator()))
        return true;
    return false;
};
bool operator<(const Fraction &t, const Fraction &f)
{
    if (*t.dvalue < *f.dvalue)
        return true;
    return false;
};
bool operator>=(const Fraction &t, const Fraction &f)
{
    Fraction x(t.nominator, t.denominator);
    x.skroc();

    Fraction y(f.nominator, f.denominator);
    y.skroc();

    if (*t.dvalue >= *f.dvalue || (x.nominator == y.nominator && x.denominator == y.denominator))
        return true;
    return false;
};
int main()
{
    Fraction x(5, 4);
    Fraction y(10, 8);

    Fraction wynik = x + y;

    // std::cout << ((x >= y) ? "Prawda" : "Falsz") << std::endl;

    wynik.print();
    wynik = -y;
    wynik.print();

    return 0;
}

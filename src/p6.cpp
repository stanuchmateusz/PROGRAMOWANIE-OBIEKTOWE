#include <iostream>
//ulamek licznik mianownik i wskaźnik na typ zmiennoprzecinkowy
struct fraction
{
    int nominator;
    int denominator;
    double *dvalue;
    fraction(int n, int d) : nominator(n), denominator(d)
    {
        double dou = (double)n / d;
        dvalue = new double(dou);
    };
    void print()
    {
        std::cout << "Ulamek " << nominator << "/" << denominator << " (" << *dvalue << ")\n";
    }
    ~fraction()
    {
        delete dvalue;
    }
};

int main()
{
    fraction *uom = new fraction(4, 5);
    uom->print();

    delete uom;
    uom->print();

    return 0;
}
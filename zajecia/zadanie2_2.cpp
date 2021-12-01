// Zad.2. Napisz funkcję swap(), która pozwoli na zamianę wartościami dwóch obiektów klasy reprezentującej Ułamek, którą pisaliśmy na ostatnich zajęciach.
// Zamieniane obiekty funkcja musi otrzymać w odpowiedni sposób w argumentach.
// Przykład:
// Ulamek u1(1,2); Ulamek u2(3,4);
// swap(...); // wywolanie swap
// cout << u1.licznik << u1.mianownik << *(u1.dwartosc); // po zamianie wypisze 3 4 0.75

#include <iostream>
class Fraction
{
private:
    int nominator;
    int denominator;
    double *dvalue;

public:
    int getNominator() { return nominator; }
    void setNominator(int nom) { nominator = nom; }

    int getDenominator() { return denominator; }
    void setDenominator(int denom) { denominator = denom; }

    void setDvalue(double *dv) { dvalue = dv; };

    Fraction(int n, int d) : nominator(n), denominator(d)
    {
        double dou = (double)n / d;
        dvalue = new double(dou);
    };
    Fraction(Fraction &fr)
    {
        nominator = fr.getNominator();
        denominator = fr.getDenominator();
        dvalue = new double((double)nominator / denominator);
    };
    void print()
    {
        std::cout << "Ulamek " << nominator << "/" << denominator << " (" << *dvalue << ")\n";
    }
    ~Fraction() { delete dvalue; }
};

void swap(Fraction &u1, Fraction &u2)
{
    Fraction temp(u1);
    u1.setNominator(u2.getNominator());
    u1.setDenominator(u2.getDenominator());
    u1.setDvalue(new double((double)u2.getNominator() / u2.getDenominator()));
    u2 = Fraction(temp);
    u2.setDvalue(new double((double)u2.getNominator() / u2.getDenominator()));
    std::cout << "ZAMIANA" << std::endl;
};

int main()
{
    Fraction u1(1, 3);
    Fraction u2(4, 8);
    u1.print();
    u2.print();
    swap(u1, u2);
    u1.print();
    u2.print();

    return 0;
}
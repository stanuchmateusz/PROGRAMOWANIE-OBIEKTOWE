// napisać clasę fraction napisać kontruktory, 2 , jeden 2 parametry, a drugi kopiujący
//  2 x int wskaźnik na double
//

#include <iostream>
class Fraction
{
private:
    int nominator;
    int denominator;
    double *dvalue;

public:
    int getNominator()
    {
        return nominator;
    }
    void setNominator(int nom)
    {
        nominator = nom;
    }

    int getDenominator()
    {
        return denominator;
    }
    void setDenominator(int denom)
    {
        denominator = denom;
    }

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
    ~Fraction()
    {
        delete dvalue;
    }
};

int main()
{
    Fraction u1(1, 3);
    Fraction u2(u1);

    u1.print();
    u2.print();

    return 0;
}
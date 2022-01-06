#include <iostream>
class Fraction
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

    operator double()
    {
        return *this->dvalue;
    }
    Fraction &operator=(Fraction &f)
    {
        if (*this == f)
            return *this;
        this->nominator = f.nominator;
        this->denominator = f.denominator;
        delete this->dvalue;
        this->dvalue = f.dvalue;
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &, Fraction &);
    friend std::istream &operator>>(std::istream &, Fraction &);
};
std::ostream &operator<<(std::ostream &out, Fraction &f)
{
    out << "Ułamek " << f.nominator << "/" << f.denominator << " (" << (double)f << ")\n";

    return out;
}
std::istream &operator>>(std::istream &out, Fraction &f)
{
    out >> f.nominator;
    out >> f.denominator;
    delete (f.dvalue);
    f.dvalue = new double((double)f.nominator / f.denominator);
    return out;
}
int main(int argc, char const *argv[])
{
    Fraction piotr(2, 5);
    std::cin >> piotr;
    std::cout << piotr << std::endl;
    return 0;
}

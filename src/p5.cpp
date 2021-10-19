#include <iostream>

struct produkt
{
    int cena, waga;
    void print();
    produkt(int c, int w) : cena(c), waga(w){};
};

void produkt::print()
{
    std::cout << "Cena " << cena << std::endl;
    std::cout << "Waga " << waga << std::endl;
};
int main()
{
    produkt banan(2, 6);
    banan.print();

    produkt *maszrum = new produkt(6, 9);
    maszrum->print();
    delete maszrum;

    return 0;
}
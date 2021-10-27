#include "Prostokat.h"
#include <iostream>

int Prostokat::ilosc = 0;
Prostokat::Prostokat(double a = 3, double b = 4)
{
    ilosc++;
    width = a;
    heigth = b;
};
Prostokat::Prostokat(Prostokat &p)
{
    ilosc++;
    width = p.getA();
    heigth = p.getB();
};
Prostokat::~Prostokat()
{
    ilosc--;
}
void Prostokat::draw()
{
    for (int i = 0; i < width; i++)
    {
        std::cout << "--";
    };
    std::cout << std::endl;
    for (int i = 0; i < heigth; i++)
    {
        for (int j = 0; j < width * 2; j++)
        {
            if (j == 0 || j == width * 2 - 1)
            {
                std::cout << "I";
            }
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    };

    for (int i = 0; i < width; i++)
    {
        std::cout << "--";
    };
    std::cout << std::endl;
}
double Prostokat::L()
{
    return 2 * width + 2 * heigth;
};
double Prostokat::pole()
{
    return width * heigth;
}
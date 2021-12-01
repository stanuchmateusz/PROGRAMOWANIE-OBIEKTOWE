//napisać klasę reprezentującą dane prostokąta
//a i b private
//jeden kontruktor
//metody liczące pole i obwód
#include <iostream>
#include "Prostokat.h"

int main()
{
    Prostokat *p1 = new Prostokat(13, 4);
    std::cout << p1->getA() << " " << p1->getB() << std::endl;
    Prostokat *p2 = new Prostokat(1, 1);
    std::cout << p2->getA() << " " << p2->getB() << std::endl;

    std::cout << p2->getIlosc() << std::endl;
    p1->draw();
    return 0;
}

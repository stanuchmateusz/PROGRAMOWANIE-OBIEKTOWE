#include <iostream>
// using namespace std;
namespace wlasana
{
    void fun()
    {
        std::cout << "Własna funkcja" << std::endl;
    }
}
namespace moja
{
    void fun()
    {
        std::cout << "Mojafunkcja" << std::endl;
    }
}
int main()
{
    moja::fun();
    wlasana::fun();
    return 0;
}
#include <iostream>
#include <new>

int main()
{
    int size;
    std::cin >> size;
    try
    {
        int *w = new int[size];
        std::cout << "Zaalokowano 1000000000000 komorek do"
                  << "przechowania liczb calkowitych" << std::endl;
    }
    catch (std::bad_alloc &wyjatek)
    {
        std::cout << "Blad alokacji " << wyjatek.what()
                  << std::endl;
    }

    try
    {
        std::string napis = "Jakis napis";
        napis.at(-2);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::string napis2 = "Jakis napis";
    napis2.at(-2);

    return 0;
}
#include <iostream>

int *make_array(int rozmiar)
{
    return new int[rozmiar];
}

int main()
{
    int *i = new int; //sterta
    int j = 5;        //stos
    delete i;
    i = new int(2);

    int rozmiar;
    std::cin >> rozmiar;

    int *tablica = new int[rozmiar];
    delete[] tablica;

    int *t1 = make_array(rozmiar);

     for (int i = 0; i < rozmiar; i++)
    {
        t1[i] = 1;
    }

    for (int i = 0; i < rozmiar; i++)
    {
        std::cout << t1[i];
    }

    return 0;
}
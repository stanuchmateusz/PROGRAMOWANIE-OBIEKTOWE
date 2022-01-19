#include <iostream>
// 1. (szablony) Napisać generyczną klasę Tablica,
// która będzie przechowywać dynamiczną tablicę danych i jej rozmiar.
// Klasa ma dostarczać konstruktor domyślny (z dowolnym domyślnym rozmiarem tablicy),
// konstruktor parametrowy (parametry: tablica danych typu T i jej rozmiar),
// konstruktor kopiujący i destruktor oraz mieć przeciążone operator przypisania i operator[ ].
// Operator[ ] ma rzucać wyjątek std::out_of_range w przypadku błędnej wartości indeksu.
// W funkcji main() przetestować działanie klasy,
// konstruując kilka obiektów i używając zaimplementowanych operatorów.

template <typename T>
class Tablica
{
private:
    T *tab;
    int rozmiar;

public:
    Tablica(int rozmiar)
    {
        this->tab = (T *)malloc(rozmiar * sizeof(T));
        this->rozmiar = rozmiar;
    }
    Tablica(T *tab, int rozmiar)
    {
        this->tab = tab;
        this->rozmiar = rozmiar;
    }
    ~Tablica()
    {
        delete[] tab;
    };
    T &operator=(T value)
    {
        return tab[value];
    }
    T &operator[](int indeks)
    {
        if (indeks < 0 || indeks >= rozmiar)
        {
            throw std::out_of_range("Niepoprawny indeks");
        }
        return tab[indeks];
    }
};

int main(int argc, char const *argv[])
{
    Tablica<int> tablica(5);
    Tablica<float> tablica2(2);
    Tablica<char> tablica3(8);

    tablica[0] = 1;
    std::cout << tablica[0] << std::endl;
    tablica3[0] = 'a';
    std::cout << tablica3[0] << std::endl;
    try
    {
        std::cout << tablica[7] << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

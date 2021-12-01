//      2. Napisać klasy Pracownik stazysta kierownik
//      W każdej klasie metoda ma wypisać na ekran informację o przyznaniu bonusu i jego wysokości, lub wypisać informację o odmowie przyznania bonusu.
//      Wprowadzić w klasach odpowiednią hierarchię dziedziczenia.
//      Metoda przyznająca bonus ma być polimorficzna. W funkcji main() pokazać polimorficzne użycie tej metody (z użyciem wskaźników na klasę bazową).
#include <iostream>
//      - Pracownik, który ma pole pensja i metodę przyznaj_bonus(double kwota);
//      bonus może być przyznany jeśli kwota stanowi maksymalnie połowę obecnej pensji
class Pracownik
{
private:
    double pensja;

public:
    Pracownik(double pensja) { this->pensja = pensja; }
    virtual ~Pracownik(){};
    double getPensja() { return pensja; }
    void setPensja(double pensja) { this->pensja = pensja; }
    virtual void przyznaj_bonus(double kwota)
    {
        if (kwota < pensja / 2)
        {
            this->pensja += kwota;
            std::cout << "Przyznano bonus pracownikowi w wysokosci " << kwota << std::endl;
        }
        else
        {
            std::cout << "Odmowa przyznania bonusu dla pracownika" << std::endl;
        }
    }
};

//      - Stazysta, który ma pole czas_stazu liczony w miesiącach i metodę przyznaj bonus; obowiązuje ta sama zasada,
//       co w klasie Pracownik, dodatkowo bonus można przyznać tylko, jeśli czas stażu to co najmniej 6 miesięcy
class Stazysta : public Pracownik
{
private:
    unsigned int czas_stazu;

public:
    Stazysta(double pensja, unsigned int czas_stazu) : Pracownik(pensja), czas_stazu(czas_stazu) {}
    ~Stazysta() {}
    void przyznaj_bonus(double kwota)
    {
        if (kwota < Pracownik::getPensja() / 2 && czas_stazu > 6)
        {
            Pracownik::setPensja(Pracownik::getPensja() + kwota);
            std::cout << "Przyznano bonus stazyscie w wysokosci " << kwota << std::endl;
        }
        else
        {
            std::cout << "Odmowa przyznania bonusu dla stazysty " << std::endl;
        }
    }
};
//      - Kierownik, który ma pole liczba_podwladnych i metodę przyznaj bonus; kwota bonusu musi być mniejsza lub równa pensji danego kierownika,
//       dodatkowo kierownik ma bonus powiększony o 50 za każdego podwładnego.
class Kierownik : public Pracownik
{
private:
    unsigned int iloscPodwladnych;

public:
    Kierownik(double pensja, unsigned int iloscPodwladnych) : Pracownik(pensja), iloscPodwladnych(iloscPodwladnych) {}
    ~Kierownik() {}
    void przyznaj_bonus(double kwota)
    {
        if (kwota <= Pracownik::getPensja())
        {
            Pracownik::setPensja(Pracownik::getPensja() + 50 * iloscPodwladnych + kwota);
            std::cout << "Przyznano bonus kierownikowi w wysokosci " << kwota << std::endl;
        }
        else
        {
            std::cout << "Odmowa przyznania bonusu dla kierownika " << std::endl;
        }
    }
};

int main()
{
    Pracownik *firma[4];
    firma[0] = new Pracownik(2400);
    firma[1] = new Pracownik(2600);
    firma[2] = new Stazysta(2100, 5);
    firma[3] = new Kierownik(4100, 3);

    for (auto &&prac : firma)
    {
        prac->przyznaj_bonus(200);
        std::cout << prac->getPensja() << std::endl;
    }
    for (auto &&prac : firma)
    {
        delete prac;
    }

    return 0;
}
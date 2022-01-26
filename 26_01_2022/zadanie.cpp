#include <iostream>
#include <vector>
#include <Windows.h>

class Silnik
{
private:
    bool _czy_dziala; // uruchomiony / zgaszony
    char _bieg;       // R,N,1,2,3,4,5

public:
    Silnik() : _czy_dziala(false), _bieg('N'){};
    ~Silnik(){};
    bool get_czy_dziala() { return _czy_dziala; };
    void uruchom()
    {
        if (_czy_dziala)
            throw std::bad_exception("Silnik juz dziala");
        else
        {
            _czy_dziala = true;
            std::cout << "Silnik uruchomiony" << std::endl;
        }
    }
    void zgas()
    {
        if (_czy_dziala)
        {
            _czy_dziala = false;
            std::cout << "Silnik został wyłączony" << std::endl;
        }
        else
            throw std::bad_exception("Silnik juz dziala");
    }
    void zmien_bieg(char bieg)
    {
        if (_czy_dziala)
        {
            if (bieg == 'R' || bieg == 'N' || bieg == '1' || bieg == '2' || bieg == '3' || bieg == '4' || bieg == '5')
            {
                _bieg = bieg;
                std::cout << "Bieg zmieniony na " << _bieg << std::endl;
            }
            else
                throw std::invalid_argument("Błędny bieg");
        }
        else
            throw std::invalid_argument("Silnik wyłączony");
    }
};

class PojazdSilnikowy : public Silnik
{
private:
    unsigned int _przebieg;
    std::string _marka;
    std::string _model;
    unsigned short _rocznik;
    Silnik _silnik;

public:
    PojazdSilnikowy(std::string marka,
                    std::string model,
                    unsigned short rocznik) : _marka(marka),
                                              _model(model),
                                              _rocznik(rocznik),
                                              _przebieg(0){};
    PojazdSilnikowy(const PojazdSilnikowy &p) : _marka(p._marka),
                                                _model(p._model),
                                                _rocznik(p._rocznik),
                                                _przebieg(p._przebieg),
                                                _silnik(p._silnik){};

    void set_przebieg(unsigned int przebieg) { _przebieg += przebieg; };
    virtual void jedz(unsigned short km){};

    ~PojazdSilnikowy(){};

    friend void operator<<(std::ostream &os, PojazdSilnikowy &p);
};
void operator<<(std::ostream &os, PojazdSilnikowy &p)
{
    os << "*****************************************" << std::endl;
    os << "Marka: " << p._marka << std::endl;
    os << "Model: " << p._model << std::endl;
    os << "Rocznik: " << p._rocznik << " r." << std::endl;
    os << "Przebieg: " << p._przebieg << " km" << std::endl;
    os << "*****************************************" << std::endl;
}

class Samochod : public PojazdSilnikowy
{
private:
    float _poziom_paliwa;  // w litrach
    float _pojemnosc_baku; // w litrach
    float _spalanie;       // na km

public:
    /**
     * @brief Samochod
     * @param marka - nazwa marki | std::string
     * @param model - nazwa modelu |
     * @param rok_produkcji - rok produkcji
     **/
    Samochod(
        std::string marka,
        std::string model,
        unsigned short rok_produkcji,
        float spalanie,
        float pojemnosc_baku) : _spalanie(spalanie),
                                _pojemnosc_baku(pojemnosc_baku),
                                _poziom_paliwa(0),
                                PojazdSilnikowy(marka, model, rok_produkcji){};
    Samochod(const Samochod &s) : _spalanie(s._spalanie),
                                  _pojemnosc_baku(s._pojemnosc_baku),
                                  _poziom_paliwa(s._poziom_paliwa),
                                  PojazdSilnikowy(s){};

    void tankuj(float litry)
    {
        if (_poziom_paliwa + litry > _pojemnosc_baku)
            throw std::invalid_argument("Przekroczono pojemnosc baku");
        else
        {
            _poziom_paliwa += litry;
            std::cout << "Zatankowano " << litry << " litrów" << std::endl;
        }
    };
    void jedz(unsigned short km)
    {
        if (this->get_czy_dziala())
        {
            if (_poziom_paliwa - km * _spalanie < 0)
                throw std::invalid_argument("Nie wystarczy paliwa");
            else
            {
                _poziom_paliwa -= km * _spalanie;
                this->set_przebieg(km);
                std::cout << "Przejechano " << km << " km" << std::endl;
            }
        }
        else
            throw std::invalid_argument("Silnik wyłączony");
    }

    ~Samochod(){};
};

class SamochodElektryczny : public PojazdSilnikowy
{
private:
    float _poziom_naladowania; // w kilometrach
    float _maksymalny_zasieg;  // w kilometrach
    static unsigned int ilosc_pojazdow;

public:
    /**
     * @brief SamochodElektryczny
     * @param marka - nazwa marki | std::string
     * @param model - nazwa modelu | std::string
     * @param rok_produkcji - rok produkcji | unsigned short
     * @param maksymalny_zasieg - maksymalny zasieg | float
     * */
    SamochodElektryczny(
        std::string marka,
        std::string model,
        unsigned short rok_produkcji,
        float maksymalny_zasieg) : _poziom_naladowania(0),
                                   _maksymalny_zasieg(maksymalny_zasieg),
                                   PojazdSilnikowy(marka, model, rok_produkcji)
    {
        ilosc_pojazdow++;
    };
    SamochodElektryczny(const SamochodElektryczny &s) : _poziom_naladowania(s._poziom_naladowania),
                                                        _maksymalny_zasieg(s._maksymalny_zasieg),
                                                        PojazdSilnikowy(s){};

    ~SamochodElektryczny() { ilosc_pojazdow--; };
    void doladuj()
    {
        _poziom_naladowania = _maksymalny_zasieg;
        std::cout << "W pełni załadowano akumlatory " << std::endl;
    };
    void jedz(unsigned short km)
    {
        if (this->get_czy_dziala())
        {
            if (_poziom_naladowania - km < 0)
                throw std::invalid_argument("Za malo energii");
            else
            {
                _poziom_naladowania -= km;
                this->set_przebieg(km);
                std::cout << "Przejechano " << km << " km" << std::endl;
            }
        }
        else
            throw std::invalid_argument("Silnik wyłączony");
    }
    void wyswietl_ilosc_pojazdow()
    {
        std::cout << "Ilość pojazdów elektrycznych: " << ilosc_pojazdow << std::endl;
    }
};

unsigned int SamochodElektryczny::ilosc_pojazdow = 0;

int main(int argc, char const *argv[])
{
    SetConsoleOutputCP(CP_UTF8); // ustawienie kodowania
    std::vector<Samochod *> pojazdy1;
    pojazdy1.push_back(new Samochod("Ford", "Focus", 2010, 0.5, 50));
    pojazdy1.push_back(new Samochod("Opel", "Astra", 2017, 0.72, 60));
    pojazdy1.push_back(new Samochod("BMW", "e46", 2006, 0.43, 70));
    std::vector<SamochodElektryczny *> pojazdy2;
    pojazdy2.push_back(new SamochodElektryczny("Tesla", "Model S", 2018, 300));
    pojazdy2.push_back(new SamochodElektryczny("Tesla", "Model 3", 2019, 200));
    pojazdy2.push_back(new SamochodElektryczny("Tesla", "Model X", 2020, 420));

    for (auto &p : pojazdy1)
    {
        try
        {
            std::cout << *p;
            p->tankuj(60);
            p->uruchom();
            p->zmien_bieg('1');
            p->jedz(340);
            p->zmien_bieg('N');
            p->zgas();
            std::cout << *p;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "*****************************************" << std::endl;

    pojazdy2[0]->wyswietl_ilosc_pojazdow();
    std::cout << "*****************************************" << std::endl;

    for (auto &p : pojazdy2)
    {
        try
        {
            std::cout << *p;
            p->doladuj();
            p->uruchom();
            p->zmien_bieg('1');
            p->jedz(240);
            p->zmien_bieg('N');
            p->zgas();
            std::cout << *p;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    for (auto &p : pojazdy1)
    {
        delete p;
    }

    return 0;
}

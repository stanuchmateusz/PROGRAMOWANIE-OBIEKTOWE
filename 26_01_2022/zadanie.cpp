#include <iostream>
#include <Windows.h>

class ValueExeption : public std::exception
{
private:
    std::string message;

public:
    ValueExeption(std::string msg = "") : message(msg) {}
    const char *what() const noexcept
    {
        std::string msg = "Podano błędna wartosc ";
        return msg.append(message).c_str();
    }
};
class EngineExeption : public ValueExeption
{
public:
    EngineExeption() : ValueExeption("Silnik jest wyłączony") {}
};

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
            std::cout << "Silnik juz działa" << std::endl;
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
            std::cout << "Silnik juz jest wyłączony" << std::endl;
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
                std::cout << "Błędny bieg" << std::endl;
        }
        else
            std::cout << "Silnik wyłączony" << std::endl;
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
    void set_przebieg(unsigned int przebieg) { _przebieg += przebieg; };
    virtual void jedz(unsigned short km){};

    ~PojazdSilnikowy(){};
};

class Samochod : public PojazdSilnikowy
{
private:
    float _poziom_paliwa;  // w litrach
    float _pojemnosc_baku; // w litrach
    float _spalanie;       // na km

public:
    Samochod(
        std::string marka,
        std::string model,
        unsigned short rok_produkcji,
        float spalanie,
        float pojemnosc_baku) : _spalanie(spalanie),
                                _pojemnosc_baku(pojemnosc_baku),
                                _poziom_paliwa(0),
                                PojazdSilnikowy(marka, model, rok_produkcji){};
    void tankuj(float litry)
    {
        if (_poziom_paliwa + litry > _pojemnosc_baku)
            throw ValueExeption("Przekroczono pojemnosc baku");
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
                throw ValueExeption("Nie wystarczy paliwa");
            else
            {
                _poziom_paliwa -= km * _spalanie;
                this->set_przebieg(km);
                std::cout << "Przejechano " << km << " km" << std::endl;
            }
        }
        else
            throw EngineExeption();
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
    ~SamochodElektryczny()
    {
        ilosc_pojazdow--;
    };
    void doladuj(float ladowanie)
    {
        if (_poziom_naladowania + ladowanie > _maksymalny_zasieg)
            throw ValueExeption("Przekroczono maksymalny zasięg");
        else
        {
            _poziom_naladowania += ladowanie;
            std::cout << "Załadowano " << ladowanie << " km" << std::endl;
        }
    };
    void jedz(unsigned short km)
    {
        if (this->get_czy_dziala())
        {
            if (_poziom_naladowania - km < 0)
                throw ValueExeption("Za mało energii");
            else
            {
                _poziom_naladowania -= km;
                this->set_przebieg(km);
                std::cout << "Przejechano " << km << " km" << std::endl;
            }
        }
        else
            throw EngineExeption();
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
    try
    {
        Samochod samochod("Ford", "Focus", 2019, 5, 50);
        samochod.tankuj(10);
        samochod.uruchom();
        samochod.jedz(20);
    }
    catch (ValueExeption &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        SamochodElektryczny samochod_elektryczny("Tesla", "Model S", 2019, 100);
        samochod_elektryczny.doladuj(50);
        samochod_elektryczny.uruchom();
        samochod_elektryczny.jedz(20);
        SamochodElektryczny samochod_elektryczny2("BMW", "F2", 2021, 403);
        samochod_elektryczny.wyswietl_ilosc_pojazdow();
    }
    catch (ValueExeption &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

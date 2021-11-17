#include <iostream>

class Osoba
{
private:
    int id;
    std::string nazwisko;
    int numer_telefonu;

public:
    Osoba(int sid, int snumer_telefon, std::string snazwisko) : id(sid), numer_telefonu(snumer_telefon)
    {
        snazwisko[0] = toupper(snazwisko[0]);
        nazwisko = snazwisko;
    };
    ~Osoba(){};
    void zmien_numer(int nowy_numer)
    {
        numer_telefonu = nowy_numer;
    }
    void wypisz()
    {
        std::cout << nazwisko << " ID: " << id << " nr telefonu: " << numer_telefonu << std::endl;
    };
};
class Student : public Osoba
{
private:
    double srednia;

public:
    Student(int sid, int snumer_telefon, std::string snazwisko, double ssrednia) : Osoba(sid, snumer_telefon, snazwisko), srednia(ssrednia) {}
    ~Student() {}
    void zmien_srednia(double nowa_srednia)
    {
        srednia = nowa_srednia;
    }
    void wypisz()
    {
        Osoba::wypisz();
        std::cout << "Srednia ocen " << srednia << std::endl;
    }
};

int main()
{
    Student piotrek(2137, 321654876, "bozek", 5.0);
    piotrek.wypisz();
    piotrek.zmien_numer(4354345);
    piotrek.zmien_srednia(3.1);
    piotrek.wypisz();

    return 0;
}
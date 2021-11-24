// 2. Napisać program, który zawiera klasy:
// Wielokat, Trojkat, Prostokat i Kwadrat. Klasy mają być powiązane relacją dziedziczenia i posiadać metodę oblicz_pole()
//  dla policzenia pola powierzchni danej figury.
#include <iostream>
#include <math.h>

class Wielokat
{
private:
	int a; //podstawa
public:
	Wielokat(int podstawa) : a(podstawa){};
	~Wielokat(){};
	int getA() { return a; };
	virtual void oblicz_pole() {}
};
class Trojkat : public Wielokat
{
private:
	int h; //wysokosc
public:
	Trojkat(int podstawa, int wysokosc) : Wielokat(podstawa), h(wysokosc){};
	~Trojkat(){};
	void oblicz_pole()
	{
		std::cout << "Pole wynosi: " << Wielokat::getA() * h << std::endl;
	}
};
class Prostakat : public Wielokat
{
private:
	int h; //wysokosc
public:
	Prostakat(int podstawa, int wysokosc) : Wielokat(podstawa), h(wysokosc){};
	~Prostakat(){};
	void print()
	{
		std::cout << "a = " << Wielokat::getA() << std::endl
				  << "b = " << h << std::endl;
	}
	void oblicz_pole()
	{
		std::cout << "Pole wynosi: " << Wielokat::getA() * h << std::endl;
	}
};

class Kwadrat : public Prostakat
{
public:
	Kwadrat(int a) : Prostakat(a, a) {}
	~Kwadrat() {}
};

int main()
{
	Kwadrat k(4);
	k.oblicz_pole();
}
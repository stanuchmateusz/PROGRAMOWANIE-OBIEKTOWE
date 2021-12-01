// 2. Napisać program, który zawiera klasy:
// Wielokat, Trojkat, Prostokat i Kwadrat. Klasy mają być powiązane relacją dziedziczenia i posiadać metodę oblicz_pole()
//  dla policzenia pola powierzchni danej figury.
#include <iostream>
#include <math.h>

class Wielokat
{

public:
	Wielokat(){};
	~Wielokat(){};
	virtual double oblicz_pole() {}
};
class Trojkat : public Wielokat
{
private:
	double a, h;

public:
	Trojkat(double podstawa, double wysokosc) : a(podstawa), h(wysokosc){};
	~Trojkat(){};
	double oblicz_pole()
	{
		return a * h;
	}
};
class Prostakat : public Wielokat
{
private:
	double a, b;

public:
	Prostakat(double podstawa, double wysokosc) : a(podstawa), b(wysokosc){};
	~Prostakat(){};
	double oblicz_pole()
	{
		return a * b;
	}
};

class Kwadrat : public Prostakat
{
public:
	Kwadrat(double a) : Prostakat(a, a) {}
	~Kwadrat() {}
};

double main()
{
	Kwadrat k(4);
	std::cout << k.oblicz_pole() << std::endl;
}
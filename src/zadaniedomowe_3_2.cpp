// 2. Napisać program, który zawiera klasy:
// Wielokat, Trojkat, Prostokat i Kwadrat. Klasy mają być powiązane relacją dziedziczenia i posiadać metodę oblicz_pole()
//  dla policzenia pola powierzchni danej figury.
#include <iostream>
#include <math.h>

class Wielokont
{
private:
	int a; //podstawa
public:
	Wielokont(int podstawa) : a(podstawa){};
	~Wielokont(){};
	int getA() { return a; };
	virtual void print()
	{
		std::cout << "podstawa = " << a << std::endl;
	}
	virtual void oblicz_pole() {}
};
class Trojkat : public Wielokont
{
private:
	int b, c; //boki trójkąta
	int h;	  //wysokosc
public:
	Trojkat(int podstawa, int bok1, int bok2) : Wielokont(podstawa), b(bok1), c(bok2) { h = 0; };
	Trojkat(int podstawa, int wysokosc) : Wielokont(podstawa), h(wysokosc){};
	~Trojkat(){};
	void print()
	{
		Wielokont::print();
		if (h > 0)
		{
			std::cout << "wysokosc = " << h << std::endl;
		}
		else
		{
			std::cout << "bok 1 = " << b << std::endl;
			std::cout << "bok 2 = " << c << std::endl;
		}
	}
	void oblicz_pole()
	{
		std::cout << "Pole trojkata" << std::endl;
		print();
		if (h > 0)
		{
			std::cout << "wynosi: " << (Wielokont::getA() * h) / 2 << std::endl;
		}
		else
		{
			int p = (Wielokont::getA() + b + c) / 2;
			std::cout << "wynosi: " << sqrt(p * (p - Wielokont::getA()) * (p - b) * (p - c)) << std::endl;
		}
	}
};
class Prostakat : public Wielokont
{
private:
	int h; //wysokosc
public:
	Prostakat(int podstawa, int wysokosc) : Wielokont(podstawa), h(wysokosc){};
	~Prostakat(){};
	void print()
	{
		std::cout << "a = " << Wielokont::getA() << std::endl
				  << "b = " << h << std::endl;
	}
	void oblicz_pole()
	{
		std::cout << "Pole prostokata o bokach:" << std::endl;
		print();
		std::cout << "wynosi: " << Wielokont::getA() * h << std::endl;
	}
};
// class Kwadrat : public Wielokont
// {
// private:
// 	/* data */
// public:
// 	Kwadrat(int a) : Wielokont(a){};
// 	~Kwadrat(){};
// 	void print()
// 	{
// 		std::cout << "a=" << Wielokont::getA() << std::endl;
// 	}
// 	void oblicz_pole()
// 	{
// 		std::cout << "Pole prostokata o bokach:" << std::endl;
// 		print();
// 		std::cout << "wynosi: " << Wielokont::getA() * Wielokont::getA() << std::endl;
// 	}
// };
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
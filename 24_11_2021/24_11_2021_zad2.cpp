// 2. Zmienić klasę bazową z zadania domowego tak, by umożliwić realizację polimorfizmu.
// W funkcji main wykorzystać polimorfizm na dwa sposoby:
// - Program ma obliczyć pole figury wybranej przez użytkownika
// (np. opcja '1' policzy pole trójkąta, opcja '2' prostokąta, wymiary mogą być domyślne np. wszystkie równe 1).
// - W programie tworzymy 3-elementową tablicę wskaźników na typ klasy bazowej. Każdy z elementów ma wskazywać na obiekt innej klasy
// (tj. Trojkat, Prostokat, Kwadrat). Za pomocą pętli policzyć sumę pól wszystkich 3 figur.
#include <iostream>

class Wielokat
{

public:
	Wielokat(){};
	~Wielokat(){};
	virtual double oblicz_pole() { return 0; }
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
		return 0.5 * a * h;
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

int main()
{
	double wymiar_a = 2;
	double wymiar_b = 4;
	double wynik;
	int wybor;
	std::cout << "Wybierz figure '1' policzy pole trojkata, opcja '2' prostokata '3' kwardatu " << std::endl;
	std::cin >> wybor;
	switch (wybor)
	{
	case 1:
		wynik = Trojkat(wymiar_a, wymiar_b).oblicz_pole();
		break;
	case 2:
		wynik = Prostakat(wymiar_a, wymiar_b).oblicz_pole();
		break;
	case 3:
		wynik = Kwadrat(wymiar_a).oblicz_pole();
		break;
	default:
		std::cout << "Naura" << std::endl;
		break;
	}
	std::cout << wynik << std::endl;

	Wielokat *figury[3];
	figury[0] = new Trojkat(21, 37);
	figury[1] = new Prostakat(21, 37);
	figury[2] = new Kwadrat(21.37);
	for (auto &&i : figury)
	{
		std::cout << i->oblicz_pole() << std::endl;
	}
	for (auto &&i : figury)
	{
		delete i;
	}

	return 0;
}
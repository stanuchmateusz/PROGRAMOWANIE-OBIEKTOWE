#include <iostream>

class X
{
	public:
	// Funkcja abstrakcyjna - metoda, dla ktorej podano jedynie nazwe, 
	// liste argumentow i typ zwracanej wartosci, 
	// natomiast calkowicie pominieto jej cialo, 
	// pozostawiajac implementacje klasom pochodnym.
	// Klasa abstrakcyjna - klasa, w ktorej umieszczono jedna lub wiecej 
	// funkcji abstrakcyjnych.
	// Funkcja abstrakcyjna w C++ to tzw. funkcja czysto wirtualna.
	virtual void f1() = 0;
	
	// niedozwolone przekazywanie i zwracanie przez wartosc
	//void f2(X x) {};
	//X f3() {};
	
	// dozwolone przekazywanie i zwracanie przez referencje lub wskaznik
	void f4(X * x) {};
	X * f5() {};		
};

class Y: public X
{
	public: 
	
	void f1()
	{
		std::cout << "Y1::f()\n";
	};
};


int main()
{
	// Nie mozna utworzyc obiektu klasy abstrakcyjnej
	//X x; 
	X * pX;
	//pX = new X;
    //delete pX;
	
	Y y; 

	Y * pY = new Y;
    delete pY;

    // ! Dozwolone
	pX = new Y;
    delete pX;

	return 0;
}




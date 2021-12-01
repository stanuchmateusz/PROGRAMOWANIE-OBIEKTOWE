#include <iostream>

class X1
{
public:
	// Wirtualny konstruktor nie jest mozliwy, gdyz konstruktora 
	// nie da sie wywolac poprzez wskaznik lub referencje, 
	// bo w momencie wolania konstruktora obiektu jeszcze nie ma.	
	X1() {};
	
	virtual void f()
	{
		std::cout << "X1::f()\n";
	};
   
	// !!! Jesli klasa deklaruje jedna ze swych funkcji jako virtual, 
	// to destruktor tej klasy tez powinien byc virtual.   
	virtual ~X1()
	{
		std::cout << "Destruktor X1\n";	
	};   
};

class Y1: public X1
{
public: 
	Y1() {};

	void f()
	{
		std::cout << "Y1::f()\n";
	};
   
	~Y1()
	{
		std::cout << "Destruktor Y1\n";	
	};   
};

class X2
{
public:
	X2() {};
	
	void f()
	{
		std::cout << "X2::f()\n";
	};
   
	~X2()
	{
		std::cout << "Destruktor X2\n";	
	};   
};

class Y2: public X2
{
public:		
	Y2() {};

	void f()
	{
		std::cout << "Y2::f()\n";
	};
   
	~Y2()
	{
		std::cout << "Destruktor Y2\n";	
	};   
};

int main()
{
	// Destruktor wirtualny w klasie bazowej zapewnia wywolanie 
	// wszystkich destruktorow klas potomnych podczas niszczenia obiektu
	// (i tym samym prawidlowe zwolnienie pamieci obiektu) 
	X1 * pX1 = new Y1;
    delete pX1;
	
    std::cout << "\n";

	X1 * pX1a = new X1;
    delete pX1a;
    
    std::cout << "\n";

	// Jesli destruktor nie jest wirtualny to destruktor klasy pochodnej 
	// nie zostanie wywolany 
	X2 * pX2 = new Y2;
    delete pX2;

	return 0;
}




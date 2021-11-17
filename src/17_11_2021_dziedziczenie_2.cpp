#include <iostream>

class X
{
    int a;
    void metoda1() {};
    
public:
    int b;
    void metoda2() {};
    
private:
    int c;
    void metoda3() {};
    
protected:
    int d;
    void metoda4() {};

public:	
	X(int ap = 0, int bp = 0, int cp=0, int dp=0): a(ap), b(bp), c(cp), d(dp)
	{
		std::cout << "Kontruktor X \n";
	};

   void wypisz()
   {
   		// z poziomu klasy wszystkie skladniki dostepne
   		std::cout << "a= " << a << "\n";
   		std::cout << "b= " << b << "\n";
   		std::cout << "c= " << c << "\n";
   		std::cout << "d= " << d << "\n";
   		
   		metoda1();
   		metoda2();
   		metoda3();
   		metoda4();
   };

	~X()
	{
		std::cout << "Destruktor X\n";	
	};
};

class Y: public X
{
public:
    int e;
		
	Y(int ap=0, int bp=0, int cp=0, int dp=0, int ep=0): X(ap, bp, cp, dp), e(ep)
	{
		std::cout << "Kontruktor Y \n";
	};

   void wypisz_e()
   {
   		std::cout << "e= " << e << "\n";
   };

   void wypisz()
   {
        X::wypisz();
        wypisz_e();

        // z poziomu klasy pochodnej bezposrednio dostepne tylko 
        // skladniki public i protected w klasie bazowej
        // (do private mozna sie "dostac" posrednio tylko przez 
        //  wywolanie metody klasy bazowej jako powyzej np. X::wypisz() )
        //std::cout << "a= " << a << "\n";
        std::cout << "b= " << b << "\n";
        //std::cout << "c= " << c << "\n";
        std::cout << "d= " << d << "\n";

        //metoda1();
        metoda2();
        //metoda3();
        metoda4();
   };
   
	~Y()
	{
		std::cout << "Destruktor Y\n";	
	};
};

int main()
{
	{
		std::cout << "X:\n";
		X x(1, 2, 3, 4);
		x.wypisz();
		
		// z zewnatrz dostepne tylko skladniki publiczne
		//std::cout << "a= " << x.a << "\n";
   		std::cout << "b= " << x.b << "\n";
   		//std::cout << "c= " << x.c << "\n";
   		//std::cout << "d= " << x.d << "\n";

   		//x.metoda1();
   		x.metoda2();
   		//x.metoda3();
   		//x.metoda4();

	}

	std::cout << "\n";

	{
		std::cout << "Y:\n";
		Y y(5, 6, 7, 8, 9);
		y.wypisz();
		
		// z zewnatrz dostepne tylko skladniki publiczne
		//std::cout << "a= " << y.a << "\n";
   		std::cout << "b= " << y.b << "\n";
   		//std::cout << "c= " << y.c << "\n";
   		//std::cout << "d= " << y.d << "\n";

   		//y.metoda1();
   		y.metoda2();
   		//y.metoda3();
   		//y.metoda4();

	}

	return 0;
}
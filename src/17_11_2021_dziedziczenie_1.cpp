#include <iostream>

class X
{
private:
	int a;
	int b;

public:
	X(int ap = 0, int bp = 0) : a(ap), b(bp)
	{
		std::cout << "Kontruktor X \n";
	};

	void wypisz()
	{
		std::cout << "a= " << a << "\n";
		std::cout << "b= " << b << "\n";
	};

	~X()
	{
		std::cout << "Destruktor X\n";
	};
};

class Y : private X
{
private:
	int c;

public:
	Y(int ap = 0, int bp = 0, int cp = 0) : X(ap, bp), c(cp)
	{
		std::cout << "Kontruktor Y \n";
	};

	void wypisz_c()
	{
		std::cout << "c= " << c << "\n";
	};

	void wypisz()
	{
		X::wypisz();
		wypisz_c();
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
		X x(1, 2);
		x.wypisz();
	}

	std::cout << "\n";

	{
		std::cout << "Y:\n";
		Y y(3, 4, 5);
		y.wypisz();
	}

	return 0;
}
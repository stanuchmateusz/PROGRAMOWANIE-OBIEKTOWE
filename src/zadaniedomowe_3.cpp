// Dopisać w pliku zadanie1.cpp definicję konstruktorów, destruktorów i metody print()
// we wszystkich trzech klasach (metoda print() w każdej klasie wypisuje wszystkie zawarte w niej i odziedziczone pola).
#include <iostream>
class First
{
private:
	int a;

public:
	First(int a) : a(a){};
	~First(){};

	void print() const
	{
		std::cout << "a = " << a << std::endl;
	};
};

class Second : public First
{
private:
	int b;

public:
	Second(int a, int b) : First(a), b(b){};
	~Second(){};
	void print() const
	{
		First::print();
		std::cout << "b = " << b << std::endl;
	};
};

class Third : public Second
{
private:
	int c;

public:
	Third(int a, int b, int c) : Second(a, b), c(c){};
	~Third(){};
	void print() const
	{
		Second::print();
		std::cout << "c = " << c << std::endl;
	};
};

int main()
{
	First f(1);
	f.print();

	Second s(1, 2);
	s.print();

	Third t(1, 2, 3);
	t.print();

	return 0;
}
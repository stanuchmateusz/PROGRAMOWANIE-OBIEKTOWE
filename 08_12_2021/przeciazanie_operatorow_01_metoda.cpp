#include <iostream>

//W jezyku C++ mozna przeladowac (przeciazac) wszystkie operatory poza:
//  :: (kwalifikator zakresu)
//  . (wybor skladowej)
//  .* (wybor skladowej za pomoca wskaznika do skladowej)
//  ?: (wyrazenie warunkowe)

// Nie mozna przeladowywac operatorow dla typow wbudowanych (int, char, float).

// Operator mozna przeladowac jako:
// - niestatyczna funkcja skladowa (takimi funkcjami musza byc operatory: =, [], (), ->)
// - funkcja zaprzyjazniona z klasa lub zwykla funkcja globalna (jesli
//   operator nie musi miec dostepu do prywatnych skladnikow klasy)

// Jesli operator zmienia w jakis sposob obiekt, na ktorym pracuje, to
// powinien byc funkcja skladowa klasy (=, ++, --, +=, *= itp.).
// W przeciwnym razie stosuje sie raczej zwykla funkcje globalna
// ze wzgledu na wygode zapisu:
// x + 5
// 5 + x (tak nie da sie napisac jesli operator + jest funkcja skladowa
// bo wtedy pierwszym argumentem musi byc ukryty wskaznik this do obiektu,
// na rzecz ktorego wywolano funkcje skladowa realizujaca operator.
// Przy czym aby byla mozliwa taka przemiennosc, trzeba operator
// zdefiniowac jako 2 funkcje globalne np.:
// operator+(X, int)
// operator+(int, X)

class X
{
private:
  int a;

public:
  X(int ap = 0) : a(ap){};

  X operator-() // -x (operator jednoargumentowy)
  {
    X s;
    s.a = -(this->a);
    return s;
  };

  X operator+(const X &x1)
  {
    X s;
    s.a = this->a + x1.a;
    return s;
  }

  X operator*(const X &x1)
  {
    X s;
    s.a = this->a * x1.a;
    return s;
  }

  // X operator*(const int c);  // x*5 (uwaga, '5*x' nie zadziala - lepiej napisac wersje z funkcja zaprzyjazniona)

  bool operator==(const X &x1) 
  {
    return this->a == x1.a;
  }

};

int main()
{
  X x1(2), x2(1);  
  X x3;

  x3 = -x2;

  if (x1 == x2)
    std::cout << "x1==x2" << std::endl;

  return 0;
}

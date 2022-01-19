#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

// Naglowek szablonu:
// template < lista_parametrow_oddzielonych_przecinkami >
// Parametrami szablonu moga byc:
// - tzw. parametry typu poprzedzone slowem kluczowym typename 
//    (z powodow historycznych moze to byc tez slowo class)
// - tzw. parametry pozatypowe - nazwy zmiennych pewnych wybranych typow (najczeciej int)
// - szablony parametrow szablonow
// Definicja szablonu nie powoduje wygenerowania jakiegokolwiek kodu.

// Szablon funkcji
template<typename T>
T wiekszy(T a, T b)
{
  return a>b ? a : b;
}

// Przyklad szablonu z wieloma parametrami (parametrem szablonu moze tez byc typ rezultatu zwracanego przez funkcje)
template<typename T1, typename T2, typename T3>
T1 mniejszy(T2  a, T3  b)
{
  return (a<b ? (T1)a : (T1)b);
}

// Przyklad szablonu klasy (szablon stosu) z parametrem pozatypowym POJEMNOSC
template<typename T,int POJEMNOSC>
class Stos{
  T stos[POJEMNOSC];
  int top;
public:
  Stos():top(-1){};
  void push(T const& t);
  T pop();
};

// Definicje funkcji skladowych moga byc w klasie lub poza klasa, tak jak w przypadku zwyklej klasy.
// W przypadku definicji poza klasa funkcja musi byc poprzedzona naglowkiem szablonu i operatorem zakresu wskazujacym szablon klasy (np. Stos<T,POJEMNOSC>::) 
template<typename T,int POJEMNOSC>
void Stos<T,POJEMNOSC>::push(T const& t)
{
  if(top<POJEMNOSC-1) stos[++top]=t;
  else throw std::out_of_range("Blad: Stos przepelniony !");  // wyjatek
}

template<typename T,int POJEMNOSC>
T Stos<T,POJEMNOSC>::pop()
{
  if(top>=0) return stos[top--];
  else throw std::out_of_range("Blad: Stos pusty !");	// wyjatek
}


int main()
{
  // Konkretyzacja szablonu: parametr formalny T zastepujemy parametrem aktualnym int i kompilator generuje odpowiedni kod
  cout << wiekszy<int>(1, 2) << endl;
  // Kolejne konkretyzacje:
  cout << wiekszy<double>(4.2, 3.1) << endl;
  cout << wiekszy<double>(5, 3) << endl;	
  cout << wiekszy<double>(6.5, 7) << endl;

  cout << wiekszy(1, 2) << endl;	// kompilator domysli sie, ze chodzi o wiekszy(int,int)
  cout << wiekszy(4.2, 3.1) << endl;	// kompilator domysli sie, ze chodzi o wiekszy(float,float) lub wiekszy(double,double)

  // Blad: nie da sie wygenerowac funkcji o naglowku wiekszy(int,float) ani wiekszy(int,double) z szablonu
  // (konwersje standardowe funkcjonuja dopiero po wygenerowaniu funkcji z szablonu, a nie przed).
  // cout << wiekszy(6, 7.5) << endl;

  cout << endl << "STOS:" << endl;
  Stos<double,10> s;
  s.push(2.4);
  s.push(5.0);
  s.push(1.5);
  cout << s.pop() << endl;
    
}

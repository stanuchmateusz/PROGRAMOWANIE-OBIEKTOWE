#include <iostream>
#include <fstream>

class X {
    int a;
public:
    X(int a = 0)
    {
        this->a = a;
    }

    X & operator=(X & drugi)
    {
        std::cout << "Dziala operator przypisania\n";
        if (this == &drugi)
            return *this;
        
        this->a = drugi.a;
        return *this;
    }

    // Mozemy tez definiowac operator przypisania innych typow (jesli to ma sens)
    X & operator=(int a)
    {
        this->a = a;
        return *this;
    }

    friend std::ostream & operator<<(std::ostream &, X &);
    friend std::istream & operator>>(std::istream &, X &);

    operator int()
    {
        return this->a;
    }
};

    // Ta definicja operatora bedzie miala zastosowanie zawsze gdy obiekt
    // bedacy po lewej stronie operatora '<<' jest klasy std::ostream lub pochodna tej klasy
    // https://www.cplusplus.com/reference/ostream/ostream/
    // Np.: obiekt cout lub obiekty reprezentujace pliki 
    // (ktore same sa instancjami klasy ofstream) itd.
std::ostream & operator<<(std::ostream & wyjscie, X & x) {
    wyjscie << "Zawartosc obiektu: " << x.a;
    return wyjscie;
}

std::istream & operator>>(std::istream & wejscie, X & x) {
    // Ta definicja operatora bedzie miala zastosowanie zawsze gdy obiekt
    // bedacy po lewej stronie operatora '<<' jest klasy std::istream lub pochodna tej klasy
    // https://www.cplusplus.com/reference/istream/istream/
    // Np.: obiekt cin; obiekty reprezentujace pliki (ktore same sa instancjami klasy fistream)
    wejscie >> x.a;
    return wejscie;
}

int square(int a)
{
    return a * a;
}

int main() {
    X x1, x2(4);

    std::cout << x1 << std::endl;
    std::cout << x2 << std::endl;

    X x3 = x1; // czy tu dziala operator przypisania?

    x1 = x2;
    x2 = 8;

    std::cout << x1 << std::endl << x2 << std::endl;

    std::cin >> x1;
    std::cout << x1;

    // std::ofstream myfile("X.txt");
    // if (myfile.is_open())
    // {
    //     myfile << x1 << "\n" << x2;
    //     myfile.close();
    // }
    // else std::cout << "Unable to open file";

    // Niejawne uzycie operator konwersji operator int()
    // std::cout << std::endl;
    // std::cout << square(x1);

    return 0;
}
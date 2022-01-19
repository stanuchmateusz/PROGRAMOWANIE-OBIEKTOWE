// 2. (biblioteka STL)

// Zadanie podstawowe: Napisać program, który pobiera tekst z pliku .txt
// i zlicza wystąpienia liter w tym pliku, na końcu wypisując wynik w konsoli.
//  Dla ułatwienia można przyjąć, że tekst w pliku jest zapisany w jednej linii

// Zadanie rozszerzone:

// Napisz funkcję, która będzie przyjmowała dwa argumenty:

// 	a. zmienną typu string
// 	b. wektor składający się z pewnej ilości słów w postaci stringów

// Funkcja ma sprawdzić ile razy można ułożyć pełne słowa podane w wektorze (b), posługując się literami, które znajdują się w zmiennej typu string (a).

// Przykład:

// 	a. zmienna typu string ma postać: "aaamlmlkkttmoaalkoamata"
// 	b. wektor ma postać: ("ala", "ma", "kota")

// Rozwiązanie:

// Ilość dostępnych liter w stringu:

// 	"a": 8
// 	"m": 4
// 	"l": 3
// 	"k": 3
// 	"t": 3
// 	"o": 2

// Układamy słowa:

// 	1. "ala"
// 		"a": 8 - 2 = 6
// 		"l": 3 - 1 = 2
// 		Można ułożyć słowo "ala"

// 	2. "ala"
// 		"a": 6 - 2 = 4
// 		"l": 2 - 1 = 1
// 		Można ułożyć słowo "ala"

// 	3. "ala"
// 		"a": 4 - 2 = 2
// 		"l": 1 - 1 = 0
// 		Można ułożyć słowo "ala"

// 	4. "ala"
// 		"a": 2 - 2 = 0
// 		"l": 0 - 1 = -1
// 		Nie można ułożyć słowa "ala" - brak liter!

// 	5. "ma"
// 		"m": 4 - 1 = 3
// 		"a": 2 - 1 = 1
// 		Można ułożyć słowo "ma"

// 	6. "ma"
// 		"m": 3 - 1 = 2
// 		"a": 1 - 1 = 0
// 		Można ułożyć słowo "ma"

// 	7. "ma"
// 		"m": 2 - 1 = 1
// 		"a": 0 - 1 = -1
// 		Nie można ułożyć słowa "ma" - brak liter!

// 	8. "kota"
// 		"k": 3 - 1 = 2
// 		"o": 2 - 1 = 1
// 		"t": 3 - 1 = 2
// 		"a": 0 - 1 = -1
// 		Nie można ułożyć słowa "kota" - brak liter!

// Odpowiedź: Można ułożyć maksymalnie 5 słów z wektora z podanych liter.

#include <iostream>
#include <vector>
#include <map>
void zrob(std::string a, std::vector<std::string> b)
{
    // Tworzymy mapę z literami i ilością ich wystąpień
    std::map<char, int> mapa;
    for (auto znak : a)
    {
        mapa[znak]++;
    }
    // zmienna do zliczania ilości słów
    int slowa = 0;

    // Sprawdzamy mozliwości ułożenia słów
    for (auto slowo : b)
    {
        // Tworzymy mapę z litarami slowa
        std::map<char, int> mapa_slowo;
        for (auto znak : slowo)
        {
            mapa_slowo[znak]++;
        }

        // // Wyswietl mape
        // std::cout << "Mapa slowa: " << slowo << std::endl;
        // for (auto znak : mapa_slowo)
        // {
        //     std::cout << znak.first << ": " << znak.second << std::endl;
        // }

        // Sprawdzamy czy można ułożyć slowo łącząc mapy
        // poprzez sprawdzenie czy jakakolwiek ilosc liter jest ujemna
        bool mozna = true;
        std::map<char, int> mapa_temp = mapa;

        while (mozna)
        {
            mapa_temp = mapa;

            // Różnica map mapa_slowo i mapa_temp
            for (auto znak : mapa_slowo)
            {
                mapa_temp[znak.first] -= znak.second;
            }

            // Sprawdzamy czy wszystkie jest jakakolwiek ujemna wartość
            for (auto znak : mapa_temp)
            {
                if (znak.second < 0)
                {
                    mozna = false;
                    break;
                }
            }
            if (!mozna)
                break;

            std::cout << "Mozna ulozyc slowo: " << slowo << std::endl;

            // Nadpisanie mapy
            mapa = mapa_temp;
            // Wyswietla nowa mape
            for (auto znak : mapa)
            {
                std::cout << znak.first << ": " << znak.second << std::endl;
            }
            slowa++;
        }
    }
    std::cout << "Mozna ulozyc " << slowa << " slow z wektora z podanych liter." << std::endl;
}

int main(int argc, char const *argv[])
{
    std::string a = "aaamlmlkkttmoaalkoamata";
    std::vector<std::string> b = {"ala", "ma", "kota"};
    zrob(a, b);
    return 0;
}

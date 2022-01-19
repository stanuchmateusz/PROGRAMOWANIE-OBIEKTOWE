#include <iostream>
#include <vector>
#include <map>

int main()
{
    // Przyklad uzycia kontenera vector
    std::vector<int> dane;
    dane.push_back(-3);
    dane.push_back(100);
    dane.push_back(8);
    dane.push_back(99);

    dane.pop_back();

    std::cout << "Elementy wektora z petla for:\n";
    for(int i = 0; i < dane.size(); i++)
    {
        std::cout << dane[i] << " ";
    }

    std::cout << "\nElementy wektora z petla for-each:\n";

    for (auto & element : dane)
    {
        std::cout << element << " ";
    }
    
    // Przyklad uzycia kontenera map - struktury danych podobnej do slownika (dictionary) z jezyka Python
    std::map<std::string, int> studenci;

    // dodawanie nowej pary klucz-wartosc
    auto student = std::pair<std::string, int> ("90010110013", 100123);
    studenci.insert(student);

    // dodawanie wartosci pod danym kluczem - jesli jeszcze takiego nie ma w mapie, zostanie wlasnie utworzony
    studenci["85060112345"] = 987654;

    // odczyt wartosci przechowywanej pod danym kluczem
    std::cout << studenci.at("85060112345") << "\n";
    std::cout << studenci["85060112345"] << "\n";

    for (auto & student : studenci) {
        std::cout << student.first << " : " << student.second << '\n';
    }

    // uwaga: istnienie lub brak danego klucza w mapie nalezy sprawdzac tylko za pomoca metody at()
    std::cout << studenci.at("nie ma takiego"); // rzuca wyjatek
    std::cout << studenci["takiego tez nie"] << "\n"; // ...ale teraz juz bedzie!
    std::cout << studenci.at("takiego tez nie") << "\n";

    return 0;
}
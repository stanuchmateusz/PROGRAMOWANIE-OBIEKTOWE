// Zad.1.
// Napisać program, który pozwoli użytkownikowi wprowadzić z klawiatury dane wybranej przez niego na początku liczby studentów. Format wprowadzanych danych:
// imie nazwisko numer_indeksu
// Numer indeksu ma zawsze 6 cyfr.
// Jeżeli użytkownik wpisał imię lub nazwisko z małej litery, program zamienia je na duże.
// jan kowalski 123456 -> Jan Kowalski 123456

// Przed zakończeniem programu, należy zapisać dane do pliku studenci.txt, w takim samym formacie jak wyżej (tzn. w jednej linijce: imie nazwisko indeks).

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main()
{
    cout << "Podaj ilosc studentow do wprowadzenia" << endl;
    int students_count;
    cin >> students_count;
    ofstream studenciFile;
    studenciFile.open("../studenci.txt");
    string temp;

    for (int i = 1; i <= students_count; i++)
    {
        cout << "Podaj dane studenta [" << i << "]" << endl;
        cin >> temp;
        temp[0] = toupper(temp[0]);
        studenciFile << temp << " ";
        cin >> temp;
        temp[0] = toupper(temp[0]);
        studenciFile << temp << " ";
        cin >> temp;
        studenciFile << temp.substr(0, 6) << endl;
    }
    studenciFile.close();

    return 0;
}
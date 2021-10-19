// Zad.2.
// Pobrać plik "movies.txt". Napisać strukturę, której pola odpowiadają informacjom o filmach zawartym w tym pliku (tytuł i rok premiery).
// Wczytać te dane z pliku do programu i zainicjalizować 10 instancji obiektów wczytanymi wartościami.
// Do wczytania wartości liczbowej z napisu do zmiennej int można wykorzystać metodę stoi() (string to int), dokumentacja i przykład użycia:
// https://en.cppreference.com/w/cpp/string/basic_string/stol
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct movie
{
    string title;
    int year;
    movie(string setTitle, int setYear) : title(setTitle), year(setYear){};
    void print()
    {
        cout << title << " (" << year << ")" << endl;
    }
};

int main()
{

    ifstream moviesFile("../movies.txt");
    if (moviesFile.is_open())
    {
        movie *movies_array[10];
        string line;
        for (int i = 0; i < 10; i++)
        {
            getline(moviesFile, line);
            movies_array[i] = new movie(line.substr(0, line.length() - 4), stol(line.substr(line.length() - 4, line.length())));
        }
        for (int i = 0; i < 10; i++)
            movies_array[i]->print();

        for (int i = 0; i < 10; i++)
            delete movies_array[i];
    }

    return 0;
}

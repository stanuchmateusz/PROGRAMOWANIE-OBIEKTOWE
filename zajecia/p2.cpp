#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "podaj slowo" << endl;
    string slowo;
    cin >> slowo;
    if (slowo.length() < 10)
        while (slowo.length() < 10)
            slowo += "_";
    else if (slowo.length() > 10)
        slowo = slowo.substr(0, 10);
    cout << slowo;
    size_t index = slowo.find("l");
    if (index != string::npos)
        cout << endl
             << "znaleziono l na pozycji " << index << endl;
    return 0;
}
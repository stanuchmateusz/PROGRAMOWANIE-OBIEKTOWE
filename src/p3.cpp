#include <iostream>
#include <string>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void swap_ref(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int main()
{
    // cout << "podaj slowo" << endl;
    int a = 1;
    int b = 21;
    cout << a << endl;
    cout << b << endl;

    swap_ref(a, b);

    cout << a << endl;
    cout << b << endl;

    swap(&a, &b);

    cout << a << endl;
    cout << b << endl;

    return 0;
}
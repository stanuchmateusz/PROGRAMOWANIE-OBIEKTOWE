#include <iostream>

using std::cout;
using std::endl;

template <typename T1, typename T2>
void my_swap(T1 &a, T2 &b)
{
    T1 tmp = a;
    a = (T1)b;
    b = (T2)tmp;
}

int main(int argc, char const *argv[])
{
    int a = 5.5;
    float b = 10;
    my_swap(a, b);
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}

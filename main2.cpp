#include <iostream>

using namespace std;
typedef unsigned long long tipo_entero;

int main()
{
    tipo_entero d = 3;
    while (d != 1)
    {
        if (d%2 != 0) d = (3*d)+1;
        else d = d/2;       
        cout << d << endl;
    }
    return 0;
}
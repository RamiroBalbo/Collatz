#include <iostream>
#include <math.h>

using namespace std;
typedef unsigned long long tipo_entero;

/*
bool primo(tipo_entero i){
    bool primo = 0;
        tipo_entero cont = 0; //acumulador
        for (tipo_entero k = i; k!=0; k--)
            if (i%k == 0)
                cont++;
        if (cont <= 2 )
            primo = true;
    return primo;
}
*/
bool primo(int n)
{
    const int SQRT_N = sqrt(n); //sqrt(n) == raiz de n

    if (n == 2) return true;
    else if (n % 2 == 0) return false;

    for (int i = 3; i <= SQRT_N; i+=2)
        if (n % i == 0) return false;

    return true;
}

int main()
{
    tipo_entero i = 1;
    while (true)
    {
        while (primo(i))
        {
            tipo_entero d = i;
            while (d != 1)
                if (d%2 != 0) d = (3*d)+1;
                else d = d/2;
            cout << i << endl;
            i++;
        }
        i++;
    }
    return 0;
}
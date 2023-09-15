#include <iostream>

using namespace std;

int main()
{
    int primo = 0;
    for (int i = 1; i!=0; i++){
        int cont = 0; //acumulador
        for (int d = i; d!=0; d--){
            if (i%d == 0)
                cont++;
        }
        if (cont == 2){
            primo = i;
            cout << primo << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;


int numar(int number, int c1, int c2) {
    
    int result = 0, p = 1;
    while(number>0) {
        int digit = number%10;
        number/=10;

        if(digit == c1) {
            digit = c2;
        }
        
        result = digit*p + result;
        p*=10;
    }

    return result;
}

void solveExercise4() {
    /*
        Se citesc numerele din fisier unul cate unu. Se verifica paritatea si daca numarul este par,
        se compara cu primul maxim. Daca primul maxim este mai mare is decat al doilea, valorile celor
        doua maxime se interschimba.
    */


    ifstream fin("numere.in");

    int maxim1 = -1, maxim2 = -1;
    while(!fin.eof()) {
        int number;
        fin>>number;

        if(number%2==0) {
            if(number>maxim1) {
                maxim1 = number;
                if(maxim1>maxim2) {
                    swap(maxim1,maxim2);
                }
            }
        }
    } fin.close();

    if(maxim1<maxim2) swap(maxim1,maxim2);
    cout<<maxim1<<' '<<maxim2;
}

int main() {
    solveExercise4();
    return 0;
}


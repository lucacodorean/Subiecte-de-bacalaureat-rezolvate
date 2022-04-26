#include <iostream>
#include <fstream>
using namespace std;

///problema 3
void numar(int number, int c1, int c2, int& result) {
    result = 0;
    
    int p = 1;
    while(number>0) {
        int digit =  number%10;
        number/=10;

        if(!(digit<=c2 && digit>=c1)) {
            result = digit*p + result;
            p*=10;
        }
    }
}

///problema 4
int prim(int number) {
    if(number == 2 || number == 3 || number==5 || number == 7){
        return 1;
    } else return 0;
}


int main() {

    /*
        Functia prim decide daca numarul citit este prim sau nu.
        Se citesc numerele. Daca numarul este prim si este mai mare
        decat maximul gasit, se reseteaza numarul de aparitii si se 
        actualizeaza valoarea maximului. Daca numarul este egal cu maximul
        numarul de aparitii creste.

    */


    ifstream fin("numere.in");

    int maxim  = -1, ap = 0;
    while(!fin.eof()) {
        int number;
        fin>>number;
        if(prim(number) == 1) {
            if(number>maxim) {
                ap = 0;
                maxim = number;
            }
            if (maxim == number) {
                ap++;
            }
        }
    } fin.close();

    cout<<maxim<<' '<<ap;

    return 0;
}
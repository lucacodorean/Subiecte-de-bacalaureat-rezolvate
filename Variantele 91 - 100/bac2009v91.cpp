#include <iostream>
#include <fstream>
#include <cfloat>
using namespace std;

int par(int numar) {
    while(numar>0) {
        if((numar%10)%2==0) {
            return 1;
        }

        numar/=10;
    }

    return 0;


    /*
        int n, cate =0;
        cin>>n;
        for(int i=0, number; i<n; i++) {
            cin>>number;

            if(par(number%10)==1) cate++;
        }

        cout<<cate;
    */
}

int main() {

    /*
        Se citeste fiecare numar si se compara cu maximul.
        Pentru numarul maxim gasit la prima sa aparitie sa va atribui
        valoarea pozitiei acestuia din fisier pentru ambele rezultate.
        La o ulterioara aparitie se modifica valoarea ultimei linii
        in care apare numarul.
    */

    ifstream fin("numere.in");
    int firstLine = 0, lastLine = 0, position = 0;
    float number, maxim = FLT_MIN;

    while(!fin.eof()) {
        fin>>number;
        position++;
        if(number>maxim) {
            maxim = number;
            firstLine = position;
            lastLine = position;
        } else if (number == maxim) {
            lastLine = position;
        }
    } fin.close();

    cout<<firstLine<<' '<<lastLine;

    return 0;
}


#include <iostream>
#include <fstream>
using namespace std;

int multiplii(int a, int b, int c) {
    int cate = 0;
    for(int value = a; value<=b; value ++) {
        if(value % c == 0) {
            cate++;
        }
    }
    return cate++;
}

int main() {
    
    /*
        Sotcam valorile de a doua linie a fisierului intr-un tablou unidimensional.
        Parcurgem elementele de pe a treia linie pe rand, si verificam, daca scazand elemente consecutive
        din tabloul salvat, ajungem la o valoare nula. Daca valoarea este negativa, atunci inseamna ca
        numarul nu poate sa fie scris ca si o suma de numere consecutive din tablou, deci trebuie sa se afiseze
        nu. In caz contrar, algoritmul continua pana ce se termina numerele de pe a doua linie. 

        Daca nu s-a gasit niciun numar negativ in urma algoritmului, se afiseaza "Da".

    */


    int number, data[101] = {0};
    int sizeofData, sizeofNumbers;
    
    ifstream fin("A.txt");

    fin>>sizeofData>>sizeofNumbers;

    for(int i=1; i<=sizeofData; i++) {
        fin>>data[i];
    }

    int start = 1;
    bool ok = true;

    for(int i=1; i<=sizeofNumbers; i++) {
        fin>>number;
        if(number>0) {
            do {
                number-=data[start++];
            } while(number>0);  
        }
 
        if(number<0) {
            ok = false;
            break;
        }
    } fin.close();

    ok == true ? cout<<"Da" : cout<<"Nu";
    return 0;
}   
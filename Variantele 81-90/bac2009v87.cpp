#include <iostream>
#include <fstream>
using namespace std;


/// problema 3
int reduce(int number, int value) {
    int sum = 0;

    while(number>0) {
        int digit = number%10;
        number/=10;

        if(value%digit!=0) sum+=digit;
    }

    return sum;
}


///problema 4

int scifPare(int number) {

    int sum = 0;

    while(number>0) {
        if((number%10)%2 == 0) {
            sum+=number%10;
        }
        number/=10;
    }
    return sum;
}

int scifImpare(int number) {

    int sum = 0;

    while(number>0) {
        if((number%10)%2 == 1) {
            sum+=number%10;
        }
        number/=10;
    }
    return sum;
}

int main() {

    /*
        Algoritmul parcuge numerele din fisier si verifica pentru fiecare daca suma cifrelor
        pare este egala cu cea a cifrelor impare. In cazul in care conditia este 
        adevarata, se compara numarul cu valoarea minima. Daca sunt egale se creste
        numarul de aparitii. In caz contrar daca numarul este mai mic decat minimul, 
        se reseteaza numarul de aparitii si valoarea minimului.


        Afisarea se face conform cerintei.
    */

    ifstream fin("numere.in");
    int ok = 0, minim = 10000001, ap = 0;

    while(!fin.eof()) {
        int number;
        fin>>number;
        if(scifImpare(number)==scifPare(number)) {
            if(number<minim) {
                ap=0;
                minim = number;
            }
            if(minim == number) {
                ap++;
                ok = 1;
            }
        }
    } fin.close();

    ok == 1 ? cout<<minim<<' '<<ap : cout<<"NU EXISTA";

    return 0;
}
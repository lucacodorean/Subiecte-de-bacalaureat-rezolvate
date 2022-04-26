#include <iostream>
#include <fstream>
using namespace std;

void numar(int& number, int c1, int c2) {
    
    int aux = number, cate = 0, result = 0;
    int ok = 0;

    while(aux>0) {
        cate++;
        aux/=10;
    }

    int p = 1;
    while(cate>1) {
        p*=10;
        cate--;
    }

    aux = number;
    while(p>0) {
        int digit = (aux/p)%10;
        if (digit == c1 && ok == 0) {
            digit = c2;
            ok = 1;
        } else if(ok == 1) digit = 0; 

        result = result * 10 + digit;
        p/=10;
    }

    number = result;
}

void solveExercise4() {
    
    ifstream fin("numere.in");

    /*
        Algoritmul citeste numerele din fisier si le marcheaza prezenta in vectorul de
        frecventa. Se parcurge intervalul [0,99] si daca numarul este mai mare decat k
        si valoarea din vectorul de frecventa este diferita de 0, atunci se afiseaza numarul.
    */

    int freq[100] = {0}, k;
    while(!fin.eof()) {
        int number; fin>>number;
        freq[number]=1;
    } fin.close();

    cin>>k;

    for(int number=99; number>=0; number--) {
        if(number>k && freq[number]==1) {
            cout<<number<<' ';
        }
    }
}

int main() {
    solveExercise4();
    return 0;
}
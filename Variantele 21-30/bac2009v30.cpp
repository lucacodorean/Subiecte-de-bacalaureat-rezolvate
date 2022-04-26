#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int suma(int data[], int size, int i, int j) {
    int sum = 0;

    for(int k = 1; k<=size; k ++) {
        sum+=data[k];
    }

    for(int k = i; k<=j; k ++) {
        sum-=data[k];
    }

    return sum;
}

int main() {

    /*
        Exista cel putin un interval care poate sa cuprinda toate numerele din fisierul numere.txt (cazul in care TOATE numerele apartin intervalului [x, x+1]).
        Se citeste n, dupa care primul numar de pe a doua linie. Contorul de numere scade si se citeste al doilea numar. Se fac verificari din aproape in aproape, dat fiind faptul ca
        numerele din fisier sunt ordonate crescator. De fiecare data cand partea intreaga a elementului din fata elementului citit este diferita de partea intreaga a elementului citit se
        marcheaza incheierea unui interval de tipul [x,x+1], iar contorul acestora (variabila integer cate) creste cu 1.

        Pentru cazurile in care x-ul citit are o valoare de tipul x = [x_ant] + 1 se va scadea valoarea contorului cate pentru ca se considera ca numarul proaspat citit apartine
        intervalului [x, x+1].

        Programul este eficient pentru presupune parcurgerea elementelor din fisier o singura data. Programul foloseste doua variabile integer si doua double deci in total 24 de bytes.
        Pentru ca variabila n poate sa fie 100 in cel mai rau caz, programul va executa maxim 99 de pasi.
    */

    ifstream fin("A.txt");

    int n, cate = 1;
    fin>>n;
    double x_ant, x;
    fin>>x_ant; n--;
    while(n>0) {
        fin>>x;
        if(int(x_ant)!=int(x)) {
            cate++;
        }
        if (x == int(x_ant) + 1) cate--;
        x_ant = x;
        n--;
    }

    cout<<cate;
    return 0;
}

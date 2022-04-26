#include <iostream>
#include <fstream>
#include <algorithm>
#define MAX 1001
using namespace std;

ifstream fin("numere.txt");

void p(double arr[], int size) {

    for(int i=1; i<=size; i++) {
        fin>>arr[i];
    }

    for(int i=1; i<=size; i++) {
        bool ok = true;
        for(int j=i; j<=size; j++) {
            if(arr[i]==arr[j]) ok = false;
        }
        if(ok == true) cout<<arr[i]<<' ';
    }
}

void getSolution() {

    /*
        Vectori de aparitii. Crestem valoarea aparitiei pentru fiecare valoare citita.
        Parcurgem vectorul de aparitii si afisam valoarea cat timp valoarea din array
        corespondenta acesteia este mai mare decat 0.

        Algoritmul foloseste doar un vector de aparitii si o variabila 
        auxiliara care retine numarul de elemente care se afla in fisierul dat.
    */


    int ap[MAX] = {0}, size;
    fin>>size;

    for(int i=1, x; i<=size; i++) {
        fin>>x;
        ap[x] ++;
    } fin.close();

    for(int i=1; i<=99; i++) {
        while(ap[i]>0) {
            cout<<i<<' ';
            ap[i]--;
        }
    }
}

int main () {
    getSolution();
    return 0;
}
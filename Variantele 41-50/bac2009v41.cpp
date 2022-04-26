#include <iostream>
#include <fstream>
#include <cmath>
#define MAX 10001
using namespace std;



bool DST(int v[], int n) {
    bool ok = true;

    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            if(v[i]==v[j]) {
                ok = false;
            
            }
        }

        if(abs(v[i-1]-v[i])==1 && abs(v[i]-v[i+1])==1) ok = false;
    }

    return ok;
}

void Solver() {

    /*
        Solutia adauga in vectorul de aparitii valoarea 1 de fiecare data cand o cifra este citita. La fiecare
        cifra citita este calculat maximul.

        Se afiseaza maximul si aparitiile acestuia indata ce toate numerele au fost parcurse. Dpdv. al memoriei
        problema este foarte eficienta, ea folosind doua variabile integer, cat si array-ul de aparitii.
    */

    ifstream fin("numere.txt");

    int ap[10] = {0}, maxVal = -1;
    int size; fin>>size;

    for(int i=1; i<=size; i++) {
        int x;
        fin>>x;
        ap[x] ++;
        maxVal = max(maxVal, x);
    } fin.close();

    cout<<maxVal<<' '<<ap[maxVal];
}

int main() {
    Solver();
    return 0;
}


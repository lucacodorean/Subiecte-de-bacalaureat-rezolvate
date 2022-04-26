#include <iostream>
#include <fstream>

using namespace std;

int p(int v[], int n) {
    int s = 0;
    for(int i=1; i<=n; i++) {
        cin>>v[i];
    }

    for(int i=1; i<=n; i++) {
        if(i%2==0 && v[i]%2!=0) s+=v[i];
    }

    return s;
}

void getSolution() {

    /*
        Algoritmmul preia cifrele si noteaza numarul de aparitii. Acesta parcurge dupa vectorul de aparitii de la 9 la 0 astfel incat sa se obtina
        cel mai mare numar posibil.
    */

    ifstream fin("numere.txt");

    int ap[11] = {0}, size;
    fin>>size;

    for(int i=1, x; i<=size; i++) {
        fin>>x;
        ap[x] ++;
    } fin.close();

    for(int i=9; i>=0; i--) {
        while(ap[i]>0) {
            cout<<i;
            ap[i]--;
        }
    }
}


int main() {
    getSolution();
    return 0;
}
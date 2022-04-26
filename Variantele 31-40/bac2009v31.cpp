#include <iostream>
#include <fstream>
using namespace std;



void suma (int data[], int size, int m) {
    
    int s = 0

    for(int i=1; i<=size; i++) {
        for(int j = i+1; j<size; j++) {
            if(data[i]<data[j]) swap(data[i],data[j]);
        }
    }

    for(int i=1; i<=m; i++) {
        s+=this->data[i];
    }

    return s;
}


int main() {

    ifstream fin("numere.txt");
    /*
        Algoritmul citeste primul interval [x_ant, y_ant]. Pentru urmatorii n-1 pasi se citesc perechi de forma [x,y]. 
        Se calculeaza intersectia intervalelor doua cate doua, comparand mereu cu intervalul de inainte dupa formula:

            x = max (x_ant,x); y = min (y_ant, y). x_ant si y_ant preiau rezultatele obtinute in urma calcularii
            maximului si minimului, iar variabila contor scade; 

        Retiem intr-o variabila de tip bool daca exista un punct comun intre intervalele date, si daca exista, afisam
        afisam rezultatul. In caz contrar, se afiseaza 0 conform cerintei.

        Algoritmul este extrem de eficient in ceea ce priveste timpul de executie, el executand n-1 pasi. In ceea ce 
        priveste memoria, el foloseste 5 variabile de tip integer si una de tip boolean, deci in total 21 de bytes.
    */

    int n;
    fin>>n;
    int x_ant, y_ant;
    fin>>x_ant>>y_ant; n--;
    bool ok = false;
    while(n > 0) {
        int x, y;
        fin>>x>>y;
        x = max(x_ant, x);
        y = min(y_ant, y);
        x_ant = x;
        y_ant = y;
        n--; 
        ok = true;
    }
 
    ok == true ? cout<<x_ant<<' '<<y_ant : cout<< 0;

    return 0;
}
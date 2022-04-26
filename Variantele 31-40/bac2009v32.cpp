#include <iostream>
#include <fstream>

#define MAX_VALUE 100
using namespace std;


int nr_prim(int x) {
    int result = x+1;
    for(int i=2; i<result; i++) {
        if(result % i == 0 ) {
            result ++;
            i = 2;
        }
    }
    return result;
}


int main() {

    ifstream fin("A.txt");

    /*
        Programul citeste numerele din fisier si urmeaza sa le prelucreze doar
        pe cele din intervalele [-99,10] respectiv [10,99]. Pentru fiecare 
        numar citit, se verifica daca este mai mic decat primul minim. In caz 
        afirmativ, valoarea minimului2 preia valoarea minimului1, ia minim1 preia
        valoarea lui x.
        
        In cazul in care x este mai mic decat minim2 si x este diferit de minim1, minim2 preia valoarea lui x.

        Programul afisesaza 0 daca unul dintre minime NU s-a modificat, respectiv
        cele doua minime in caz contrar.

        Programul este eficient in ceea ce priveste memoria, el folosind 3 variabile integer, adica 3 bytes.
        Dpdv. al timpului de executie, algoritmul este rapid, parcurgand datele de intrare din fisier o singura data.
    */

    int min1, min2,x;
    min1=min2=MAX_VALUE;

    while(!fin.eof()) {
        fin>>x;
        if((x>=10 && x<=99) || (x>=-99 && x<=-10)) {
            if(x<min1){
                min2 = min1;
                min1 = x;
            } else if(x<min2) {
                if(x!=min1) min2 = x;
            }
        }
    }
    fin.close();

    if(min1== MAX_VALUE || min2 == MAX_VALUE) cout<<0;
    else cout<<min1<<" "<<min2;

    return 0;
}
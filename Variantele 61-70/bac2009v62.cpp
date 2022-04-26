#include <iostream>
#include <fstream>

using namespace std;

#define LESS_THAN -1
#define EQUAL 0
#define GREATER_THAN 1
#define LIMIT 1005


int compara(int a, int b) {
   if(a%2 == b%2) {
       if(a<b) return (a%2==0) ? LESS_THAN : GREATER_THAN;
       if(a>b) return (a%2==0) ? GREATER_THAN : LESS_THAN;
       else return EQUAL;
   }

   if(a%2 < b%2) return LESS_THAN;
   if(a%2 > b%2) return GREATER_THAN;
}

void fibo(int n, int v[]) {
    

    int lung = 0, auxN = n;

    v[++lung] = 1;
    v[++lung] = 1;

    int value, anterior=1, preAnterior=1;

    while(n>=0) {

        value = anterior + preAnterior;

        if(value % 2 != 0) {
            v[++lung] = value;
            n--;
        }

        preAnterior = anterior;
        anterior = value;
    }
}

void solveExercise3() {
    int x;
    cin>>x;
    int v[LIMIT];
    
    fibo(x,v);
}

void solveExercise4() {

/*
    Se citesc valori din fisier. Acestea se stocheaza intr-un tablu
    unidimensional care urmeaza sa fie sortat pe baza paritatii.
    Elementele tabloului se afiseaza doar in cazul in care sunt diferite
    fata de anteriorul lor, pentru a evita repetitia numerelor. In momentul
    in care se face trecerea de la numere impare la pare, se afiseaza un
    endline.
*/

    ifstream fin("data.in");
    ofstream fout("data.out");

    int lung = 0, v[10005];

    while(!fin.eof()) {
        fin>>v[++lung];
    } fin.close();


    for(int i=1; i<=lung; i++) {
        for(int j = i+1; j<=lung; j++) {
            if(compara(v[i],v[j])==LESS_THAN) swap(v[i],v[j]);
        }
    }

    for(int i=1; i<=lung; i++) {
        if(v[i] != v[i-1]){ 
            if(v[i]%2 == 0 && v[i-1]%2!=0) fout<<endl;
            else fout<<v[i]<<' ';
        }
    } fin.close();
    
}

int main() {
    
    solveExercise3();
    solveExercise4();

    return 0;
}

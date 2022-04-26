#include <iostream>
#include <fstream>
using namespace std;

int suma(int arr[], int size) {
    int suma = 0;
    
    for(int i = 0; i<size; i++) {
        if(arr[i]%100 == arr[i]/100) suma+=arr[i];
    }

    return suma;
}

void solveExercise4() {
    /*
        Se citesc numerele din fisier; lungimea secventei creste pentru fiecare numar citit. 
        Se calculeaza maximul pe secventa. Daca se ajunge la un element 0, se determina
        lungimea minima pana in acel punct, dupa care se verifica daca maximul gasit pe secventa
        este mai mare decat maximul determinat pana in acel punct, pentru secventa de lungime minima.
        Se reseteaza lungimea.


        In cele din urma se afiseaza maximul, salvat in variabila stored.

    */


    ifstream fin("numere.in");
    ofstream fout("numere.out");

    int number, maxim = -1, stored = -1;
    int l = 0, lMin = 501;
    while(!fin.eof()) {
        fin>>number;
        maxim = max(maxim, number);
        l++;
        if(number == 0) {
            lMin = min(lMin, l);
            if(stored<maxim && l == lMin) {
                stored = maxim;
            }
            l = 0;
        }
    } fin.close();

    fout<<stored;
    fout.close();
}

int main() {
    solveExercise4();

    return 0;
}
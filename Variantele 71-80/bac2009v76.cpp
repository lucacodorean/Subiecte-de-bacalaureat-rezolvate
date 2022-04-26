#include <iostream>
#include <fstream>
using namespace std;


int cifreInterval(int number, int c) {
    int result = 0;
    
    while(number>0) {
        int digit =  number % 10;
        number/=10;
        if(digit>=c-1 && digit<=c+1) result++;
    }

    return result;
}

void solveExercise4() {


    /*
        Se citesc numerele din fisier. Pentru fiecare numar de pe prima
        linie, se creste numarul de aparitii.
        Pentru a doua linie, se citesc numerele, cresc aparitiile si se verifica
        daca valoarea din vectorul de aparitii este strict 2, pentru a evita situatiile in care
        se afiseaza un numar de doua ori. 

        Complexitatea este: O(n) + O(m) = O(n+m).

    */


    ifstream fin("bac.txt");

    int n,m, ap[100001] = {0};
    fin>>n>>m;
    while(n>0) {
        int number;
        fin>>number;
        ap[number]++;
        n--;
    }

    while(m>0) {
        int number;
        fin>>number;
        ap[number]++;

        ap[number]==2 ? cout<<number<<' ' : cout<<"";
        
        m--;
    } fin.close();
}

int main() {
    solveExercise4();

    return 0;
}
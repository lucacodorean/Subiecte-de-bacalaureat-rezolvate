#include <iostream>
#include <fstream>
using namespace std;

int prim(int number) {
    for(int divizor = 2; divizor*divizor<=number; divizor++) {
        if(number%divizor==0) {
            return 0;
        }
    }

    return 1;
}

void solveExercise3() {
    int limit, parameter = 2, cate = 1;
    cin>>limit;
    while(cate<=limit) {

        if(prim(parameter) == 1) {
            cout<<parameter<<' ';
            cate++;
        }
         
        parameter++;
    }
}

void solveExercise4() {

    /*
        Se citesc numerele unul cate unu. Se actualizeaza valoarea
        din vectorul de aparitii. Se calculeaza valoarea maxim citita;
        Se parcurg toate numerele de la valoarea maxim citita spre 1 si
        se afiseaza perechea numar - aparitii.
    */

    ifstream fin("bac.txt");

    int n, ap[101] = {0}, maxim = -1;
    fin>>n;

    while(!fin.eof()) {
        fin>>n;
        ap[n] ++;
        maxim = max(maxim, n);
    } fin.close();

    for(int number = maxim; number >=1; number --) {
        cout<<number<<' '<<ap[number]<<'\n';
    }
}
 

int main() {
    solveExercise4();

    return 0;
}
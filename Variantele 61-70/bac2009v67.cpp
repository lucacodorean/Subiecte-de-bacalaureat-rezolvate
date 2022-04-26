#include <iostream>
#include <fstream>

using namespace std;

bool prime(int n) {
    bool ok = true;

    for(int d=2; d*d<=n; d++) {
        if(n%d == 0) {
            ok = false;
            break;
        }
    }

    return ok;
}

int calcul(int n, int a[]) {
    int cate = 0;
    for(int i=1; i<=n; i++) {
        if(prime(a[i])==true) cate++;
    }

    return cate;
}

void solveExercise3() {
    int n = 5;
    int a[] = {12,37,43,6,71};

    cout<<calcul(n,a);
}

void Solver::solveExercise4() {

/*
    Programul citeste datele. Citeste si afiseaza primul numar individual de restul.
    Restul numerelor sunt comparate cu anteriorul lor. Daca sunt diferite, numarul curent 
    se afiseaza.
*/

    ifstream fin("data.in");

    int n; fin>>n;

    int x, x_ant;

    fin>>x_ant; n--;
    cout<<x_ant<<' ';
    while(n>0) {
        fin>>x;

        if(x_ant != x) cout<<x<<' ';
        x_ant = x;
        n--;
    } fin.close();
}

int main() {
    //solveExercise3();
    solveExercise4();

    return 0;
}

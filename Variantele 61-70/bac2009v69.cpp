#include <iostream>
#include <fstream>

using namespace std;


int calcul(int n) {
    int pare = 0, impare = 0;
    while(n>0) {
        int c = n%10;
        c%2==0 ? pare++ : impare++;
        n/=10;
    }

    return abs(pare-impare);
}

void solveExercise3() {
    int n; cin>>n;

    for(int number = n; number < 10000000; number++) {
        if(calcul(number) == 0) {
            cout<<number<<' ';
            break;
        }
    }
}

void solveExercise4() {

/*
    Profitam de faptul ca numerele sunt ordonate crescator.
    La citirea numerelor le afisam pe cele pare. Daca sunt impare,
    le adaugam intr-un tablou unidimensional pe care-l parcurgem invers
    pentru afisare.

*/

    ifstream fin("data.in");
    ofstream fout("data.out");

    int x, n;
    int lung = 0, v[LIMIT];

    fin>>n;

    while(n>0) {
        fin>>x;
        if(x%2==0) fout<<x<<' ';
        else v[++lung] = x;
        n--;
    } fin.close();

    for(int i=lung; i>=1; i--) fout<<v[i]<<' ';
    fout.close();

}

int main() {

    //solveExercise3();
    solveExercise4();

    return 0;
}

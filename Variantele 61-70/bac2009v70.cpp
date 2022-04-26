#include <iostream>
#include <fstream>
#include <climits>

using namespace std;


void calcul(int n, int &x) {

    x=0;

    while(n>0) {
        int digit = n%10;
        if(digit%2==0) x=x*10+digit;
        n/=10;
    }
}

void solveExercise3() {
    int x = 0;
    calcul(9278,x);
    cout<<x;
}

void solveExercise4() {
    int n, x_ant, lung = 1, element=0, maxim = 1;
    
    ifstream fin("data.in");
    ofstream fout("data.out");

    fin>>n;
    fin>>x_ant;
    n--;

    for(int i=1, x; i<=n; i++) {
        fin>>x;

        if(x_ant == x) {
            lung++;
        }
        else {
            if(lung > maxim) {
                maxim = lung;
                element = x_ant;
            }
            lung = 1;
        }

        x_ant = x;
    } fin.close();

    fout<<element<<' '<<maxim;
    fout.close();
}

int main() {
    //solveExercise3();
    solveExercise4();

    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;


/// problema 3
int verif (int number, int a) {
    int ok = 1;
    while(number>0) {
        int digit = number%10;
        number/=10;

        if(digit>a) {
            ok = 0;
            break;
        }
    }

    return ok;
}

void solveExercise3() {

    int number; cin>>number;
    int aux = number, maxim = 0;

    while(aux>0) {
        maxim = max(maxim, aux%10);
        aux/=10;
    }

    for(int base=2; base<maxim; base++) {
        if(verif(number, base)==0) {
            cout<<base<<' ';
        }
    }

    maxim > 1 ? cout<<maxim : cout<<"";

}


///problema 4
int main() {
    ifstream fin("numere.in");
    int x_ant,x, difMax = 0;
    int maxim = -1, termenP, termenS;

    fin>>x_ant;
    while(!fin.eof()) {
        fin>>x;
        if(x>0 && x_ant>0) {
            if(x_ant+x > maxim) {
                if(x_ant-x > difMax) {
                    difMax = x_ant-x;
                    maxim = x_ant+x;
                    termenP = x_ant;
                    termenS = x;
                }
            }
        }

        x_ant = x;
    } fin.close();

    cout<<termenP<<' '<<termenS;

    return 0;
}
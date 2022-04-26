#include <iostream>
#include <fstream>

using namespace std;

long long oglindit(long long x) {
    long long aux = 0;
    
    while(x>0) {
        short cifra = x % 10;
        aux = aux * 10 + cifra;
        x/=10;
    }

    return aux;
}

bool sfx(long long x) {
    bool ok = false;

    if ((x % 10 < (x/10)%10) && ((x/10)%10 < (x/100)%10)) ok = true;

    return ok;
}

void solveExercise3() {
    int x; cin>>x;
    int y = x/1000;

    (sfx(x) == true && sfx(y) == true) ? cout<<"Da" : cout<<"Nu";
}

void solveExercise4() {
/*
    Programul construieste triplete. Citeste initial primele doua valori, urmand sa
    le citeasca pe restul. Cele trei valori se verifica conform indicatiei date. 
    In caz afirmativ, se creste un contor. x_ant preia valoarea din x, iar x valoarea
    din x_urm cu scopul de a munta tripletul cu o pozitie spre sfaristul sirului.
*/

    ifstream fin("data.in");

    int x_ant, x, x_urm, cate = 0;
    fin>>x_ant>>x;

    while(!fin.eof()) {
        fin>>x_urm;

        if(x>(x_ant + x_urm)) cate++;

        x_ant = x;
        x = x_urm;

    } fin.close();

    cout<<cate;
}

int main() {
    //solveExercise3();
    solveExercise4();

    return 0;
}

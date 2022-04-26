#include <iostream>
#include <fstream>

using namespace std;


int verif(int number) {
    bool ok = false;
    int current = 0, lastDigit, result = 0;

    lastDigit = number % 10;
    number/=10;

    if(lastDigit % 2 != 0) current ++;

    while(number>0) {
        int digit = number % 10;
        if(digit % 2 == 0) current = 0;
        if(digit % 2 != 0) current ++;
        number/=10;

        lastDigit = digit;
    
        if (current >= 3) result = current;
    }

    result!=0 ? ok = true : ok = false;

    return ok;
}

void solveExercise3() {
    int x; cin>>x;

    x/=1000;

    verif(x) == true ? cout<<"Da" : cout<<"Nu";
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

        if(x<(x_ant + x_urm)) cate++;

        x_ant = x;
        x = x_urm;

    } fin.close();

    cout<<cate;
}

int main() {

    solveExercise3();
    solveExercise4();

    return 0;
}

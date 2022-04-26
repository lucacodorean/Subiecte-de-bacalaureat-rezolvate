#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


int nrCif(int number) {
    int cate = 0;
    while(number>0) {
        number/=10;
        cate++;   
    }
    return cate;
}

void maxim(float a, float b, float &c) {
    c = 0.0;

    float zecimaleA, zecimaleB, aux;
    zecimaleA = (a - (int)a) * 100;
    zecimaleB = (b - (int)b) * 100;

    float auxA, auxB;

    auxA = zecimaleA + (int(a)/(pow(10,nrCif(a))));
    auxB = zecimaleB + (int(b)/(pow(10,nrCif(b))));

    c = max(max(a,b), max(auxA,auxB));
}

void solveExercise4() {
    ifstream fin("bac.txt");

    int freq[101] = {0}, number, ok = 0;
    fin>>number;

    while(!fin.eof()) {
        fin>>number;
        freq[number] = 1;
    } fin.close();


    for(int number=1; number<=100; number++) {
        if(freq[number] == 0) {
            cout<<number<<' ';
            ok = 1;
        }
    }

    ok == 0 ? cout<<"NU LIPSESTE NICIUN NUMAR" : cout<<"";
}

int main() {
    float c;
    maxim(33.17, 15.40, c);
    cout<<c;
    return 0;
}
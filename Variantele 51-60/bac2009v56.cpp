#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#define LIMIT 1001

void solveExercise3() {
    ifstream fin("numere.in");

    int ap[LIMIT] = {0};
    while(!fin.eof()) {
        int number; fin>>number;
        if(number%2==0) ap[number] ++;
    } fin.close();

    for(int number=0; number<=LIMIT-5; number+=2) {
        while(ap[number]!=0) {
            cout<<number<<' ';
            ap[number]--;
        }
    }
}

bool prim(int x) {
    bool ok = true;

    for(int i=2; i<=sqrt(x); i++) {
        if(x%i==0) {
            ok = false;
            break;
        } 
    }

    return ok;
}

void numar(int x, int &result) {
    if(x>=2) result = 1;
    else result = 0;

    for(int number=3; number<=x; number+=2) {
        if(prim(number)==true) {
            result ++;
        }
    }
}

void solveExercise4() {
    int a, b; cin>>a>>b;
    int primeNumbers = 0;

    if(a>b) swap(a,b);

    int primesUntilA = 0; this->numar(a, primesUntilA);
    int primesUntilB = 0; this->numar(b, primesUntilB);

    primeNumbers = primesUntilB - primesUntilA;

    primeNumbers>=1 ? cout<<"DA" : cout<<"NU";

}

int main() {
    solveExercise3();
    solveExercise4();

    return 0;
}

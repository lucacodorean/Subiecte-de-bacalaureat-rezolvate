#include <iostream>
#include <fstream>
using namespace std;

#define LIMIT 1005

void divizor(int number, int &d) {
    for(int divisors = 2; divisors<number; divisors++) {
        if(number%divisors==0) {
            d = divisors;
            break;
        }
    }
}

void solveExercise3() {

    int v[LIMIT];
    ifstream fin("numere.in");

    int size = 0;
    int p = 1;

    while(!fin.eof()) {
        fin>>v[++size];
    } fin.close();

    for(int i=size; i>size-3; i--) p*=v[i];

    cout<<p%10;
}

void solveExercise4() {
    int number; 
    cin>>number;

    int prime = 1;
    divizor(number, prime);

    prime == 1 ? cout<<"DA" : cout<<"NU";
}

int main() {
    solveExercise3();
    solveExercise4();

    return 0;
}
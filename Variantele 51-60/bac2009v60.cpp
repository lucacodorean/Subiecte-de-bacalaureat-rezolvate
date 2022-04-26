#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
#define LIMIT 1005

void solveExercise3() {
    bool v[LIMIT] = { false };

    ifstream fin("numere.in");

   for(int i=1; i<=100; i++) {
       int x; fin>>x;
       v[x] = true;
    } fin.close();

    int value; fin>>value;

    v[value] == true ? cout<<"DA" : cout<<"NU";
}

void radical(int a, int &x) {
    int squareRootofA = sqrt(a);

    for(int number = 1; number<=squareRootofA; number++) {
        if(number*number <= a) {
            x = number;
        }
    }
}

void solveExercise4() {
    int n, x = 0;
    cin>>n;
    radical(n,x);

    x*x == n ? cout<<"Da" : cout<<"Nu";
}

int main() {
    //solveExercise3();
    solveExercise4();

    return 0;
}

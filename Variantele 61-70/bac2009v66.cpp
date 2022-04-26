#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int cmmdc(int a, int b) {
    int r;
    while(b!=0) {
        r = a%b;
        a = b; 
        b = r;
    }

    return a;
}

void solveExercise3() {

    ifstream fin("data.in");

    int n,x_ant, result = 1; fin>>n;
    fin>>x_ant;
    for(int i=2; i<=n; i++) {
        int x; fin>>x;

        result = cmmdc(x_ant,x);

        x_ant = x;
    } fin.close();

    cout<<result;
}

void solveExercise4() {
/*
    Citesc elementele din B.txt prima data si calculez valoarea minima din el.
    Citesc elementele din A.txt si compar cu minimul gasit.
    Adaug la contor.
    
*/

    ifstream fin;

    fin.open("B.txt");

    int x, cate=0, minim = INT_MAX;

    while(!fin.eof()) {
        fin>>x;
        minim = min(minim, x);
    } fin.close();


    fin.open("A.txt");

    while(!fin.eof()) {
        fin>>x;
        if(x<minim) {
            cate++;
        }
    } fin.close();

    cout<<cate;
}

int main() {
    //solveExercise3();
    solveExercise4();

    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;


//problema 3
int function(int firstArray[], int sizeA, int secondArray[], int sizeB) {
    int sum = 0, result = 0;
    
    for(int i=0; i<sizeA; i++) {
        if(firstArray[i]%2==0) sum+=firstArray[i];
    }

    for(int i=0; i<sizeB; i++) {
        if(secondArray[i]%2==1 && secondArray[i]<sum) result +=secondArray[i];
    }

    return result;


    /*
        int a[] = {2,3,7,8}, b[] = {44,3,1,8};
        int sizeA = 4, sizeB = 4;

        cout<<function(a,sizeA,b,sizeB);
    */
}

/// problema 4
///a)
int cmmmc(int x, int y);

///b)

int cmmdc(int x, int y) {
    int r;
    while(y) {
        r = x%y;
        x = y;
        y = r;
    }

    return x;
}

int cmmmc(int x, int y) {
    return (x*y)/cmmdc(x,y);
}

void solveExercise4() {
    ifstream fin("numere.in");
    ofstream fout("numere.out");

    while(!fin.eof()) {
        int x,y;
        fin>>x>>y;

        fout<<cmmmc(x,y)<<'\n';
    } fin.close(), fout.close();
}

int main() {
    solveExercise4();
    return 0;
}
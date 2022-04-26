#include <iostream>
#include <fstream>
using namespace std;

/// problema 3

int function(int arrA[], int arrB[], int size) {
    int sum = 0, result = 0, l = 0;
    
    for(int i=0; i<size; i++) {
        if(arrA[i]%2==0) {
            sum+=arrA[i];
            l++;
        }
    }

    int average = sum/l;

    for(int i=0; i<size; i++) {
        if(arrB[i]<average) result+=arrB[i];
    }

    return result;

    /*
        int a[] = {2,3,7,8}, b[] = {44,3,1,8};
        int size;

        cout<<function(a,b,size);
    */
}


/// problema 4
int cmmdc(int x, int y);

int cmmdc(int x, int y) {
    int r;
    while(y) {
        r = x%y;
        x = y;
        y = r;
    }

    return x;
}

void solveExercise4() {
    ifstream fin("numere.in");
    ofstream fout("numere.out");

    while(!fin.eof()) {
        int numarator, numitor;
        fin>>numarator>>numitor;
        int simplificare = cmmdc(numarator, numitor);

        fout<<numarator/simplificare<<' '<<numitor/simplificare<<endl;
    } fin.close(), fout.close();
}

int main() {
    solveExercise4();
    return 0;
}
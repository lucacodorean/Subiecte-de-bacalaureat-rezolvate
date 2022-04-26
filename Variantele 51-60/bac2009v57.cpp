#include <iostream>
#include <fstream>

using namespace std;

bool find(int suma, int v[], int size) {
    for(int i=0; i<size; i++) {
        if(suma==v[i]) {
            return false;
        } 
    }
    return true;
}

void sort(int v[], int size) {
    for(int i=0; i<size; i++) {
        for(int j=i; j<=size; j++) {
            if(v[i]>v[j]) {
                swap(v[i],v[j]);
            }
        }
    }
}

int multiplu(int a, int k) {
    
    int solution = 0;

    for(int number = a; number<k*a; number++) {
        if(number%k==0) {
            solution = number;
            break;
        }
    }

    return solution;
}

void solveExercise3() {

    ifstream fin("numere.in");
    ofstream fout("numere.out");

    int v[LIMIT], result[LIMIT], lung = 0, k = 0;

    while(!fin.eof()){
        fin>>v[++lung];
    } fin.close();

    for(int i=1; i<=lung; i++) {
        for(int j=i+1; j<=lung; j++) {
            int suma = v[i] + v[j];
            bool ok = find(suma, result, k);
            if(ok == true) {
                result[++k] = suma;
            }
        }
    }

    sort(result, k);

    for(int i=1; i<=k; i++) fout<<result[i]<<' ';

    fout.close();
}

void solveExercise4() {

    int x,y,z;
    int result = 0;
    cin>>x>>y>>z;

    if(x>y) swap(x,y);

    int delaX = this->multiplu(x,z);

    if(delaX!=0 && delaX<=y) cout<<"Da";
    else cout<<"Nu";
}

int main() {
    //solveExercise3();
    solveExercise4();

    return 0;
}

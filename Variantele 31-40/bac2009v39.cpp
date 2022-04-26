#include <iostream>
#include <fstream>
#define MAX 1001
using namespace std;

ifstream fin("A.txt");

void ex3() {
    int n;
    int v[1001];
    bool ok = false;

    fin>>n;
    for(int i=1; i<=n; i++) {
        fin>>v[i];
    }

    for(int i=1; i<=n; i++) {
        if(v[i]%2==0) {
            for(int j=i; j<=n; j++) {
                if(v[i]>v[j]) {
                    ok = true;
                } else ok = false;
            }
        }
    }

    ok ? cout<<"DA" : cout<<"NU";
}

int cifNumber(int x) {
    int number = 0;
    while (x > 0) {
        number++;
        x /= 10;
    }

    return number;
}

bool pr(int x) {
    for (int div = 2; div < x; div++) {
        if (x % div == 0) {
            return false;
        }
    }
    return true;
}

void Solve() {

    int number;

    fin >> number;
    int aux = cifNumber(number);

    while(aux > 2) {
        int auxiliaryValue = number / 10;
        number /= 10;
        if (pr(auxiliaryValue) == true) {
            cout << auxiliaryValue << ' ';
        }
        aux--;
    }
}

int main () {
    Solve();
    return 0;
}
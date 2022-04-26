#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void s3() {
    
    ifstream fin("A.txt");
    
    int n,k;
    cin>>k;
    fin>>n;

    for(int i=1, number; i<=n; i++) {
        fin>>number;
        int aux = number, result=1, exp = 0;
        while(number>=1) {
            number/=k;
            exp++;
        }

        for(int i=1; i<exp; i++) {
            result*=k;
        }

        if(result==aux) cout<<aux<<' ';
    } fin.close();
}

void cif(int number, int& sc) {
    sc = 0;
    while(number>0) {
        sc+=(number%10);
        number/=10;
    }
} 

void s4() {
    
    ifstream fin("A.txt");

    int size, maxim = 0, values[100];
    fin>>size;

    for(int i=1, sc = 0; i<=size; i++) {
        fin>>values[i];
        cif(values[i], sc);
        maxim = max(maxim,sc);
    } fin.close();

    for(int i=1; i<=size; i++) {
        int sc = 0;
        cif(values[i], sc);
        if (maxim == sc) cout<<values[i]<<' ';
    }
}

int main() {
    s3();
    return 0;
}
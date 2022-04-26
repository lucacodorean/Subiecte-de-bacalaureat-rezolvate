#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


void Cifra(int n, int &x) {

    x = 0;

    while(n>0) {
        int cifra = n%10;
        n/=10;

        if(cifra>x) {
            x = cifra;
        }
    }
}

void getSolution() {
    long long n;
    bool founded = true;

    cin>>n;

    int maxValue = 0;

    this->Cifra(n,maxValue);

    if(maxValue>4) founded = false;
    
    founded == true ? cout<<"Da" : cout<<"Nu";

}

void ex3() {
    
    int n;
    string number;
    ifstream fin("numere.in");

    fin>>n;

    for(int i=1; i<=n; i++) {
        short digit; fin>>digit;
        number += digit + '0';
    }

    fin.close();

    sort(number.begin(),number.end());

    
    for(int digit = 0; digit<number.size(); digit ++) {
        if(number[digit]>number[0]) {
            swap(number[digit], number[0]);
            break;
        }
    }

    cout<<number;
}


int main() {
    problem;
    //getSolution();
    ex3();

    return 0;
}

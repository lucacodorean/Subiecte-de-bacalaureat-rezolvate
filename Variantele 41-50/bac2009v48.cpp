#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b) {
    while(b) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

void s3() {
    int n, ired = 0;
    cin>>n;
    for(int i=1; i<=n; i++) {
        if(cmmdc(i,n)==1) ired++;
    }

    cout<<ired<<' ';
}

void s4() {
    ifstream fin("bac.in");

    int ap[10000] = {0}, size = 0, maxim = 0;
    fin>>size;
    for(int i=1, number; i<=size; i++) {
        fin>>number;
        ap[number]++;
        maxim = max(maxim, number);
    } fin.close();
    
    for(int number=0; number<=maxim; number++) {
        if(ap[number]==1) cout<<number<<' ';
    }
}

int main() {
    s4();
    return 0;
}
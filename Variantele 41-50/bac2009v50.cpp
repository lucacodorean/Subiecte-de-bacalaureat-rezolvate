#include <iostream>
#include <fstream>
using namespace std;


bool divxy(int x, int y) {
    return x%y==0 || y%x==0;
}

void s3() {
    int a, b, n;
    bool ok = false;
    cin>>a>>b>>n;

    if(a>b) swap(a,b);

    for(int number = a; number<=b; number++) {
        if(divxy(number,n)==true && number<=n) {
            cout<<number<<' ';
            ok = true;
        }
    }

    if(ok == false) cout<<"NU EXISTA";
}

void s4() {
    ifstream fin("bac.in");

    int size, maxim = 0;
    int ap[5001] = {0};

    fin>>size;
    for(int i=1; i<=size; i++) {
        int number;
        fin>>number;
        ap[number]++;
        maxim = max(maxim,number);
    } fin.close();

    for(int number=0; number<=maxim; number++) {
        if(ap[number]>=2) {
            cout<<number<<' ';
        }
    }
}

int main() {
    s4();
    return 0;
}
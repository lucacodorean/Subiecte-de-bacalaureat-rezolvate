#include <iostream>
#include <fstream>
using namespace std;

int getFirstDivisior(int n) {

    if(n%2!=0){
        for(int divisor = 3; divisor<=n; divisor+=2){
            if(n%divisor == 0) {
                return divisor;
            }
        }
    } 
    return n;
}

int getGroup(int a) {
    int p = a*a, cate = 1;
    while(p%10 != a%10) {
        p*=a;
        cate++;
    }

    return cate;
}

int ultimaCifra(int a, int b) {
    int divisor = getFirstDivisior(a);
    int index   = b%getGroup(divisor);

    cout<<divisor<<' '<<index<<endl;

    if(index!=0) {
        int p = 1;
        for(int i = 1; i<=index; i++) {
            p*=divisor;
        }
        return p%10;
    }
    else return divisor;
}


int main() {

    ifstream fin("sir.in");
    ofstream fout("sir.out");

    int n, s = 0;

    fin>>n;
    for(int i=1,x,y; i<=n; i++) {
        fin>>x>>y;
        s+=ultimaCifra(x,y);
    } fin.close();

    fout<<s%10;
    fout.close();
    return 0;
}
#include <iostream>
#include <fstream>

using namespace std;

int divisor(int a, int b, int c) {
    int cate=0;
    for(int number = 1; number<=min(a,min(b,c)); number++) {
        if(a%number == 0 && b%number == 0 && c%number==0) {
            cate++;
        }
    }

    return cate;
}

int main() {
    ifstream fin("data.dat");
    
    int x, y;
    fin>>x>>y;
    char* numar = new char[y];
    fin>>numar;
​
    int f1=(x<10 ? 1 : 2), f2=(x==9 ? 2 : f1), f3 = f1+f2;
    while (f3<y) {
        f1 = f2; f2=f3; f3= f1+f2;
    }
​
    numar[f2]=0;
    cout<<numar;
​
    delete numar;

    return 0;
}

/*
​
        maxim 18 pasi
​
        numar:  2   3   32      323     32332   32332323
        cifre:  1   1   2        3        5         8
​
        8 = 3 + 5
        5 = 2 + 3
        3 = 1 + 2
        2 = 1 + 1
​
    */
​
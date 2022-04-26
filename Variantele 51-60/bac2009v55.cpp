#include <iostream>
#include <fstream>

using namespace std;
#define LIMIT 100001

void cifre(int n, int &result) {
    result = 0;

    int ap[10] = {0};

    while(n) {
        int digit = n % 10;
        n/=10;

        if(ap[digit]==0) ap[digit] ++;
    }

    for(int digit=0; digit<=9; digit++) {
        if(ap[digit]==1) {
            result = result * 10 + digit;
        }
    }
}

void concatenate(int a, int b, int &result) {
    result = a;

    int reversed = 0;
    while(b) {
        int digit = b%10;
        b/=10;
        reversed = reversed * 10 + digit;
    }

    while(reversed) {
        int digit = reversed%10;
        reversed/=10;
        result = result * 10 + digit;
    }
}

void solveExercise3() {
    ifstream fin("numere.in");

    int size,v[LIMIT]; fin>>size;
    bool ok = false;

    for(int i=1; i<=size; i++) {
        fin>>v[i];
    } fin.close();

    for(int i=1; i<=size; i++) {
        int x = 0;
        cifre(v[i],x);
        if(x==v[i]) {
            ok = true;
            cout<<v[i]<<' ';
        }
    }

    if(ok == false) cout<<"0";

}

int main() {

    int result =  0;
    cifre(15231012, result);
    cout<<result;
    return 0;

    int size; cin>>size;

    int a[LIMIT], lungA = 1;
    int b[LIMIT], lungB = 1;
    int c[LIMIT];


    for(int i=1; i<=2 * size; i++) {
        int x; cin>>x;
        if(i<=size) a[lungA++] = x;
        else b[lungB++] = x;
    }
   
    for (int i=1; i<=size; i++) {
        int result = 0;
        a[i]<b[i] ? concatenate(a[i],b[i], result) : concatenate(b[i],a[i], result);
        c[i] = result;
    }

    for(int i=1; i<=size; i++) {
        cout<<c[i]<<' ';
    }
    return 0;
}
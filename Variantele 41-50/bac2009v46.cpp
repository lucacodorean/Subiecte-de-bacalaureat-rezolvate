#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void s3() {

    ifstream fin("A.txt");

    int array[101], size = 0, n, k, number;
    cin>>k;
    fin>>n;
    
    for(int i=1; i<=n; i++) {
        fin>>number;
        int cati = 0;
        for(int div = 2; div < number; div++){
            if(number%div==0) {
                cati++;
                
            }
        }

        if(cati>=k) cout<<number<<' ';
    } fin.close();

    
    for(int i=1; i<=size; i++) {
        cout<<array[i]<<' ';
    }
}

void cifre(int number, int &sc, int &nc) {
    sc = nc = 0;

    while(number!=0) {
        int digit = number%10;
        sc+=digit;
        nc++;
        number/=10;
    }
}

void s4() {
    int number; cin>>number;
    int aux = number, sum = 0, digitNumber = 0, digits[10] = {0};
    cifre(number, sum, digitNumber);

    bool ok = false;

    for(int i=0; i<digitNumber; digits[i]+= aux%10, aux/=10, i++);
   
    for(int i=0; i<digitNumber; i++) {
        if(digits[i] == (sum-digits[i])/(digitNumber-1)) {
            ok = true;
        }
    }

    ok == true ? cout<<"DA" : cout<<"NU";
}

int main() {
    s4();
    return 0;
}
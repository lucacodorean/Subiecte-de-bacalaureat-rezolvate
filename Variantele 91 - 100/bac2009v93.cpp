#include <iostream>
#include <cmath>
using namespace std;

void p3() {
    int number, size = 1;
    cin>>number;

    int pare = number, impare = 1, arr[100];

    //arr[size++] = impare++;
    for(int i=1; i<=number; i++) {
        (i%2==0) ? arr[size++] = pare-- : arr[size++]=impare++;
    }


    for(int i=1; i<=size-1; i++) cout<<arr[i]<<' ';
}

int prime(int value) {
    int ok = 1;
    for(int divisor = 2; divisor<value; divisor ++) {
        if(value%divisor == 0) {
           ok = 0;
           break;
        }
    }

    return ok;
}

int is_Solution(int value) {

    int p = 1;
    for(int divisor = 2; divisor<value; divisor++) {
        if(value%divisor == 0) {
            if(prime(divisor) == 1) {
                p*=divisor;
            }
        }
    }
    return p==value ? 1 : 0;
}


int dcm(int x, int y) {
    return (x%y == 0 ) ? y : dcm(y, x%y);
}

int main() {
    int a, b, found = 0;
    cin>>a>>b;
    
    int cel_mai_mare_divizor = dcm(a,b);
    
    if(is_Solution(cel_mai_mare_divizor) == 0) {
        while(found == 0) {
            cel_mai_mare_divizor--;
            if(is_Solution(cel_mai_mare_divizor) == 1 && a%cel_mai_mare_divizor==0 && b%cel_mai_mare_divizor==0) {
                found = 1;
                break;
            }
        }
    }
    
    cel_mai_mare_divizor != 1 ? cout<<cel_mai_mare_divizor : cout<<"nu exista";

    return 0;
}
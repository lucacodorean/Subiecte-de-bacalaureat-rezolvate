#include <iostream>
#include <fstream>
using namespace std;

#define CRESCATOR 1 
#define DESCRESCATOR 2
#define CONSTANT 0
#define RANDOM -1

int f(int arr[], int size) {
    
    int crescator,descrescator,constant,random = 0;
    
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if(arr[i]>arr[j]) {
                crescator++;
            } else {
                if(arr[i]<arr[j]) descrescator++;
                if(arr[i]==arr[j]) constant ++;
            }
        }
    }

    if(crescator == size) return CRESCATOR;
    if(descrescator == size) return DESCRESCATOR;
    if(constant == size) return CONSTANT;

    return RANDOM;
}

int main() {
    ifstream fin("bac.txt");

    int number,  p = 1; fin>>number;

    int last_digit, digit, to_be_added = 0, cif_min = 9;
    last_digit = number%10;
    number/=10;
    cif_min = min(cif_min, last_digit);
    while(number>0) {
        digit = number%10;
        
        if(last_digit>digit) {
            break;
        }

        to_be_added = digit*p + to_be_added;
        p*=10;

        cif_min = min(cif_min, digit);

        last_digit = digit;
        number/=10;
    } fin.close();

    to_be_added = to_be_added * 10 + (number%10);
    number/=10; p*=10;
    number = number*10 + cif_min;
    number = number*p + to_be_added;

    cout<<number;

    return 0;
}
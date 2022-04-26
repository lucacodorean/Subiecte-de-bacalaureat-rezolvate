#include <iostream>
#include <fstream>

using namespace std;

int equalDigits(int number) {
    
    int lastdigit = number%10;
    number/=10;
    while(number > 0) {
        int digit = number%10;
        number/=10;
        if (digit != lastdigit) return 0;
    }

    return 1;
}

void divi(int number, int &result) {
    
    result = 0;
    for(int divisor = 2; divisor<=number; divisor++) {
        if(number%divisor == 0) {
            result = divisor;
            break;
        }
    }
}

void solveExercise3() {

    ifstream fin("bac.txt");

    int number;
    while(!fin.eof()) {
        fin>>number;
        if(equalDigits(number)==1) cout<<number<<' ';
    } fin.close();
}

void solveExercise4() {
    int n; cin>>n;
    int divN, number = n-1, findDiv = 0;

    divi(n, divN);
    cout<<n/divN;
}

int main() {
    solveExercise4();
    return 0;
}
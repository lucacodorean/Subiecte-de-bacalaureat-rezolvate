#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int prob3 () {
    int size, cate = 0;
    cin>>size;
    double data[51];
    for(int i=1; i<=size; i++) {
        cin>>data[i];
    }

    double mediaAritmetica = 0, suma = 0;
    for(int i=1; i<=size; i++) {
        for(int j = 1; j<=size; j++) {
            suma += data[j];
        }
        suma -= data[i];
        mediaAritmetica = suma / (size-1);
        if(mediaAritmetica == data[i]) cate++;
        mediaAritmetica = 0;
        suma =  0;
    }

    cout<<cate;
    return 0;
}

int primul (int number) {
    /// sqrt 10000 = 100
    int result=1;
    for(int divisor=2; divisor<=number; divisor++){
        if(number%divisor == 0) {
            result = divisor;
            break;
        } 
    }
    return result;
}

int main(){

    ifstream fin("A.txt");

    int size, maxim = -1;
    fin>>size;

    for(int i=1; i<=size; i++) {

        int x;
        fin>>x;
        if(primul(x / primul(x)) == x / primul(x)) {
            maxim = max(maxim, x);
        }

    } fin.close();

    maxim != -1 ? cout<<"DA "<<maxim : cout<<"NU";

    return 0;
}
#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>

using namespace std;

int sum3 (int values[], int size) {
    int s = 0;

    for(int i=1; i<=size; i++) {
        if(values[i]%3==0) s+=values[i];
    }

    return 0;
}

void checkNumber(int x, int arr[]) {
       if(x<=999) {
            if(x>=values[1]) {
                values[0] = values[1];
                values[1] = a;
            } else values[0] = a;
        } else values[2] = min(values[2],x)
}

void display(int arr[]){
    fin.close();
    values[2] - values[1] <= values[1] - values[0] ? cout<<values[2]<<' '<<values[1] : cout<<values[1]<<' '<<values[0];
}

int main(){

/*
    Algoritmul citeste din fisier elementele si calculeaza maximl daca ele sunt in intervalul [100,999].
    Se calcuelaza valoarea maxima pe linie, pe care o adaugam in vectorul v.

    Se parcruge vectorul v si se verifica daca modului valorii maxime anterior gasite - elementul este minim si daca elementul este diferit de maxim,
    pentru a evita cazul in care se afiseaza valoarea 0. Se afiseaza valoarea maxima si rezultatul gasit in urma parcurgerii.

    Din punct de vedere al eficientei, algoritmul executa n*n pasi pentru parcurgerea tuturor numerelor, si o parcurgere aditionala pentru vector, 
    deci complexitatea este O().
*/

    ifstream fin("A.txt");

    int size, values[3] = {0, 0, INT_MAX};
    fin>>size; size = size*size;
    /*for(int i=1, x; i<=size; i++) {
        fin>>x;
        checkNumber(x,values);
    
    } fin.close();*/

    for(int i = 1, x; i<=size && fin>>number; checkNumber(number,values), i++); 
    display(values);

    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

#define LIMIT 10000

/// ex 3
void sortare(double arr[], int size) {
    for(int i=1; i<=size; i++) {
        for(int j=i+1; j<size; j++) {
            if(arr[i]<arr[j]) {
                swap(arr[i],arr[j]);
            }
        }
    }
}

///ex 4

int main() {

    /*
        Folosim un array boolean, ap, care ne va marca aparitia numarului citit intr-unul dintre fisiere.
        Se parcurg numerele de la 0 la 9999, iar in cazul in care ap[numar] are valoarea true, se afiseaza numarul.
    */

    ifstream fin;
    int number, size;
    bool ap[LIMIT] = {false};

    fin.open("A.txt");

    fin>>size;
    ///for(int i=1; i<=size; i++)
    while(!fin.eof()) {
        fin>>number;
        ap[number] = true;
    } fin.close();

    fin.open("B.txt");

    fin>>size;
    ///for(int i=1; i<=size; i++)
    while(!fin.eof()) {
        fin>>number;
        ap[number] = true;
    } fin.close();

    for(int number=0; number<=9999; number++) {
        if(ap[number]==true) cout<<number<<' ';
    }

    return 0;
}
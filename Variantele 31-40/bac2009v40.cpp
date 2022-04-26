#include <iostream>
#include <fstream>
#include <cmath>
#define MAX 1001
using namespace std;

ifstream fin("numere.txt");

void ex3() {
    int size;
    int arr[1001];
    bool okPare = false;
    bool okImpare = false;

    fin>>size;
    for(int i=1; i<=size; i++) {
        fin>>arr[i];
    } fin.close();

    for(int i=1; i<=size; i++) {
        if(arr[i]%2==0 && okPare == false) {
            for(int j=i+1; j<=size; j++) {
                if(arr[j]%2==0) {
                    if(arr[i]<=arr[j]) okPare = true;
                    else okPare = false; 
                }
            }
        }
        if(arr[i]%2!=0 && okImpare == false) {
            for(int j=+1; j<=size; j++) {
                if(arr[j]%2!=0) {
                    if(arr[i]>=arr[j]) {
                        okImpare = true;
                    } else okImpare = false;
                }
            }
        }
        if(okPare == true && okImpare == true) break; 
    }

    if(okImpare == true && okPare == true) cout<<"DA";
    else cout<<"NU";
}

int sdiv(int value)
{
    int s = 0;
    int rad = sqrt(value);
    for (int div = 1; div <= value; div++) {
        if (value % div == 0)
            s = s + div;
    }

    if (rad * rad == value) s -= rad;

    return s;
}

void printSolution()
{
    bool prime = false;
    int number; cin>>number
    int value = sdiv(number);

    for (int div = 1; div <= value; div++) {
        if (value % div == 0) {
            prime = false;
            break;
        }
        else
            prime = true;
    }

    prime ? cout << "Da" : cout << "NU";
}

int main() {

    printSolution();

    return 0;
}
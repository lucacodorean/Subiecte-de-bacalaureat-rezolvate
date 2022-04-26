#include <iostream>
#include <fstream>
 
using namespace std;


bool mult(int size, int arr[]) {
 
    for(int i=0; i<size; i++) {
        for(int j=0; j<size && i!=j; j++) {
            if(arr[i]==arr[j]) {
                return false;
            }
        }
    }
 
    return true;
}
 
int main() {

    ifstream fin("numere.txt");

    int arr[501], l = 0, k=0;
    while(!fin.eof()) {
        fin>>arr[l++];
    } fin.close();

    for(int position = 0; position<l; position++) {
        if(mult(position,arr)==true) {
            k++;
        } else break;
    }
 
    cout<<k-1;
 
    return 0;
}
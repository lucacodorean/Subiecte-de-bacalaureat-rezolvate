#include <iostream>
#include <fstream>
using namespace std;

#define LIMIT 10000

///ex 3

void nule (int arr[], int size) {

    int zeros = 0;

    for(int i=0; i<size; i++) {
        if(arr[i]==0) {
            zeros++;
            for(int j=i; j<size-1; j++) {
                arr[j] = arr[j+1];
            }
            size--;
        }
    }

    while(zeros>0) {
        arr[size++] = 0;
        zeros--;
    }

}

void solveExercices3() {
    int array[12] = {1,2,0,3,4,5,0,7,8,-1,10};
    int size = 11;

    nule(array,size);
    for(int i=0; i<size; i++) cout<<array[i]<<' ';
}



int main() {

    int size, ap[LIMIT] = {0}, number;

    ifstream fin;

    fin.open("A.txt");

    fin>>size;
    while(!fin.eof()){
        fin>>number;
        ap[number]++;
    } fin.close();

    fin.open("B.txt");

    fin>>size;
    while(!fin.eof()){
        fin>>number;
        ap[number]++;

        if(ap[number]==2) cout<<number<<' ';
    } fin.close();

    return 0;
}
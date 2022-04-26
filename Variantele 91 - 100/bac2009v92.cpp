#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


void sortare(float arr[], int size) {
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if(arr[i]>arr[j]) swap(arr[i],arr[j]);
        }
    }

    /*
        float numbers[100]; int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++) cin>>numbers[i];
        sortare(numbers,n);
        for(int i=n-1; i>=m; i--) cout<<numbers[i]<<' ';
    */
}

int main() {
    ofstream fout("SIR.TXT");
    for(char first_letter = 65; first_letter<=90; first_letter++) {
        for(char last_letter = 66; last_letter<=90; last_letter++) {
            if(strchr("AEIOU", last_letter)==0 || strchr("AEIOU", first_letter)==0) {
                fout<<first_letter<<last_letter<<'\n';
            }
        }
    } fout.close();
    return 0;
}

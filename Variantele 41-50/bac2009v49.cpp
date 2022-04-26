#include <fstream>
#define MAX_VAL 30000
#define MAX 1005
using namespace std;
 
ifstream cin("numere.txt");
ofstream cout("numere.out");
 
void p3(int arr[], int sizeofV) {

    for(int i=0; i<sizeofV; i++) {
        cin>>arr[i];
    } cin.close();
 
    for(int i=0; i<sizeofV; i++) {
        for(int j=i; j<sizeofV; j++) {
            if(arr[i]<arr[j]) {
                swap(arr[i],arr[j]);
            }
        }
    }
 
    bool possible = true;
    for(int i=1; i<sizeofV; i++) {
        if(arr[i]-arr[i-1]!=i) {
            possible = false;
            break;
        }
    }
 
    possible == true ? cout<<"DA" : cout<<"NU";
    cout.close();
 
}
 
void cmax(int a, int &b);
bool digitCheck(int number, int digit);
 
int main(){
    int size=0, arr[MAX];
    int cifraMax = 0;
    int minVal = MAX_VAL;
    while(!cin.eof()){
        int x;
        cin>>x;
        cmax(x,cifraMax);
        arr[++size]=x;
    }
 
    for(int i=1; i<=size; i++) {
        if(digitCheck(arr[i],cifraMax)) minVal = min(minVal, arr[i]);
    }
 
    cout<<cifraMax<<" "<<minVal;
 
    return 0;
}
 
void cmax(int a, int &b) {
    while(a>0) {
        int cifra = a%10;
        a/=10;
        b = max(b, cifra);
    }
}
 
bool digitCheck(int number, int digit) {
    bool solution = false;
    while(number>0) {
        int auxiliary = number%10;
        number/=10;
        if(auxiliary == digit) {
            solution = true;
            break;
        }
    }
 
    return solution;
}
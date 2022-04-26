#include <iostream>
#include <fstream>
using namespace std; 

/* problema 3.
int main() {
    int size, k;
    cin>>n>>k;
    for(int i=n*k ; i>0; i-=n) {
        int multiplu = i / k;
        if(multiplu) cout<<i<<' ';
        k--;
    }
    return 0;
}*/


void sterge(int arr[], int &size, int i, int j) {
    for (int position = size; position >= 1 ; position --){
        if(position>=i && position<=j) {
            for(int k = position; k <= size - 1; k ++) {
               arr[k] = arr[k+1];
            }
            size --;
        }
    }
}

int main() {

    ifstream fin("A.txt");

    int size, data[101];
    fin>>size;
    for(int i=1; i<=size; i++) {
        fin>>data[i];
    } fin.close();

    int start, stop;
    for(int i=size; i>=2; i--) {
       if(data[i]==data[i-1]) {
           start = i;
           stop = i;
           while(data[start] == data[stop]) {
               start--;
           }
           sterge(data,size,start+2,stop);
        }
    }

    for(int i=1; i<=size; i++){
        cout<<data[i]<<' ';
    }
    return 0;
}

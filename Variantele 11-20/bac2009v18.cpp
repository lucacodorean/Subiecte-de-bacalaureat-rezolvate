#include <iostream>
#include <fstream>
using  namespace std;

///S3
int count(double arr[], int size) {
    int result = 0;
    double ma = 0, sum = 0;
    for(int i=1; i<=size; i++){
        sum+=arr[i];
    }
    ma = sum/size;

    for(int i=1; i<=size; i++) {
        if(arr[i] >= ma) result += 1;
    }

    return result;

    /*
        int n;
        double a[101];
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>a[i];
        }
        cout<<count(a,n);
        return 0;
    */
}

int cautare(int arr[], int size, int ec) {
    int st=size, dr=1, mijloc=0;
    while (st>=dr){
        mijloc=(st+dr)/2;
        if (ec==arr[mijloc]) return mijloc;
        if (ec>arr[mijloc]) st = mijloc - 1;
        else if (ec<arr[mijloc]) dr = mijloc + 1;
    }
    return -1;
}

void sort(int arr[], int size) {
    for(int i=1; i<=size; i++){
        for(int j=i+1; j<=size; j++) {
            if(arr[i]<arr[j]) {
                swap(arr[i],arr[j]);
            }
        }
    }
}

int main() {
    ///cautare binara pe array sortat descrescator

    ifstream fin("A.txt");

    int data[10001] = {0}, size = 0, position, number;
    cin>>position;

    while(fin>>number){
        data[++size]=number;
    } fin.close();

    sort(data,size);

    int result = cautare(data,size,position);
    if(result == -1 ) cout<<"NU EXISTA";
    else cout<<result;
    return 0;
}
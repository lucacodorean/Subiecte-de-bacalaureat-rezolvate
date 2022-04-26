#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("A.txt");

/// ex3
int interval(int arr[], int size){
    int cate = 0;
    int cap1 = min(arr[1],arr[size]);
    int cap2 = max(arr[1],arr[size]);
    for(int i=1; i<=size; i++){
        if(arr[i]<=cap2 && arr[i]>=cap1) {
            cate+=1;
        }
    }
    return cate;

    /*
        int main() {
        int n,a[101];
        cin>>n;
        for(int i=1; i<=n; i++) {
            cin>>a[i];
        }
        cout<<interval(a,n);
        return 0;
    }*/
}

int cautare(int arr[], int ec, int size)
{
    int st=1,dr=size;
    int mijloc=0;
    while (st<=dr){
        mijloc=(st+dr)/2;
        if (ec==arr[mijloc]) return mijloc;
        if (ec>=arr[mijloc]) st=mijloc+1;
        else if (ec<arr[mijloc]) dr=mijloc-1;
    }
    return -1;
}

void sort(int arr[], int size) {
    for(int i=1; i<=size; i++){
        for(int j=i+1; j<=size; j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

int main() {
    /*
        Algoritmul se bazeaza pe problema cautarii binare. Se citesc
        elementele vectorului dupa care se salveaza intr-o variabila elementul
        de cautat. Array-ul in care cautam trebuie sa fie sortat dupa selectearea
        elementului. Se apeleaza functia de cautare binara, care returneaza pozitia
        elementului in array, dupa sortare.
    */
    int size, data[10001];
    fin>>size;
    for(int i=1; i<=size; i++) {
        fin>>data[i];
    }
    
    int find = data[1];

    sort(data,size);

    cout<<cautare(data,find,size);

    return 0;
}
#include <iostream>
#include <fstream>
#include <bitset>
#include <cstring>
#include <cmath>
using namespace std;

ifstream fin("produse.txt");

void ex5(){
    int n,k;
    cin>>n>>k;
    int aux = n*k;
    int v[aux], l=0;
    int i = 0 ;
    while(l<=n*k){
        int d = sqrt(i);
        if(d*d==i && i%2==0){
            v[++l]=d*d;
        }
        i++;
    }

    for(int i = 1; i<=aux; i++){
        cout<<v[i]<<' ';
        if(i%k==0) {
            cout<<endl;
        }
    }
}

void sub(int n, int &a, int &b){
    int aux=0, v[2],l=0;
    for(int i=n; i>1 && l<2; i--){
        for(int d=2; d<=i/2; d++){
            if(i%d==0)
            {
                aux++;
            }
        }
        if(aux==0){
            v[l]=i;
            l++;
        }
        else aux=0;
    }
    a=v[0];
    b=v[1];
}

int a[200001][3], n;
pair<int, int>sume[200001];

int main(){
    fin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=3; j++){
            fin>>a[i][j];
        }
    }
    int aux = n; 
    for(int i=1; i<=n; i++){
        sume[a[i][1]].first = a[i][1];
        sume[a[i][1]].second+=(a[i][2]*a[i][3]);
        for(int j=i; j<=n; j++){
            if(sume[a[i][1]].first==j){
                aux--;
            }
        }
    }

    for(int i=1; i<=aux; i++){
        cout<<sume[i].first<<" "<<sume[i].second<<endl;
    }
    return 0;
}
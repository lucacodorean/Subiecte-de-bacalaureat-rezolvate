#include <iostream>
#include <fstream>
#include <bitset>
#include <cstring>
using namespace std;

ifstream fin("bac.txt");

void function(){
    bitset<1000001>viz;
    int x, gasit=0;
    while(fin>>x){
        fin>>x;
        viz[x]=1;
    }

    for(int i = 999; i>99 && gasit<2; i--){
        if(viz[i]==0){
            cout<<i<<' ';
            gasit++;
        }
    }
    
    fin.close();
}

void sub(int n, int k){
    int aux=n, i = 1, v[51], l = 0;
    while(aux>0){
        if(i%k==0){
            v[++l]=i;
            aux--;
        }
        i++;
    }

    for(int i=l; i>=1; i--){
        cout<<v[i]<<' ';
    }
}

void ex5(int n, int a[25][25]){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        cout<<a[1][i]<<" ";
    }
    for(int i=2; i<=n; i++){
        cout<<a[i][n]<<' ';
    }
    for(int i=n-1; i>=1; i--){
        cout<<a[n][i]<<" ";
    }
    for(int i=n-1; i>=2; i--){
        cout<<a[i][1]<<' ';
    }
}

int main(){
    int a[25][25];
    ex5(4,a);
    return 0;
}
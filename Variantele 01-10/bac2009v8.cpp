#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream fin("bac.txt");

void ex3(){
    int v[51],n,s=0,rez[51],l=0;
    fin>>n;
    for(int i=1; i<=n; i++){
        fin>>v[i];
    }

    for(int i=1; i<=n; i++){
        int d = sqrt(v[i]);
        if(d*d==v[i]){
            s+=v[i];
            rez[++l]=v[i];
        }
    }

    for(int i=1; i<l; i++){
       cout<<rez[i];
       if(i!=l-1)
       {
           cout<<'+';
       }
    }
    cout<<'='<<s;
}

void function(int n, int m, int a[], int b[]){
    int c[202],l=0;
    int i=1, j=1;
    
    for(int i=1; i<=n; i++){
        c[++l]=a[i];
    }
    for(int i=1; i<=m; i++){
        c[++l]=b[i];
    }

    sort(c+1,c+l+1);

    for(int i=1; i<=l; i++){
       if(c[i]%2==0 && c[i+1]%2==0 && i!=l){
           for(int j=i+1; j<=l; j++){
             c[j]=c[j+1];
           }
           l--;
       }
    }

    for(int i=1; i<=l; i++){
        cout<<c[i]<<' ';
    }
}

int main(){
    int n, m, l=0;
    fin>>n>>m;
    int a[101], b[101], c[202];
    for(int i=1; i<=n; i++){
        fin>>a[i];
    }
    for(int i=1; i<=m; i++){
        fin>>b[i];
    }
    function(n,m,a,b);
    return 0;
}
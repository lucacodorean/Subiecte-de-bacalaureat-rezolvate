#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
int f(int a);

int main(){
    int n,v[101];
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>v[i];
    }
    for(int i=1; i<=n; i++){
        if(f(v[i])==v[i]){
            for(int j=i+1; j<=n; j++){
                if(v[i]>v[j]){
                    swap(v[i],v[j]);
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(f(v[i])==v[i]){
            cout<<v[i]<<' ';
        }
    }
    return 0;
}

/// cel mai mic divizor prim 
int f(int a){
    int minim=INT_MAX, sol=2;
    for(int d=2; d<=a; d++){
            if(a%d==0){
                minim=min(minim, d);
                if(minim==2){
                    return minim;
                }
                else {
                    for(int i=3; i<=sqrt(a); i+=2){
                        if(minim%i!=0){
                            sol=minim;
                        }
                    } 
                }
            }
        }
    return sol;
}
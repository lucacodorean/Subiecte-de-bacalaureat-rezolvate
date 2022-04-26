#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;
ifstream fin("nr.txt");

void f(int n, int x){
    if(x>n){
        cout<<0;
    }
    else {
        if(x%4<=1){
            f(n,x+1);
        }
        else{
            f(n,x+3);
            cout<<1;
        }
    }
}

void solves2e3(int n){
    int a[25][25];
    int aux=n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            a[i][j]=aux;
            if(i+j==n+1){
                a[i][j]=0;
            }
        }
            aux--;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
}

void solvees3e3(){
    int v[101], n=0,x;
    while(fin>>x)
    {
        v[++n]=x;
    }
  
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(v[i]<v[j]){
                swap(v[i],v[j]);
            }
        }
    }
    int cate=0;
    for(int i=1; i<=n; i++){
        if (v[i]<100) {
            cate++;
            cout<<v[i]<<' ';
        }
    }
    if(cate==0){
        cout<<"NU EXISTA";
    }

}

int cf(int a, int b){
    
    int aux=a,cate=0;
    int cifra=0;
    while(aux>0){
        cifra=aux%10;
        if(cifra==b){
            cate++;
        }
        aux/=10;
    }
    return cate;
}

int ap[9],v[4];
int main(){
    int cifra=0,n,l=0;
    int ok=true;
    cin>>n;
    int cate=8,aux=n;
    while(cate>0){
        ap[l]=cf(aux, l);
        cate--;
        l++;
    }
    int l2=0;

    for(int i=1; i<=l; i++){
        if(ap[i]==1 || ap[i]%2!=0){
            ok=false;
        }
        while(ap[i]>0){
            if(ap[i]>=2 && ap[i]%2==0){
                v[++l2]=i;
            }
            ap[i]--;
        }
    }
   
    if(ok==false){
        cout<<"NU EXISTA";
    }
    else{
        for(int i=1; i<=l2; i++){
            for(int j=i+1; j<=l2; j++){
                if(v[i]>v[j]){
                    int a=v[i];
                    v[i]=v[j];
                    v[j]=a;
                }
            }
        }

        for(int i=1; i<=l2; i++){
            cout<<v[i];
        }
        for(int i=1; i<=l2; i++){
            for(int j=i+1; j<=l2; j++){
                if(v[i]<v[j]){
                    int a=v[i];
                    v[i]=v[j];
                    v[j]=a;
                }
            }
        }

        for(int i=1; i<=l2; i++){
            cout<<v[i];
        }
    }
    return 0;
}
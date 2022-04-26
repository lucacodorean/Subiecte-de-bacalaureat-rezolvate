#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("nr.txt");
/*int a[25][25];

void f(int x){
    if(x>0){
        if(x%4==0){
            cout<<x;
            f(x-1);
        }
        else{
            f(x/3);
            cout<<'y';
        }
    }
}


int main(){

    int n;
    cin>>n;
    f(26);
    int aux=n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            a[j][i]=aux;
        }
        aux--;
    }
    for(int i=1; i<=n; i++){
        a[i][i]=0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
int l=0, cate=0, v[101];
int main(){
    while(fin){
        fin>>v[++l];
    }
    cout<<l<<" ";
    for(int i=1; i<l; i++){
        for(int j=i+1; j<l; j++){
            if(v[i]>v[j]){
                int aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
    for(int i=1; i<l; i++){

            cate++;
            cout<<v[i]<<" ";

    }
    if(cate==0){
        cout<<"NU EXISTA";
    }
    return 0;
}*/

int cif(int a, int b){
    int aux=a, cate=0;
    int cifra=0;
    while(aux>0){
        cifra=aux%10;
        aux/=10;
        if(cifra==b){
            cate++;
        }
    }
    return cate;
}

int ap[9],v[4];

int main(){
    int n;
    bool ok=true;
    cin>>n;
    int aux2=n, aux=n, l=0, cate=8;
    while(cate>0){
        ap[l]=cif(aux, l);
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
    cout<<l2<<endl;
    for(int i=1; i<=l2; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    if(ok==true){
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
    }
    else cout<<0;
    return 0;
}

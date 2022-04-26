#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

ofstream outf("bac.txt");

void sterge_cons(){
    char text[256], separator[]=" ", aux[256];
    cin.get(text, 256);
    int n = strlen(text)-1,gata=0;
    for(int i=n; i>0 && gata==0; i--){
        if(strchr("aeiou", text[i])==0){
                strcpy(aux, text+i+1);
                strcpy(text+i, aux);
                gata++;
        }
    }
    if(gata!=0){
        cout<<text;
    }
    else cout<<"TEXTUL NU CONTINE CONSOANE";
}

void interschimbare(){
    int v[301], n, gata1=0, gata3=0, primazona=0, uzona=0;
    cin>>n;
    for(int i=1; i<=3*n; i++){
        cin>>v[i];
    }
    for(int i=1; i<=n && gata1==0; i++){
        if(v[i]%2==0){
           primazona=i; 
           gata1=1;
        }
    }
    for(int i=3*n; i>2*n && gata3==0; i--){
        if(v[i]%2!=0){
           uzona=i; 
           gata3=1;
        }
    }
    if(gata1==1 && gata3==1){
        swap(v[primazona],v[uzona]);
    }
    for(int i=1; i<=3*n; i++){
        outf<<v[i]<<' ';
    }
}

long long gensir(long long n){
    if (n<=5){
        return n;
    }
    else return 2*gensir(n-1);
}

int pcta(int n){
    int v[50], l=0;
    for(int i=1; i<=n && gensir(i)<=n; i++){
        v[++l]=gensir(i);
    }
    return v[l];
}

void pctb(long long n){
    while(n>0){
        cout<<pcta(n)<<' ';
        n-=pcta(n);
    }
}

int main(){
    int n;
    cin>>n;
    pctb(n);
    return 0;
}



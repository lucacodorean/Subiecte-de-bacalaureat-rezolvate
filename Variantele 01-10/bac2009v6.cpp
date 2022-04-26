#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

ifstream fin("bac.txt");

int f(int a, int b){
    if(b<1) return -1;
    else{
        if(a%b==0){
            return 1+ f(a/b,b);
        }
        else return 0;
    }
}

void turn_to_upper(){
    char c[255];
    cin.get(c, 255);
    int size = strlen(c);
    c[0]=toupper(c[0]);
    for(int i=0; i<size-1; i++){
        if(c[i-1]==' '){
            c[i]=toupper(c[i]);
        }
    }
    cout<<c;
}

void suma(int v[101], int n){
    int s = 0;
    if(n>1){
        for(int i=1; i<=n; i++){
            s+=v[i];
        }
        cout<<s<<endl;
        suma(v,n-1);
    }
    else cout<<v[1];
}

int main(){
   /*int x, l=0;
   while(!fin.eof()){
        fin>>x;
        v[x]+=1;
       
    }
    l=x;
    for(int i=1; i<=l; i++){
        if(v[i]!=0){
            cout<<i<<' '<<v[i]<<' ';
        }
    }
    return 0;*/

    int x, x_ant, cate=0;
    fin>>x_ant;
    cate=1;
    while(!fin.eof()){
        fin>>x;
        if(x_ant==x){
            cate++;
        } else {
            cout<<x_ant<<" "<<cate<<' ';
            cate = 1;
        }
        x_ant=x;
    }

    cout<<x_ant<<" "<<cate;
}
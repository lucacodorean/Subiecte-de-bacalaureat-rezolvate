#include <iostream>
#include <cstring>
using namespace std;
/**int a[100][100];
int main(){
    int x,y,s=0,s2=0;
    cin>>x>>y;
    ///cout<<((x%y==0) && (y%x==0) && (x*y>0));

    for(int i=0; i<=y-1; i++){
        for(int j=0; j<=y-1; j++){
            cin>>a[i][j];
        }
    }
    int k;
    cin>>k;
    for(int j=0; j<y/2; j++){
        if(a[k][j]>0){
            s+=a[k][j]%10;
            s2+=a[k][j];
        }
    }
    cout<<s<<" "<<s2%10;
}

1 2 3 4 5
6 7 8 9 0
1 2 3 4 5
6 7 8 9 0
1 2 3 4 5

char s[100],aux[100],c[1],t[1];
int main(){
    cin>>s;
    int l =strlen(s);
    for(int i=0; i<l; i++){
        if(strchr("aeiou", s[i])){
            c[0] = char(toupper(s[i]));
            strcpy(aux,s+i+1);
            strcpy(s+i+1, c);
            strcpy(s+i+2, aux);
            l++;
        }
    }
    cout<<s;
    return 0;
}

void f(long n){
    cout<<n%10;
    if(n!=0){
        f(n/100);
        cout<<n%10;
    }
}

int main(){
    f(12345);
}*/

#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("nr.txt");
int v[101];

int main(){
    int n,l=1,aux;
    while(fin){
        fin>>v[l];
        l+=1;
    }
    for(int i=1; i<=l; i++){
        for(int j=i+1; j<=l; j++){
            if(v[i]>v[j]){
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
    int cate=0;
    for(int i=1; i<=l; i++){
        if(v[i]>0){
            cout<<v[i]<<' ',cate++;
        }
    }
    if(cate==0){
        cout<<"NU EXISTA";
    }
    return 0;
}

/*#include <iostream>
#include <algorithm>
using namespace std;

int f(int n){
    int d=2,p,s=0;
    while(n>1){
        p=0;
        while(n%d==0){
            p++;
            n/=d;
        }
        if(p){
            s+=p;
        }
        d++;
        if(n>1 && d*d>n){
            d=n;
        }
        p=0;
    }
    return s;
}

int a[101],n,s[100], l=0,l2=0, rez[101], ap[101],ap2[101];

bool corect(int k){

    for(int i=1; i<=k-1; i++){
        if(s[i]==s[k] && ap[s[k]]==ap[s[i]]){
            return false;
        }
    }
    return true;
}

void scrie(int k){
    for(int j=1; j<=k; j++){
        cout<<s[j]<<" ";
    }
    cout<<endl;
}

void scrierez(){

    for(int i=1; i<=l2; i++){
        cout<<rez[i]<<endl;
    }
}

bool cond(int a, int b){
return a<b;
}

void backtr(int k){
    for(int i=1; i<=l; i++){
        s[k]=a[i];
        ///if(corect(k)==true){
            if(l==k){
                    if((s[k]==s[k-1] && s[k-1]==s[k-2])){
                            return;
                    }
                    else rez[++l2]=s[k]*100+s[k-1]*10+s[k-2];
            }
            else {
                    backtr(k+1);
            }
       //}
    }
}

int main(){
    cin>>n;
    int aux=n;
    while(aux!=0){
        a[++l]=aux%10;
        aux/=10;
        ap[a[l]]++;
    }

    sort(a+1,a+l+1, cond);
    backtr(1);
    scrierez();
    /*
        VARIANTA OKISH
    if(n>=100){
        int v1,v2,v3,v4,v5;
        v1 = a[1]*100+a[3]*10+a[2];
        v2 = a[2]*100+a[1]*10+a[3];
        v3 = a[2]*100+a[3]*10+a[1];
        v4 = a[3]*100+a[1]*10+a[2];
        v5 = a[3]*100+a[2]*10+a[1];
        if(f(v1)==1 && f(v2)==1 && f(v3)==1 && f(v4)==1 && f(v5)==1 && f(n)==1){
            cout<<"DA";
        }
        else{
            cout<<"NU";
        }
    }
    else if (n>=2 && n<100){
        a[1]=n%10;
        a[2]=n/10;
        int v1=a[1]*10+a[2];
        int v2=a[2]*10+a[1];
        cout<<v1<<" "<<v2;
        if(f(v1)==1 && f(v2)==1 && f(n)==1){
            cout<<"DA";
        }
        else cout<<"NU";
    }
    if(f(n)!=1)
    {
        cout<<"NU";
    }
    return 0;
}*/

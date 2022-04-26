/**#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("bac.txt");
int v[1001];

int main()
{
    int n, cate=0, l=1;
    cin>>n;
    while(fin){
        fin>>v[l];
        ///cout<<l<<' '<<v[l]<<endl;
        l++;
    }
    cout<<l-1<<endl;
    for(int i=1; i<l-1; i++){
        if(v[i]%n==0){
            cout<<v[i]<<' ';
            cate+=1;
        }
    }
    if(cate==0){
        cout<<"NU EXISTA";
        fin.close();
        return 0;
    }
    fin.close();
    return 0;
}
*/

#include <iostream>
using namespace std;
int v[101], r[101], l=0;
int sub(int v[], int n, int a)
{
    int cate=0;
    for(int i=1; i<=n; i++)
    {
        if(v[i]<a)
        {
            cate+=1;
        }
    }
    return cate;
}

int main()
{
    int n,rez=0;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>v[i];
    }
    for(int i=1; i<=n; i++){
        r[++l]=sub(v,n,v[i]);
    }
    for(int i=1; i<=l; i++){
      for(int j=i+1; j<=l; j++){
        if(r[i]==r[j]){
            rez+=1;
        }
      }
    }
    if(rez!=0){
        cout<<"NU";
    }
    else cout<<"DA";
    return 0;
}

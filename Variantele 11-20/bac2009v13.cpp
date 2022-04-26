#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

ifstream fin("BAC.out");
ofstream fout("BAC.out");

/*problema 3
int main(){

	Algoritmul determina numarul de grupe peste care sare bazandu-se pe Suma Gauss.

	  Daca numarul de grupe complete este egal cu 2*k, atunci inseamna ca elementul
	  pe care-l cautam este pe capatul unei grupe, deci este egal cu 1. In caz contrar,
	  se scade din pozitie numarul de pozitii (s gauss a grupelor peste care
	  se sare) cu scopul de a ajunge la grupa care in care se afla elementul. Rezultatul
	  este numarul de grupe complete + 2 (+2 pentru a trece in urmatoarea grupa in raport cu 
	  pozitiile), din care se scade pozitia care ne intereseaza.
	

	long long position,answer; cin>>position;
    
    long long groupsNo = (-1+sqrt(1+(8*position)))/2;
    
    if(g*(g+1) == 2*position) cout<<1;
    else{
        position-=(groupsNo*(groupsNo+1))/2;
        answer = groupsNo + 2 - position;
        cout<<answer;
    }

    return 0;
}*/


///PROBLEMA 4
void P (int &number, int tobeDeleted) {

    int p = 1, result = 0;
    while(number>0){
        int cifra = number%10;
        if(cifra!=tobeDeleted){
   		    result= (cifra*p) + result;
			p*=10;
		}
        number/=10;
    }

	number = result;
}

int main(){
	
	ifstream fin("A.txt");


	int number;
	while(!fin.eof()) {
		fin>>number;
		for(int i=1; i<=9; i+=2) {
			P(number,i);
		}

		if(number!=0) cout<<number<<' ';
	} fin.close();

    return 0;
}
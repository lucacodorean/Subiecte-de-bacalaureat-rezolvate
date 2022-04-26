#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;



int catecif(int n) {
	int cate=0, aux=n;
	while(aux>0) {
		cate++;
		aux/=10;
	}
	return cate;
}

void s2ex5() {
	int n,a[9][9];
	cin>>n;
	int lung=catecif(n);
	for(int i=1; i<=lung; i++) {
		for(int j=1; j<=lung; j++) {
			a[j][i]=n%10;
		}
		n/=10;
	}

	for(int i=1; i<=lung; i++) {
		for(int j=1; j<=lung; j++) {
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
}

void ex3() {

	/*
	ALGORITMUL FOLOSESTE UN VECTOR DE APARITII. PENTRU FIECARE
	ELEMENT CITIT, SE VA CRESTE NUMARUL DE APARITII. SE
	PARCURGE VECTORUL DE APARITII, CAT TIMP NR DE APARITII
	ESTE DIFERIT DE 0. SE AFISEAZA POZITIA PARCURSA.
	*/

	int ap[501] = {0};
	int size,data;
	cin>>size;
	for(int i=1; i<=size; i++) {
		cin>>data;
		ap[data]++;
	}
	for(int i=0; i<=size; i++) {
		while(ap[i]>0) {
			cout<<i<<' ';
			ap[i]--;
		}
	}
}

int scif(int number) {
	 int sum = 0;
	 while(number>0) {

		 sum+=number%10;
		 number/=10;
	 }

	 return sum%2;
}

void ex4() {

	ifstream fin("A.txt");

	int number,cate=0,rez=0;

	while(!fin.eof()) {
		fin>>number;
		cate = (cate+1)%5;
		cout<<number<<' '<<"\n"[cate!=0];
	
		rez+=scif(number);
	} fin.close(); 

	cout<<"\n"[rez==0]<<rez;
}

int main(){
	ex4();
	return 0;
}
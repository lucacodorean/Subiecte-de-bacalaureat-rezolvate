#include <iostream>
#include <fstream>
#include <climits>
#include <cstring>
using namespace std;


///PROBLEMA 3
ifstream fin("test.txt");

/*int main(){
	int size, number;


	Metoda citeste numarul de numere din fisier dupa care 
	primul numar de pe linia a doua, numar pe care-l foloseste 
	pentru a initializa variabila maxim. 

	Se citesc restul numerelor dupa care se compara cu maximul,
	pe care-l afisam.


	fin>>size>>number; 

	int maxim = number;
	cout<<maxim<<' ';
	while(!fin.eof()) {
		fin>>number;
		maxim = max(maxim, number);
		cout<<maxim<<' ';
	} fin.close();
	return 0;
}

PROBLEMA 4	*/

struct vector{
	int numar;
	long long suma;
};

long long sum(long long number){
	int sum=0;
	for(int divisors=1; divisors<=n; divisors++){
		if(number%divisors==0){
			sum+=divisors;
		}
	}
	
	return sum;
}

int main(){
	int size, cate=0;
	vector data[26];
	cin>>size;
	for(int i=1; i<=size; i++){
		cin>>data[i].numar;
		data[i].suma=sdiv(data[i].numar);	
		
		if(data[i].suma==data[i].numar+1){
			cate++;
		}
	}
	cout<<cate;
	return 0;
}
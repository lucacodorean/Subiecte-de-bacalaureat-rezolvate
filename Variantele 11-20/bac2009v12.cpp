#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

///PROBLEMA 3

	/*
		Programul memoreaza intr-un vector de aparitii 
		numarul de aparitii ale unui multiplu de 5 intalnit in fisiere.

		Se parcurge vectorul de aparitii de la 5 la maxim, din 5 in 5,
		dupa care se afiseaza numerele pentru care ap[numar] = 1;

	*/


/*int main(){
	int ap[202] = {0}, number;

	ifstream fin;

	fin.open("A.txt");
	while(!fin.eof()) {
		fin>>number;
		if(number%5==0) ap[number]+=1;
	} fin.close();

	int maxim = number;

	fin.open("B.txt");
	while(!fin.eof()) {
		fin>>number;
		if(number%5==0) ap[number]+=1; 
	} fin.close();

	maxim = max(maxim, number);

	for(int number=5; number<=maxim; number+=5){
		if(ap[number]==1) cout<<number<<' ';
	}

	return 0;
}*/

bool equalDigits(int number) {
	bool ok = true;

	int prevDigit = number % 10;
	number/=10;

	while(number > 0) {
		int digit = number % 10;
		if(digit != prevDigit) {
			ok = false;
			break;
		}

		number/=10;
		prevDigit = digit;
	}

	return ok;
}

bool compare(int a, int b) {
	return a<b;
}

void sort(int arr[], int size) {
	for(int i=1; i<=size; i++){
		for(int j=i+1; j<=size; j++){
			if(compare(arr[i],arr[j])==false){
				swap(arr[i],arr[j]);
			}
		}
	}
}

void readData(int arr[], int &size) {

	int readSize;

	cin>>readSize;
	for(int i=1; i<=readSize; i++){
		cin>>arr[i];	
	}

	size = readSize;
}

void solve(int arr[], int size) {
	for(int i=1; i<=size; i++){
		if(equalDigits(arr[i])==true){
			cout<<arr[i]<<' ';
		}
	}
}

int main(){
	int size=0, data[21];

	readData(data, size);
	sort(data,size);
	solve(data, size);

	return 0;
}
#include <iostream>
#include <fstream>
#include <cmath>
#include <map>
#include <string>
#include <cstring>

using namespace std;

void cifra(double value, short &d) {
    int result = floor(value);
    d = result % 10;
}

bool isVowel(char letter) {
    char vocals[6] = "aeiou";
    if(strchr(vocals, letter)) return true;
    else return false;
}


void getPair(string input, map<string, int>&dataBase) {

    string output = "";

    for(int i=0; i<input.size(); i++) {
        output = "";
        if(isVowel(input[i]) && isVowel(input[i+1]) && input[i+1] != 0) {
            output.push_back(input[i]);
            output.push_back(input[i+1]);
        }
        if(output != "") dataBase[output]++;
    }
}

void solveExercise3() {
    double a, b; cin>>a>>b;

    short uA=0, uB=0;

    cifra(a,uA); cifra(b,uB);

    uA == uB ? cout<<"Da" : cout<<"Nu";
}

struct map2{
    int index, frequency;
    char[3] sequence;
};

void solveExercise4() {
    ifstream fin("text.in");
    ofstream fout("text.out");
    map<string, int>dataBase;

    while(!fin.eof()) {
        string data; fin>>data;
        getPair(data, dataBase);
    } fin.close();

    int maximumValue = 0;
    for(map<string, int>::iterator i = dataBase.begin(); i != dataBase.end(); i++){
        maximumValue = max(maximumValue, i->second);
    }
        

    for(map<string, int>::iterator i = dataBase.begin(); i != dataBase.end(); i++)
        if(i->second == maximumValue) fout<<i->first<<' ';

    fout.close();
}

int main() {

    //solveExercise3();
    solveExercise4();

    return 0;
}

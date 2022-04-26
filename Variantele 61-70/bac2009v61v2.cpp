#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("text.in");
ofstream fout("text.out");
char word[100];
int freqMatrix[30][30];
const char vowels[] = {'a','e','i','o','u'};

bool isVowel(char value) {
    return strchr(vowels, value) != nullptr;
}

int main() {

    int maxim = 1;
    while(!fin.eof()) {
        fin>>word;
        strlwr(word);
        for (int i=0; i<strlen(word)-1; i++) {
            if (isVowel(word[i]) && isVowel(word[i+1])) {
                freqMatrix[word[i]-'a'][word[i+1]-'a']++;
                maxim = max(maxim, freqMatrix[word[i]-'a'][word[i+1]-'a']);
            }
        }
    } fin.close();

    for(int i=0; i<=4; i++) {
        for(int j=0; j<=4; j++) {
            if (maxim == freqMatrix[vowels[i]-'a'][vowels[j]-'a']) {
                fout<<vowels[i]<<vowels[j]<<endl;
            }
        }
    } fout.close();

    return 0;
}
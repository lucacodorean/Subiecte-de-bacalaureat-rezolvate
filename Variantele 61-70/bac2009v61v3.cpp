#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
#define LIMIT 2030

int isLetter(char c) {
    return c >= 'a' && c <= 'z';
}

int isVowel(char c) {
    return isLetter(c) == 1 && strchr("aeiou",c)!=nullptr;
}

int key(char c1, char c2) {
    return (c1 - 'a') * 100 + (c2 - 'a');
}

int main()
{
    
    char word[100]; 
    int v[LIMIT] = {0}, maxim = -1;

    ifstream fin("text.in");
    ofstream fout("text.out");

    while(!fin.eof()) {
        fin>>word;
        strlwr(word);
        for(int i=0; i<strlen(word)-1; i++){ 
            if(isVowel(word[i]) && isVowel(word[i+1])) {
                v[key(word[i], word[i+1])]++;
                maxim = max(maxim, v[key(word[i],word[i+1])]);
            }
        }
    } fin.close();

    for(int key=0; key<=LIMIT; key++) {
        if(v[key]==maxim) {
            char firstVowel = (key/100+'a'), secondVowel = (key%100+'a');
            fout<<firstVowel<<secondVowel<<endl;
        }
    } fout.close();

    return 0;
}

// c1 c2 c1-'a', c2-'a'
//'ai' 0 8
//  'z' 25   (0..25)(0..25) - 26
//  (c1, c2) => (c1-'a')*100 + (c2-'a') - index unic;
//  
//  Formula de codare: (c1-'a')*100 + (c2-'a') 
//  key:
//          primul caracter - (key/100+'a') -> prima paranteza.
//          al doilea caracter: (i%100+'a') -> a doua paranteza.
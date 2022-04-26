/**
 * S1:
 * 
 *      1) pentru a = 211 =>  a/10 = 21 % 10 = 1; a%10 = 1              => R: d)
 *      2) n = ? a.i f(n) -> 1 n = maxim
 *              Pentru n = 1431            n    |     f(n)
 *                                        ------|-----------
 *                                         1431 |   f(143)
 *                                         143  |   f(14)
 *                                         14   |   f(1)
 *                                         1    |   f(0)
 *                                         0    |   1    
 *              Pentru n = 3034            n    |     f(n)
 *                                        ------|-----------
 *                                         3034 |   f(303)
 *                                         303  |   f(30)
 *                                         30   |   f(3)
 *                                         3    |   f(1)
 *                                         1    |   f(0)
 *                                         0                
 *              Pentru n = 4444            n    |     f(n)
 *                                        ------|-----------
 *                                         4444 |   f(444)
 *                                         444  |   f(44)
 *                                         44   |   f(4)
 *                                         4    |   f(2)
 *                                         2    |   f(1)
 *                                         1    |   f(0)
 *                                         0                          => R: c)
 *      3)   A ={a,b,c,d,e}  , litere distincte doua cate doua
 *               1,2,3,4,5   , NU contin consoane alaturate.
 *          ultimele generari vor incepe cu ed, deci 54, deoarece d si e sunt ultimele elemente
 *          din multime                           
 *                                        
 *                  125     135     ....    5412    =   edab
 *                  1253    1352            5413    =   edac
 *                  1254    1354                                        => R: d)
 *      4)  Nodul 8 este legat de 9, legat de 7, legat de 2, legat de 5 => R: d)
 *      5)  Un nod poate sa fie la capatul unei muchii terminale, 
 *          deci gradul minim poate sa fie 1.
 *          Un nod poate sa fie conectat cu restul de n-1 noduri, 
 *          deci cu alte 2020 noduri.                                   => R: d)
 *                                                                      
 * 
 *  S2:
 *      1)  Algoritmul preia cifra maxima de pe aceeasi pozitie a numerelor si o adauga la 
 *          un rezulat, in scopul obinetrii unui nou numar.
 *          
 *          a)  a = 153 si b = 204  => R: 4351
 *          b)  Cate a  se pot citi pentru b = 1202 a.i nr = 2021?      ATENTIE!!
 *              Cautam numerele de forma abc0 deoarece nr = oglindit(b);
 *                      a       -> 9 valori
 *                      b, c    -> 10 valori                            => R: 9*10*10 = 900
 *          c)  citeste a,b
 *              nr<-0;
 *              |-daca a>0 si b>0 atunci
 *              |   |-executa 
 *              |   |    |-daca a%10 > b%10 atunci
 *              |   |    |   c <- a%10; a<-[a/10]
 *              |   |    |-altfel c <- b%10; b<-[b/10]
 *              |   |   nr <- nr*10 + c
 *              |   |-cat timp a>0 si b>0
 *              |-
 *              scrie nr    
 * 
 *          d) #include <iostream>
 *             using namespace std;
 *             int main() {
 *                  int nr = 0, a,b; cin>>a>>b;
 *                  while(a>0 && b>0) {
 *                      int c=0;
 *                      if(a%10 > b%10) {
 *                          c = a%10; a/=10;
 *                      } else {
 *                          c = b%10; b/=10;
 *                      }
 *                      nr = nr*10 + c;
 *                  }
 *                  cout<<nr;
 *                  return 0;     
 *             } 
 *      
 *      2) Un cerc intersecteaza axa Ox daca: 
 *              a) centrul cercului este pe axa Ox (include originea sistemului)
 *              b) raza cercului este mai mare decat distanta in y-ul originii cercului.
 *          R: C.O.y == 0 || abs(C.O.y) <= C.r
 * 
 *      3)      0               6 5 4 3 2 1
 *              1               7 6 5 4 3 2
 *              2                     5  
 *              3                   7
 *              4                 9
 *              5               11
 *                                      => R: 1,3,5,7,9,11
 *      
 *  S3: 
 *      1)  Se determina minimul si maximul. Pentru minim parcurgem de la 0 spre n deoarece
 *          cautam PRIMA aparitie, iar pentru maxim de la n spre 0 deoarece ne intereseaza 
 *          ultima sa aparitie. In cel mai rau caz, minimul si maximul sunt unul langa celalalt.
 *      2)  Folosim o functie auxiliara care verifica, litera cu litera, secventa de strlen(sufix)
 *          caractere de la finalul cuvantului selectat.
 *      3)  Algoritmul proiectat foloseste 16 bytes deci este eficient dpdv. al memoriei.
 *          In ceea ce priveste complexitatea, el este eficient deoarece parcurge numerele
 *          din fisierul de intrare o singura data.
 * */ 

#include <iostream>

void sub(int v[], int n) {
    int minVal = 10000, maxVal = -1;
    int firstOccurance = -1, lastOccurance = -1;

    for(int i = 0; i<n; i++) {
        minVal = std::min(minVal, v[i]);
        maxVal = std::max(maxVal, v[i]);
    }

    for(int i =0; i<n; i++) {
        if(v[i]==minVal) {
            firstOccurance = i;
            break;
        }
    }

    for(int i = n-1; i>=0; i--) {
        if(v[i]==maxVal) {
            lastOccurance = i;
            break;
        }
    }

    std::swap(v[firstOccurance], v[lastOccurance]);
}

#include <cstring>

bool check(char key[256], char word[256]) {
    int index = strlen(key);
    for(int i = strlen(word); i>=strlen(word)-strlen(key); i--) {
        if(word[i]!=key[index--]) return false;
    }

    return true;
}

void solve_ex2() {
    char text[256], sufix[256];
    std::cin.getline(text, 256);

    int lSufix = 0;
    while(text[lSufix]!='*') {
        lSufix++;
    }

    for(int i = 0; i<lSufix; i++) {
        sufix[i] = text[i];
    } sufix[lSufix] = '\0';

    char *word = strtok(text+lSufix, "*");
    std::cout<<'*';
    while(word!=nullptr) {
        bool ok = check(sufix, word);
        if(ok) {
            std::cout<<'*';
        } else std::cout<<word<<'*';

        word = strtok(NULL, "*");
    }
}

#include <fstream>

int digits_sum(int number) {
    int sum = 0;
    while(number>0) {
        sum+=(number%10);
        number/=10;
    }
    return sum;
}

void solve_ex3() {
    int l = 1, lMax = -1;
    int x, x_ant;
    std::ifstream fin("bac.in");
    fin>>x_ant;
    while(!fin.eof()) {
        fin>>x;
        int curr_sum = digits_sum(x);
        if(digits_sum(x_ant) == curr_sum) {
            l++;
        } else {
            lMax = std::max(l,lMax);
            l = 1;
        }
        x_ant = x;
    } fin.close();
    std::cout<<lMax;
    return;
}

int main() {
    std::cout<<f(1431);
    return 0;
}

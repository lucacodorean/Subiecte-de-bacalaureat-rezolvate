/**
 *  S1:
 *      1)   x= 123     100 <= 123 (1) && 123 <= 999 (1) => 1 && 1 = 1      => R: d)
 *           x=-123   => tot trei cifre.
 *      2)      
 *             f(12345) = ?
 *                              display inainte de AR | AR | display dupa AR
 *                              --------------------------------------------
 *                                      5             |1234|        *
 *                                      4             |123 |        *
 *                                      3             |12 |         *
 *                                      2             | 1 |         *
 *                                      #                                   => R: a)
 *      
 *      3)  A.y == 0 && B.x == 0                                            => R: a)
 *      4)  Un graf neorientat complet are n(n-1)/2 muchii, deci 5*4/2 = 10 => R: d) 
 *      5)  Lanturile elementare de lungime maxima incep din nodurile 2,3   => R: a)
 * 
 *  S2:
 *      1) Algoritmul determina lungimile secventelor de elemente care respecta
 *         cerinta: u.c(x_ant) == p.c(x).
 *      
 *      a)    SECVENTA  | AFISARE
 *          ------------|--------
 *          12 23 34    |    3
 *          592         |    1
 *          13 39 91 1  |    4                 => R: 314
 *  
 *      b) secventa = ? a.i se afisesaza 1234
 *          
 *          Fie secventa: 5 23 32 62 27 72 15 51 16 61 0
 * 
 *            SECVENTA  | AFISARE
 *          ------------|--------
 *          5           |    1
 *          23 32       |    2  
 *          62 27 72    |    3
 *          15 51 16 61 |    4             => R: 5 23 32 62 27 72 15 51 16 61 0
 *      
 *      c)  citeste x,y (numere naturale)
 *          p <- 1
 *          |- cat timp y>0 executa
 *          |       t<-y
 *          |       |- daca t>9 atunci
 *          |       |        |- repeta
 *          |       |       |     t<-[t/10]
 *          |       |       |-cat timp t>9
 *          |       |-                  
 *          |       
 *          |       |- daca x%10 = t atunci p <- p+1
 *          |       |  |- altfel 
 *          |       |  |     scrie p
 *          |       |  |    p <- 1
 *          |       |  |- 
 *          |       |-
 *          |       x <- y
 *          |        citeste y   (numar natural)
 *          |-
 *          scrie p
 * 
 *      d)  #include <iostream>
 *          using namespace std;
 *          int main() {
 *              int x,y; cin>>x>>y;
 *              int p = 1;
 *              while(y>0) {
 *                  int t = y;
 *                  
 *                  while(t>9) { t/=10; }
 *                  if(x%10 == t) p++;
 *                  else {
 *                      cout<<p;
 *                      p=1;     
 *                  }
 *                  x=y;
 *                  cin>>y;
 *              }
 *              cout<<p;
 *              return 0;
 *          }
 * 
 *      2)  A = {1,2,3,4}   n = abcde a.i a + b = 5;
 *          Scrieți câte dintre numerele generate încep și se termină cu cifra 3?
 *          incep cu 3 => 3 + b = 5 => b = 2 => n = 32ab3
 *                       
 *              a apartine lui A => 4 valori        => 4*4 = 16 numere
 *              b apartine lui B => 4 valori 
 *            14111   14121      ...     32113   32123   32133   32143
 *            14112   14122              32213   32223   32233   32243     
 *            14113   14123              32313   32323   32333   32343   
 *            14114   14124              32413   32423   32433   32443  => R: 16 numere
 * 
 *      3)  s = "3a+b=9";
 *               012345
 *          primul strpcy    ==> a+b=9
 *          al doilea strcpy ==> sterge caracterul de pe poz 2  => R: a=9
 * 
 *  S3:
 *      1)  Pentru a nu adauga logica inutila subprogramului cerut, cream 
 *          inca un subprogram, numit insert, care adauga in array. Retinem intr-un array pozitiile in
 *          care trebuie sa adaugam pentru a nu intra intr-un loop inifnit.
 *      2)  N/A
 *      3)  Pentru a determina daca numerele "santinela", folosim doua functii care determina
 *          daca numerele in cauza sunt formate doar din cifre pare sau doar din cifre impare.
 *          Pentru fiecare numar, determinam natura acestuia. In momentul in care gasim un numar
 *          care este format doar din cifre impare, avand deja un numar gasit care are doar cifre
 *          pare in componenta, comparam lungimea maxima pana in acel punct cu valoarea pozitiei curente
 *          din care scadem valoarea de start, start setat pe numarul cu cifre pare. Resetam startul.
 * 
 *          Algoritmul dezoltat este eficient deoarece nu presupune stocarea valorilor din fisierul de intrare
 *          intr-un array, fisierul fiind parcurs o singura data, deci complexitatea este liniara.
 *          De asemenea, din punct de vedere al memoriei, suboprogramul foloseste doar 16 bytes, ceea ce 
 *          ii asigura eficienta.
 * */

#include <iostream>

void insert(int value, int index, int arr[], int& size) {
    for(int i = size; i>=index; i--) {
        arr[i] = arr[i-1];
    }
    arr[index] = value;
    size++;
}

void sub(int x, int v[], int& n) {
    int add[100] = {0}, l = 0;
    for(int i=0; i<n; i++) {
        if(v[i]==x) {
            add[l++] = i+1;
       }
    }

    for(int i = 0; i<l; i++) {
        insert(x,add[i],v,n);
    }
}


void solve_ex2() {
    int n,m, a[25][25] = {0}; std::cin>>n>>m;

    for(int i = 1; i<=n; i++) {
        a[i][1] = i;
    }

    for(int i=1; i<=m; i++) {
        a[1][i] = i;
    }

    for(int i = 2; i<=n; i++) {
        for(int j = 2; j<=m; j++) {
            a[i][j] = a[i-1][j] + a[i][j-1];
        }
    }
    
    for(int i=1; i<=n; i++) {
        for(int j =1; j<=m; j++) {
            std::cout<<a[i][j]<<' ';
        } std::cout<<'\n';
    }
}

#include <fstream>

bool has_even_digits(int number) {
    while(number>0) {
        if ((number%10)%2 == 1) return false;
        number/=10;
    }

    return true;
}

bool has_odd_digits(int number) {
    while(number>0) {
        if ((number%10)%2 == 0) return false;
        number/=10;
    }

    return true;
}

void solve_ex3() {
    int lMax = 0, x, start = -1, position = 0;
    std::ifstream fin("bac.in");

    while(!fin.eof()) {
        fin>>x;
        position++;
        if(has_even_digits(x)==true) {
           if(start == -1) start=position;
           else start ++;
        } 
        if(has_odd_digits(x)==true) {
            lMax = std::max(lMax, position - start);
            start = -1;
        }

    } fin.close();
    std::cout<<lMax;
    return;
}

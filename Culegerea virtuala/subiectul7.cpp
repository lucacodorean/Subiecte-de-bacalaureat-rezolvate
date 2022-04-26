/**
 * @file subiectul7.cpp
 * @author Luca Codorean (luca.codorean@lapidej.ro)
 * @brief 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 *  S1:
 *      1)  -5%5 = 0 - 1 = -1
 *           4%5 = 1 - 1 =  0
 *          -1%5 = 4 - 1 =  3
 *           3%5 = 2 - 1 =  1                                           => R: a)
 * 
 *      2)  f(315) = ?
 *              f(315) => f(313);                                       => R: a)
 *              f(313) = f(31) + 1  = 3
 *              f(31)  = f(3)  + 1  = 2
 *              f(3)   = f(1)       = 1
 *              f(1)   = f(0) + 1   = 1
 *              f(0)                = 0
 *  
 *      3) S = 10 
 *              1+2+3+4     2+1+3+4 sau orice alta forma nu se genereaza pt ca avem 1+2+3+5
 *              1+2+7       2+1+7   sau orice alta forma nu se genereaza pt ca avem 1+2+7
 *              1+3+6       2+3+5
 *              1+4+5       2+8                                         => R: c)
 *              1+9
 *              
 *      4) Varianta d) nu este un arobre deoarece nodurile 4,2 sunt 
 *         izolate fata de restul arborelui.                            => R: d)
 *      
 *      5) Izoland nodurile 4 si 5 de restul grafului obtinem trei componente conexe,
 *         si astfel taiem 7 muchii. De asemenea, din componenta conexa (1,2,3), putem sa mai
 *         renuntam la o muchie deoarece aceasta este un  ciclu, deci vom avea 8 muchii la are
 *         am renuntat.
 * 
 *         G.c cu 5 noduri => 10 muchii.
 *         2 noduri izolate => g.c cu 3 noduri => 3*2/2 = 3 muchii.
 *         3 noduri se pot lega cu 2 muchii
 *          => 10 - x = 2 => x = 8                                      => R: c)
 * 
 * 
 *  S2:
 * 
 *      1) Algoritmul verifica daca numarul a este multiplu de b si adauga ultima cifra a lui a
 *          intr-un nou numar, in caz afirmativ.
 * 
 *          a)  a = 12541 si b = 3
 * 
 *              nr multiplu de 3 daca scif(nr) multiplu de 3
 *              1+2+5+4+1 = 2+2+5+4 = 8+5 = 13
 *              1+2+5+4   = 12                  => nr = 4
 *              1+2+5     = 8                   => nr = 4
 *              1+2       = 3                   => nr = 24
 *              1         = 1                   => nr = 24              => R: 24
 * 
 *          b)  a=?; a = 4 cifre, a = cel mai mare nr a.i nr = 0 si b = 9;
 * 
 *              Numarul a nu poate sa fie format doar din cifre de 9 deoarece 9*n = multiplu de 9
 *              => a poate sa aiba 9 in componenta, dar trebuie sa aiba si alte valori.
 *              Cele mai mari doua valori <= 9 sunt 9 si 8 => a este format din 9 si 8
 * 
 *              9+9+8+8 = 34 -> nu este multiplu de 9
 *              9+9+9+8 = 35 -> nu este multiplu de 9
 *              
 *              9 nu poate sa fie pe prima pozitie deoarece ajungem in cazul 9%9 == 0
 *              8999    => 8+9+9+9 = 39 -> nu este multiplu de 9    => nr = 0;
 *                         8+9+9   = 26 -> nu este multiplu de 9    => nr = 0;
 *                         8+9     = 17 -> nu este multiplu de 9    => nr = 0;
 *                         8       = 8  -> nu este multiplu de 9    => nr = 0;      => R: 8999.
 * 
 *          c)  #include <iostream>
 *              using namespace std;
 *              int main() {
 *                  int a,b; cin>>a>>b;
 *                  int p = 1, c = 0;
 *                  while(a!=0) {
 *                      if(a%b==0) {
 *                          c=c+a%10*p;
 *                          p*=10;
 *                      }
 *                      a/=10;
 *                  }
 *                  cout<<c;
 *                  return 0;
 *              }
 *      
 *          d) Pentru ca se specifica faptul ca a = nr natural != 0, instructiunea daca conditie
 *             nu mai este necesara in transformarea din cat timp in repeta cat timp.
 *              
 *              citeste a,b (numere naturale nenule)
 *              p <- 1
 *              c <- 0
 *              daca a!=0 atunci                -> cu siguranta returneaza true pentru ca a!=0
 *                  repeta 
 *                      daca a%b = 0 atunci
 *                          c <- c+a%10*p
 *                          p <- p*10
 *                  
 *                      a<-[a/10]
 *                  cat timp a!=0
 *              scrie c  
 * 
 *      2) dn.z == e.d_nt.z && dn.l == e.dn_t.l && dn.a == e.dn_t.a
 *      3) s = bac2021
 *             0123456
 *         s[3] = s[3]-1 => s = bac1021
 *         primul    strcpy      => pune in t sfarsitul de sir
 *         al doilea strcpy      => sterge ultimele 2 caractere  => s = bac10
 *         al trielea strcpy     => pune in t de la al treilea caracter => t = 10
 *         al patrulea strpcy    => pune t in s                 => s = 10           => R: 10
 * 
 *  S3:
 *      1) Subprogramul auxiliar find determina daca un numar exista intr-un array-ul dat.
 * 
 *      2) Elementele de pe diagonalele paralele cu D.P sunt egale.
 * 
 *      3) Algoritmul citeste o singura data numerele din fisier, ceea ce ii asigura rapiditate
 *         in ceea ce priveste timpul de executie, deoarece complexitatea creste liniar cu numarul
 *         de elemente din fisierul de intrare. Se afla unde incepe secventa si se memoreaza pozitia.
 *         Pentru fiecare aparitie ulterioara a cheii se memoreaza pozitia si se reseteaza numarul de elemente
 *         aflate dupa aceasta. Rezultatul final este diferenta dintre elementele aflate dupa start
 *         si cele aflate dupa stop.
 */     

#include <iostream>
#include <fstream>
#include <iomanip>

bool find(int value, int source[], int size) {
    for(int i = 0; i<size; i++) {
        if(source[i]==value) return true;
    }

    return false;
}

int pare(int a, int b, int v[], int n) {
    if (a>=b) std::swap(a,b);

    int result = 0;

    for(int number = a; number<=b; number++) {
        if(number%2==0 && find(number,v,n)==true) {
            result++;
        }
    }
    return result;
}

void display(int arr[21][21], int sizeR, int sizeC) {
    for(int i=1; i<=sizeR; i++) {
        for(int j=1; j<=sizeC; j++) {
            std::cout<<arr[i][j]<<' ';
        }   std::cout<<'\n';
    }
}

void solve_ex2() {
    int n,m, a[21][21] = {0};
    std::cin>>n>>m;

    int index = 1;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            a[i][j] = index;
            if(index == 9) index = 1;
            else index+=2;
        }
    }

    display(a,m,n);
}

void solve_ex3() {
    std::fstream fin("bac.in", std::ios::in);

    int key, dupa_start = 0, dupa_stop = 0; fin>>key;
    int start_position = -1, position = 0, stop_position = -1;
    while(!fin.eof()) {
        int number;
        fin>>number;
        position++;
        if(number==key) {
            if(start_position == -1) start_position = position;
            else {
                stop_position = position;
                dupa_stop = 0;
            }
        } 
        if(number%2==1) {
            if(start_position != -1) dupa_start++;
            if(stop_position  != -1) dupa_stop++;
        } 
    } fin.close();

    if(start_position == -1 || stop_position == -1) std::cout<<"nu exista";
    else std::cout<<dupa_start-dupa_stop;
    return;
}

int main() {
    solve_ex3();
    return 0;
}
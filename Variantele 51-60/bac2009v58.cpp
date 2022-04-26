#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
#define LIMIT 1005

void divizor(int value, int &d) {
    for(int number = value-1; number>=2; number--) {
        if(value%number==0) {
            d = number;
            break;
        }
    }
}

void solveExercise3() {
    
    ifstream fin("numere.in");

    vector<int>numbers;

    while(!fin.eof()) {
        int x; fin>>x;
        numbers.push_back(x);
    }
    fin.close();

    sort(numbers.begin(),numbers.end());

    cout<<numbers[0]<<' '<<numbers[1]<<' '<<numbers[2];
}

void solveExercise4() {
    int n;
    cin>>n;
    int result = 1;
    divizor(n, result);

    result == 1 ? cout<<"DA" : cout<<"NU";
}

int main() {
    //solveExercise3();
    solveExercise4();

    return 0;
}

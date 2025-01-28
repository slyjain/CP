#include <iostream>
using namespace std;

void printPyramid(int n) {
    for(int i=1;i<=n;i++){
        int emptySpace=n-i;
        for(int j=1;j<=emptySpace;j++){cout<<" ";}
        for(int j=1;j<=((2*i)-1);j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}

int main() {
    int n;
    // cout << "Enter the number of rows for the pyramid: ";
    cin >> n;
    printPyramid(n);
    return 0;
}

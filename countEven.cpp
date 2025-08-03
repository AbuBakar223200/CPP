#include <iostream>

using namespace std;

int countEven(int a[], int i, int j){
    if(i == j) return (a[i]%2==0) ? 1: 0; // a[i] for evenSum
    int m = (i+j)/2;
    return countEven(a, i, m) + countEven(a, m+1, j);
}

int main(){
    int n;
    int a[100];
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    cout << countEven(a, 0,n-1);

    return 0;
}

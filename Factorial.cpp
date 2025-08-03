#include <iostream>

using namespace std;

int factorial(int n){
    int f = 1;
    for(int i=1; i<=n; i++) f*= i;
    return f;
}

int factorial_rec(int n){
    if(n == 0) return 1;             //if (n==1) return 1;
    return n*factorial_rec(n-1);     // return n+factorial_rec(n-1);
}

//    for(int i=0; i<n/2; i++){
//        tmp = a[i];
//        a[i] = a[n-i-1];
//        a[n-i-1] = tmp;
//    }
//

void printArray(int a[], int n) {for(int i=0; i<n; i++) cout << a[i] << " "; cout <<endl;}

void reverseArray(int a[], int n, int i){
    if(i >= n/2 ) return;
    reverseArray(a, n, i+1);

    int tmp;

    tmp = a[i];
    a[i] = a[n-i-1];
    a[n-i-1] = tmp;

    cout << "i: " << i << " --- ";
    printArray(a,n);

}


int main(){
    int x, y, n;
//    cin >> x >> y;
//    cout << factorial_rec(x) << " " << factorial_rec(y) << endl;
    int a[100];
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    reverseArray(a,n,0);
    cout << "After reverse:" << endl;
    for(int i=0; i<n; i++) cout << a[i] << " ";

    return 0;
}

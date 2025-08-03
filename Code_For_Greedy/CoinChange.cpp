// #include <iostream>
// #include <algorithm>

// using namespace std;

// int main(){
//     int c[100];
//     int n,d,tc = 0;
//     cin >> n >> d;
//     for(int i=0; i<d; i++) cin >> c[i] ;
//     sort(c, c+d, greater<int>());
//     for(int i=0; i<d && n>0; i++){
//         if(c[i] <= n){
//             tc += n/c[i];
//             n = n%c[i];
//         }
//     }
//     cout << tc << endl;
//     return 0;
// }

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int c[100];
    int coinCount[100] = {0}; // Array to store the count of each coin
    int n, d, tc = 0;
    cin >> n >> d;
    for (int i = 0; i < d; i++) cin >> c[i];
    sort(c, c + d, greater<int>());
    for (int i = 0; i < d && n > 0; i++) {
        if (c[i] <= n) {
            coinCount[i] = n / c[i]; // Store the count of the current coin
            tc += coinCount[i]; // Update total count
            n = n % c[i]; // Update remaining amount
        }
    }
    cout << "Total coins used: " << tc << endl;
    for (int i = 0; i < d; i++) {
        if (coinCount[i] > 0) {
            cout << "Coin " << c[i] << ": " << coinCount[i] << endl;
        }
    }
    return 0;
}



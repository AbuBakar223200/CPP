#include <bits/stdc++.h>

using namespace std;


int main(){
    int a[] = {5,12,22,2,1,7};
    sort(a, a+6, greater<int>());
    for(int i=0; i<6; i++) cout << a[i] << " " ;
    return 0;
}


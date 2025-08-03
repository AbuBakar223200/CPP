#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,t=0;
    float s,e;
    float a[100];
    cin >> n;
    for(int i=0; i<n;i++) cin >> a[i];
    sort(a, a+n);
    s = a[0]; e=s+1; t = 1;
    cout << s << "," << e << endl;
    for(int i=0; i<n; i++){
       if(a[i] >= s && a[i] <= e) continue;
       s = a[i];e = s+1; t++;
       cout << s << ", " << e << endl;
    }
    cout << t << endl;

}

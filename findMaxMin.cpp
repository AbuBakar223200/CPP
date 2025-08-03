#include <iostream>
using namespace std;
struct pr{
    float max, min;
};

struct pr findMaxMin(float a[], int i, int j){
    struct pr res;
    if(i == j) {
        res.max = res.min = a[i];
        return res;
    }
    int m = (i+j)/2;
    struct pr left = findMaxMin(a, i, m);
    struct pr right = findMaxMin(a, m+1, j);
    res.min = left.min < right.min ? left.min : right.min;
    res.max = left.max > right.max ? left.max : right.max;
    return res;
}

int main(){
    int n;
    float a[100];
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    struct pr r = findMaxMin(a, 0 , n-1);
    cout << r.max << " " << r.min << endl;

    return 0;
}

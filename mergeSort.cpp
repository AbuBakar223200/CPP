#include <iostream>
#include <climits>
using namespace std;

void merge(int a[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r-q;
    int left[n1+1], right[n2+1];

    for(int i=0; i<n1; i++) left[i] = a[p+i];
    for(int i=0; i<n2; i++) right[i] = a[q+i+1];
    left[n1] = right[n2] = INT_MAX;

    int i, j; i=j= 0;
    for(int k=p; k<=r; k++){
        if(left[i] < right[j]) a[k] = left[i++];
        else a[k] = right[j++];
    }
}

void mergeSort(int a[], int p, int r){
    if(p<r){
        int q = (p+r)/2;
        mergeSort(a, p, q);
        mergeSort(a, q+1,r);
        merge(a, p, q, r);
    }
}

int main(){
    int n;
    int a[100];
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    mergeSort(a, 0, n-1);
    for (int i=0; i<n; i++) cout << a[i] << " " ;
    cout << endl;
    return 0;
}


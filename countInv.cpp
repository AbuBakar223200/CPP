#include <iostream>
#include <climits>
using namespace std;
void printArr(int a[], int n){ for(int i=0; i<n; i++) cout << a[i] << " ";  cout <<endl; }

int merge(int a[], int p, int q, int r){
    int invCount = 0;
    int n1 = q - p + 1;
    int n2 = r-q;
    int left[n1+1], right[n2+1];

    for(int i=0; i<n1; i++) left[i] = a[p+i];
    for(int i=0; i<n2; i++) right[i] = a[q+i+1];
    left[n1] = right[n2] = INT_MAX;

    int i, j; i=j= 0;

//    cout << "Merging ..." << p << " " << q << " " << r <<endl;
//    cout << "Left : " ; printArr(left, n1+1);
//    cout << "Right : "; printArr(right, n2 + 1);

    for(int k=p; k<=r; k++){
        if(left[i] <= right[j]) a[k] = left[i++];
        else {
            if(i != n1) {
//                cout << left[i] << " " << right[j] << " " << j << endl;
                invCount += (n1-i);
            }
            a[k] = right[j++];
        }
    }
    return invCount;
}

int countInv(int a[], int p, int r){
    int invCount = 0;
    if(p<r){
        int q = (p+r)/2;
        invCount += countInv(a, p, q);
        invCount += countInv(a, q+1,r);
        invCount += merge(a, p, q, r);
    }
    return invCount;
}

int main(){
    int n;
    int a[100];
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    cout << countInv(a, 0, n-1) << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;


int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    
    int j = mid + 1; 
    int k = left;    
    int inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            inv_count += (mid - i + 1);
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);      
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right); 
        inv_count += mergeAndCount(arr, temp, left, mid, right);   
    }
    return inv_count;
}


int countGoodPairs(int arr[], int n) {
    int temp[n]; 
    int inversions = mergeSortAndCount(arr, temp, 0, n - 1);
    int total_pairs = n * (n - 1) / 2;
    int good_pairs = total_pairs - inversions;
    return good_pairs;
}

int main() {
    int n;
    cout << "number of element: ";
    cin >> n;

    int A[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int goodPairs = countGoodPairs(A, n);

    cout << "good pairs: " << goodPairs << endl;

    return 0;
}

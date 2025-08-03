#include <bits/stdc++.h>
using namespace std;


int crossSum(int arr[], int low, int mid, int high, int& start, int& end) {
    int left_sum = INT_MIN;
    int sum = 0;
    int temp_start = mid;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
            temp_start = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    int temp_end = mid + 1;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
            temp_end = i;
        }
    }

    start = temp_start;
    end = temp_end;
    return left_sum + right_sum;
}


int find_max_sum_subarray(int arr[], int low, int high, int& start, int& end) {
    if (low == high) {
        start = low;
        end = low;
        return arr[low];
    }

    int mid = (low + high) / 2;

    int left_start, left_end, right_start, right_end, cross_start, cross_end;

    int left_max = find_max_sum_subarray(arr, low, mid, left_start, left_end);
    int right_max = find_max_sum_subarray(arr, mid + 1, high, right_start, right_end);
    int cross_max = crossSum(arr, low, mid, high, cross_start, cross_end);

    if (left_max >= right_max && left_max >= cross_max) {
        start = left_start;
        end = left_end;
        return left_max;
    } 
    else if (right_max >= left_max && right_max >= cross_max) {
        start = right_start;
        end = right_end;
        return right_max;
    } 
    else {
        start = cross_start;
        end = cross_end;
        return cross_max;
    }
}

int main() {
    int n;
    cout << "number of element: ";
    cin >> n;

    int arr[n];
    cout << "Enter the element: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start, end;
    int max_sum = find_max_sum_subarray(arr, 0, n - 1, start, end);
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
     cout<< endl;
     cout << "sum: " << max_sum << endl;
   
    return 0;
}

#include <iostream>
using namespace std;

int findMax(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    } else if (high == low + 1) {
        if (arr[low] > arr[high]) {
            return arr[low];
        } else {
            return arr[high];
        }
    } else {
        int mid = (low + high) / 2;
        int leftMax = findMax(arr, low, mid);
        int rightMax = findMax(arr, mid + 1, high);

        if (leftMax > rightMax) {
            return leftMax;
        } else {
            return rightMax;
        }
    }
}

int main() {
    int n;
    cout << "Enter how many numbers you want to compare: " << endl;
    cin >> n;
    int arr[n];

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxElement = findMax(arr, 0, n - 1);

    cout << "Maximum element in the array is: " << maxElement << endl;

    return 0;
}

//Kth Largest Element in an Array
#include <iostream>
#include <algorithm> // for swap

using namespace std;

// Function to partition the array
int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] >= pivot) { // For k-th largest, use >= instead of <=
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// Function to perform the Quickselect
int quickSelect(int arr[], int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    // Use the middle element as the pivot
    int pivotIndex = left + (right - left) / 2;
    swap(arr[pivotIndex], arr[right]);
    pivotIndex = partition(arr, left, right);

    if (pivotIndex == k) {
        return arr[pivotIndex];
    } else if (pivotIndex < k) {
        return quickSelect(arr, pivotIndex + 1, right, k);
    } else {
        return quickSelect(arr, left, pivotIndex - 1, k);
    }
}

// Main function to take user input and find the k-th largest element
int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* nums = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Invalid value of k" << endl;
        delete[] nums;
        return 1;
    }

    int result = quickSelect(nums, 0, n - 1, k - 1);
    cout << "The " << k << "-th largest element is: " << result << endl;

    delete[] nums;
    return 0;
}

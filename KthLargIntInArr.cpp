//Find the Kth Largest Integer in the Array
//You are given an array of strings nums and an integer k. Each string in nums represents an integer without leading zeros.
//Return the string that represents the kth largest integer in nums.
#include <iostream>
#include <string>
#include <algorithm> // for swap

using namespace std;

// Function to compare two strings representing integers
bool compare(const string &a, const string &b) {
    if (a.length() != b.length()) {
        return a.length() > b.length();
    }
    return a > b;
}

// Function to partition the array
int partition(string arr[], int left, int right) {
    string pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (compare(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// Function to perform the Quickselect
string quickSelect(string arr[], int left, int right, int k) {
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

// Main function to take user input and find the kth largest integer
int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;

    string* nums = new string[n];
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

    string result = quickSelect(nums, 0, n - 1, k - 1);
    cout << "The " << k << "-th largest integer is: " << result << endl;

    delete[] nums;
    return 0;
}

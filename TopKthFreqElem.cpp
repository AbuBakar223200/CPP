//Top K Frequent Elements
//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
#include <iostream>
#include <algorithm> // for swap
#include <utility> // for pair

using namespace std;

// Function to find the maximum element in the array
int findMaxElement(int arr[], int n) {
    int maxElement = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

// Function to partition the array of pairs (element, frequency)
int partition(pair<int, int> arr[], int left, int right) {
    int pivot = arr[right].second;
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j].second >= pivot) { // For k most frequent, use >=
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// Function to perform the Quickselect on the array of pairs
void quickSelect(pair<int, int> arr[], int left, int right, int k) {
    if (left == right) {
        return;
    }

    // Use the middle element as the pivot
    int pivotIndex = left + (right - left) / 2;
    swap(arr[pivotIndex], arr[right]);
    pivotIndex = partition(arr, left, right);

    if (pivotIndex == k) {
        return;
    } else if (pivotIndex < k) {
        quickSelect(arr, pivotIndex + 1, right, k);
    } else {
        quickSelect(arr, left, pivotIndex - 1, k);
    }
}

// Main function to take user input and find the k most frequent elements
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

    // Find the maximum element to define the range
    int maxElement = findMaxElement(nums, n);

    // Create a frequency array
    int* freq = new int[maxElement + 1]();
    for (int i = 0; i < n; ++i) {
        freq[nums[i]]++;
    }

    // Convert the frequency array to an array of pairs
    int uniqueCount = 0;
    for (int i = 0; i <= maxElement; ++i) {
        if (freq[i] > 0) {
            uniqueCount++;
        }
    }

    pair<int, int>* freqArr = new pair<int, int>[uniqueCount];
    int index = 0;
    for (int i = 0; i <= maxElement; ++i) {
        if (freq[i] > 0) {
            freqArr[index++] = make_pair(i, freq[i]);
        }
    }

    // Perform Quickselect to find the k most frequent elements
    quickSelect(freqArr, 0, uniqueCount - 1, k - 1);

    // Print the k most frequent elements
    cout << "The " << k << " most frequent elements are: ";
    for (int i = 0; i < k; ++i) {
        cout << freqArr[i].first << " ";
    }
    cout << endl;

    delete[] nums;
    delete[] freq;
    delete[] freqArr;
    return 0;
}

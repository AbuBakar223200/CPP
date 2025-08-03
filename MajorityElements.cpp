#include <iostream>
#include <algorithm>

using namespace std;

// Function to find the majority element in a range of the array
int majorityElementRec(int arr[], int left, int right) {
    // Base case: if the range has only one element, return it
    if (left == right) {
        return arr[left];
    }

    // Calculate the mid-point of the range
    int mid = (left + right) / 2;

    // Recursively find the majority element in the left and right halves
    int leftMajority = majorityElementRec(arr, left, mid);
    int rightMajority = majorityElementRec(arr, mid + 1, right);

    // If both halves agree on the majority element, return it
    if (leftMajority == rightMajority) {
        return leftMajority;
    }

    // Count the occurrences of the left and right majority elements in the whole range
    int leftCount = 0;
    int rightCount = 0;
    for (int i = left; i <= right; ++i) {
        if (arr[i] == leftMajority) {
            leftCount++;
        } else if (arr[i] == rightMajority) {
            rightCount++;
        }
    }

    // Return the element that occurs more frequently
    return leftCount > rightCount ? leftMajority : rightMajority;
}

// Function to find the majority element in the array
int majorityElement(int arr[], int n) {
    return majorityElementRec(arr, 0, n - 1);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* nums = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = majorityElement(nums, n);
    cout << "The majority element is: " << result << endl;

    delete[] nums;
    return 0;
}

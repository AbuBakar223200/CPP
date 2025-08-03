//Maximum Sum Circular Subarray
//Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
//A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
//A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
#include <iostream>

using namespace std;

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the maximum subarray sum using Kadane's algorithm
int kadane(int nums[], int n) {
    int maxEndingHere = nums[0];
    int maxSoFar = nums[0];

    for (int i = 1; i < n; ++i) {
        maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

// Function to find the maximum circular subarray sum
int maxSubarraySumCircular(int nums[], int n) {
    // Case 1: Maximum subarray sum is within the array boundaries
    int maxNormal = kadane(nums, n);

    // Case 2: Maximum subarray sum wraps around (circular)
    int totalSum = 0;
    for (int i = 0; i < n; ++i) {
        totalSum += nums[i];
        nums[i] = -nums[i]; // Invert the array for finding minimum subarray sum
    }
    int maxCircular = totalSum + kadane(nums, n);

    // If all numbers are negative, maxCircular would be the same as maxNormal
    return (maxCircular > 0) ? max(maxNormal, maxCircular) : maxNormal;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int nums[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int maxSum = maxSubarraySumCircular(nums, n);
    cout << "The maximum possible sum of a non-empty circular subarray is: " << maxSum << endl;

    return 0;
}

//Maximum Sum Circular Subarray
//Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
//A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
//A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// Function to find the maximum subarray sum for a non-circular subarray
int maxSubarraySum(int nums[], int n) {
    int maxEndingHere = nums[0];
    int maxSoFar = nums[0];
    for (int i = 1; i < n; i++) {
        maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

// Function to find the maximum sum circular subarray
int maxCircularSubarraySum(int nums[], int n) {
    // Step 1: Find the maximum subarray sum using Kadane's algorithm
    int max_kadane = maxSubarraySum(nums, n);

    // Step 2: Find the maximum circular subarray sum
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += nums[i];
        nums[i] = -nums[i]; // Inverting the array
    }

    // Step 3: Find the maximum subarray sum of the inverted array
    int max_inverted_kadane = maxSubarraySum(nums, n);

    // If the sum of the inverted array is equal to the total sum, it means all elements are negative
    // In such a case, return the maximum Kadane result.
    if (total_sum + max_inverted_kadane == 0) {
        return max_kadane;
    } else {
        return max(max_kadane, total_sum + max_inverted_kadane);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int nums[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = maxCircularSubarraySum(nums, n);
    cout << "The maximum possible sum of a non-empty subarray is: " << result << endl;

    return 0;
}

//Given an integer array nums, find the
//subarray
// with the largest sum, and return its sum.
#include <iostream>
#include <climits>

int maxCrossingSum(int arr[], int left, int mid, int right) {
    int sum = 0;
    int left_sum = INT_MIN;

    // Include elements on left of mid
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;

    // Include elements on right of mid
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    // Return sum of elements on left and right of mid
    return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int left, int right) {
    // Base case: only one element
    if (left == right)
        return arr[left];

    int mid = (left + right) / 2;

    // Find maximum subarray sum for left, right, and crossing the mid
    int left_sum = maxSubArraySum(arr, left, mid);
    int right_sum = maxSubArraySum(arr, mid + 1, right);
    int cross_sum = maxCrossingSum(arr, left, mid, right);

    // Return the maximum of the three
    return std::max(std::max(left_sum, right_sum), cross_sum);
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int max_sum = maxSubArraySum(nums, 0, n - 1);
    std::cout << "The maximum subarray sum is: " << max_sum << std::endl;
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool isSorted;  // Flag to check if the array is already sorted

    for (int i = 0; i < n - 1; i++) {
        isSorted = true;  // Assume the array is sorted at the beginning of each pass
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSorted = false;  // If a swap occurs, the array is not sorted
            }
        }

        // If the inner loop completes without any swaps, the array is already sorted
        if (isSorted) {
            break;
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

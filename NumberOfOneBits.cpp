//Number Of 1 Bits
#include <iostream>

using namespace std;

// Function to count the number of set bits in a given range of bits
int countSetBitsRec(int n) {
    // Base case: if n is 0, it has no set bits
    if (n == 0) {
        return 0;
    }

    // Divide the problem: count the set bits in the remaining part of n
    return (n & 1) + countSetBitsRec(n >> 1);
}

// Main function to take user input and output the number of set bits
int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    // Ensure the input is positive
    if (n < 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    int result = countSetBitsRec(n);
    cout << "The number of set bits is: " << result << endl;

    return 0;
}

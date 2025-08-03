//Longest Substring with At Least K Repeating Characters
//Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
//if no such substring exists, return 0.
#include <iostream>
#include <string>

using namespace std;

const int MAX_CHARS = 26; // Assuming only lowercase English letters

// Function to find the length of the longest substring with all characters appearing at least k times
int longestSubstring(string s, int k) {
    int n = s.length();
    if (n == 0 || k > n) return 0;

    // Array to count frequencies of each character
    int freq[MAX_CHARS] = {0};
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Check if the entire substring meets the frequency requirement
    bool allValid = true;
    for (int i = 0; i < MAX_CHARS; ++i) {
        if (freq[i] > 0 && freq[i] < k) {
            allValid = false;
            break;
        }
    }
    if (allValid) return n; // Entire string meets the requirement

    // Find the first character that does not meet the frequency requirement
    int start = 0;
    while (start < n && freq[s[start] - 'a'] >= k) {
        start++;
    }
    if (start == n) return n; // All characters meet the requirement

    // Recursively check substrings divided by characters that don't meet the requirement
    int left = longestSubstring(s.substr(0, start), k);
    while (start < n && freq[s[start] - 'a'] < k) {
        start++;
    }
    int right = longestSubstring(s.substr(start), k);

    return max(left, right);
}

int main() {
    string s;
    int k;

    cout << "Enter the string: ";
    cin >> s;

    cout << "Enter the value of k: ";
    cin >> k;

    int result = longestSubstring(s, k);
    cout << "The length of the longest substring with all characters appearing at least " << k << " times is: " << result << endl;

    return 0;
}

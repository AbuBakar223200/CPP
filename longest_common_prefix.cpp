#include <bits/stdc++.h>
using namespace std;

string lCP(string s1, string s2) {
    int minLength = min(s1.length(), s2.length());
    int i = 0;
    while (i < minLength && s1[i] == s2[i]) {
        i++;
    }
    return s1.substr(0, i);
}

string findLCP(string strs[], int low, int high) {
    if (low == high) {
        return strs[low]; 
    } else if (low < high) {
        int mid = (low + high) / 2;
        string leftLCP = findLCP(strs, low, mid); 
        string rightLCP = findLCP(strs, mid + 1, high); 
        return lCP(leftLCP, rightLCP); 
    } else {
        return ""; 
    }
}

int main() {
    int n;
    cout << "number of string: ";
    cin >> n;

    string strs[n];
    cout << "Enter strings: ";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    string longestCommonPrefix = findLCP(strs, 0, n - 1);

    if (longestCommonPrefix.empty()) {
        cout << "no common prefix" << endl;
    } else {
        cout << longestCommonPrefix << endl;
    }

    return 0;
}

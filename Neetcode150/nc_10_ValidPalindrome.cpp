/*
Approach:
---------
We must check if a string is a palindrome considering only:
- Alphanumeric characters (a–z, A–Z, 0–9)
- Case-insensitive comparison

Steps:
1. Preprocess the string:
   - Remove all non-alphanumeric characters.
   - Convert all characters to lowercase.
   (This is done in convertToCorrectFormat)

2. Check if the processed string is a palindrome:
   - Compare characters from both ends moving towards the center.

Time Complexity:
----------------
O(n):
- One pass to clean the string
- One pass to check palindrome

Space Complexity:
-----------------
O(n) for the cleaned string.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Helper function to extract only lowercase alphanumeric characters
    string convertToCorrectFormart(string s) {
        string ans = "";
        for (char c : s) {
            // Keep letters and digits only
            if ((c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9')) {

                ans += tolower(c);  // convert to lowercase
            }
        }
        return ans;
    }

    // Check if cleaned string is a palindrome
    bool isPalindrome(string s) {
        string converted = convertToCorrectFormart(s);
        int n = converted.size();

        // Two-pointer palindrome check
        for (int i = 0; i < n / 2; i++) {
            if (converted[i] != converted[n - i - 1])
                return false;
        }
        return true;
    }
};

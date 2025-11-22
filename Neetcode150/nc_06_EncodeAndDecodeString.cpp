/*
Approach:
---------
We need to encode a list of strings into a single string such that decoding
is always possible even if strings contain special characters like '#' or digits.

Encoding Strategy:
- For each string:
        "<length>#<string>"
  Example: ["abc", "de"] → "3#abc2#de"
- This ensures unambiguous decoding.

Decoding Strategy:
- Read characters until '#', that gives the length of the next string.
- Extract exactly <length> characters after '#'.
- Move pointer forward and repeat.

Why it works:
-------------
Because the length prefix makes it impossible to confuse content with delimiters.

Time Complexity:
----------------
Encode:  O(N) where N is total characters across all strings.
Decode:  O(N) for scanning and substring extraction.

Space Complexity:
-----------------
Encode:  O(N) output string.
Decode:  O(N) for storing decoded strings.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Encode list of strings into a single string
    string encode(vector<string>& strs) {
        string ans;

        for (string &str : strs) {
            // Append: <length>#<string>
            ans += to_string(str.size()) + "#" + str;
        }
        return ans;
    }

    // Decode single string back into list of strings
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while (i < s.size()) {

            // Find the '#' delimiter
            int j = i;
            while (s[j] != '#') j++;

            // Extract the length prefix
            int len = stoi(s.substr(i, j - i));

            // Extract the actual string of 'len' characters
            string curr = s.substr(j + 1, len);
            res.push_back(curr);

            // Move pointer to next encoded segment
            i = j + 1 + len;
        }
        return res;
    }

};

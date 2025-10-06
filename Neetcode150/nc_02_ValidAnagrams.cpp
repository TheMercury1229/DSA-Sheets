#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    Approach:
    - If two strings s and t are anagrams, they must have the same frequency of each character.
    - Create a frequency array of size 26 (for each lowercase English letter).
    - Loop through both strings simultaneously:
        - Increment the count for the character in s.
        - Decrement the count for the character in t.
    - After the loop, if all values in the frequency array are zero, the strings are anagrams.

    Time Complexity: O(n), where n is the length of the strings.
    Space Complexity: O(1), since the frequency array size is fixed at 26.

    Thought Process:
    - Naive approach: Sort both strings and compare. This has O(n log n) time complexity.
    - Optimized approach: Using a frequency array, we can achieve O(n) time.
    - The key insight is that anagrams have identical character counts.
    */

    // Function to check if two strings are anagrams
    bool isAnagram(string s, string t)
    {
        // Initialize the frequency map for 26 lowercase English letters
        vector<int> freqMap(26, 0);

        // If strings are of different lengths, they cannot be anagrams
        if (s.size() != t.size())
            return false;

        // Loop through both strings
        for (int i = 0; i < s.size(); i++)
        {
            freqMap[s[i] - 'a']++; // Increment frequency for s
            freqMap[t[i] - 'a']--; // Decrement frequency for t
        }

        // Check if all frequencies are zero
        for (int i = 0; i < 26; i++)
        {
            if (freqMap[i] != 0)
                return false;
        }

        // All frequencies zero → strings are anagrams
        return true;
    }
};

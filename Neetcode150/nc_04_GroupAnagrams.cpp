#include <bits/stdc++.h>
using namespace std;
class Solution
{
    /*
    Approach:
    - If two strings are anagrams, they have the same frequency of characters.
    - For each string, generate a "code" representing the frequency of each character (26-length string for lowercase letters).
    - Use a hash map where the key is this frequency code and the value is a vector of strings sharing this code.
    - After processing all strings, the map values represent the grouped anagrams.

    Time Complexity: O(n * k), where n is the number of strings and k is the maximum length of a string.
                     Generating the frequency code takes O(k) for each string.
    Space Complexity: O(n * k), for storing the strings in the map.

    Thought Process:
    - Naive approach: Compare every string with every other string after sorting (O(n * k log k)).
    - Optimized approach: Use character frequency as a hashable key to group strings efficiently.
    - The key insight is that anagrams have identical character frequency distributions.
    */

public:
    // Helper function to generate a unique code for a string based on character frequency
    string generateCode(string str)
    {
        vector<int> charFreq(26, 0); // Frequency array for 26 lowercase letters

        // Count frequency of each character
        for (char ch : str)
        {
            charFreq[ch - 'a']++;
        }

        // Convert frequency array to a string to use as a key in the map
        string res = "";
        for (int i = 0; i < 26; i++)
        {
            res.push_back(charFreq[i]); // Append frequency as a character
        }
        return res;
    }

    // Function to group anagrams
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> anagramMap; // Map from frequency code to strings

        // Insert every string into the map based on its frequency code
        for (string str : strs)
        {
            anagramMap[generateCode(str)].push_back(str);
        }

        vector<vector<string>> ans;

        // Loop through the map and move grouped strings into the answer
        for (auto entry : anagramMap)
        {
            ans.push_back(entry.second);
        }

        return ans;
    }
    /*
    Naive Approach:
    - Sort each string and use the sorted string as a key in the hash map.
     vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> anagramMap;

        for (string str : strs)
        {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end()); // Sort each string
            anagramMap[sortedStr].push_back(str);     // Use sorted string as key
        }

        vector<vector<string>> ans;
        for (auto entry : anagramMap)
        {
            ans.push_back(entry.second);
        }
        return ans;
    }

    */
};

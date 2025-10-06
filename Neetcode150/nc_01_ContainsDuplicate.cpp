#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*
    Approach:
    - Use a hash set (unordered_set) to track the elements we have seen so far.
    - Iterate through the array.
    - If an element is already in the hash set, it is a duplicate → return true.
    - Otherwise, add it to the hash set.
    - If we finish iterating without finding a duplicate, return false.

    Time Complexity: O(n), where n is the size of the input array.
                     Each insertion and lookup in unordered_set is O(1) on average.
    Space Complexity: O(n), in the worst case all elements are unique and stored in the set.

    Thought Process:
    - The naive approach would be to use a nested loop to compare each element with every other element.
      This would have O(n^2) time complexity.
    - Using a hash set helps reduce time complexity to O(n) by allowing constant-time lookups.
    - This approach is simple, efficient, and directly leverages the properties of a hash set.
    */

    // Function to check if the array contains duplicates
    bool hasDuplicate(vector<int> &nums)
    {
        // Initialise the hash set to keep track of seen elements
        unordered_set<int> hashSet;

        // Loop over each element in the array
        for (int i : nums)
        {
            // If the element is already in the hash set, it is a duplicate
            if (hashSet.find(i) != hashSet.end())
            {
                return true;
            }
            // If the element is not present, insert it into the hash set
            hashSet.insert(i);
        }

        // If no duplicate was found after checking all elements
        return false;
    }
};

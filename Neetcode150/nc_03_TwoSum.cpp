#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    Approach:
    - Use a hash map to track the numbers we have seen and their indices.
    - For each number in the array, calculate the complement (target - current number).
    - If the complement exists in the hash map, we found the two numbers → return their indices.
    - Otherwise, store the current number and its index in the map.
    - If no solution is found (shouldn't happen per problem constraints), return {-1, -1}.

    Time Complexity: O(n), where n is the size of the array. Each lookup and insertion in unordered_map is O(1) on average.
    Space Complexity: O(n), for storing numbers in the hash map.

    Thought Process:
    - Naive approach: Use a nested loop to check all pairs (O(n^2) time complexity).
    - Optimized approach: Use a hash map to achieve O(n) time by checking complements efficiently.
    - This approach leverages the fact that we only need one pass through the array.
    */

    // Optimized twoSum function
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Initialize a hash map to store visited numbers and their indices
        unordered_map<int, int> hashSet; // {num[i], index}

        int n = nums.size();

        // Iterate through the array
        for (int i = 0; i < n; i++)
        {
            int res = target - nums[i]; // Compute the required complement

            // If the complement is already in the map, return the pair of indices
            if (hashSet.find(res) != hashSet.end())
            {
                return {hashSet[res], i};
            }

            // Otherwise, insert the current number and its index into the map
            hashSet[nums[i]] = i;
        }

        // If no pair found (shouldn't happen per problem constraints)
        return {-1, -1};
    }

    /*
    // Naive approach (commented out):
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) return {i, j};
            }
        }
        return {-1, -1};
    }
    */
};

#include <bits/stdc++.h>
using namespace std;

// /*
// Approach (Sorting-based, not the optimal solution):
// ---------------------------------------------------
// 1. If the array is empty or has one element, return its size.

// 2. Sort the input array. Sorting ensures that any consecutive numbers appear next to each other.

// 3. Initialize:
//    - curr = 1 : to track the length of the current consecutive sequence
//    - lcs = 0  : to track the maximum consecutive sequence length found so far

// 4. Traverse the sorted array from index 1 to n-1:
//    a) If the current number is equal to the previous number, skip (handle duplicates).
//    b) If the current number is exactly 1 more than the previous, increment curr.
//    c) Otherwise, update lcs = max(lcs, curr) and reset curr = 1.

// 5. After the loop, update lcs = max(lcs, curr) to account for the last sequence.

// 6. Return lcs.

// Time Complexity: O(n log n) due to sorting.
// Space Complexity: O(1) extra space (excluding input array for sort).
// */

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 0 || n == 1) return n;
        
//         sort(nums.begin(), nums.end());
//         int curr = 1, lcs = 0;
        
//         for(int i = 1; i < n; i++) {
//             if(nums[i] == nums[i-1]) continue;  // skip duplicates
            
//             if(nums[i] - nums[i-1] == 1) {
//                 curr++;
//             } else {
//                 lcs = max(curr, lcs);
//                 curr = 1;
//             }
//         }
        
//         lcs = max(curr, lcs);  // FINAL UPDATE for last sequence
//         return lcs;
//     }
// };

/*
Approach (Optimal, O(n) using HashSet):
----------------------------------------
1. Store all numbers in an unordered_set for O(1) lookups.

2. Iterate over each unique number in the set:
   a) Check if it's the **start of a sequence**:
      - If num-1 exists in the set, then skip (it's not the start).
      - Otherwise, this is the beginning of a consecutive sequence.
   
   b) Count the length of the consecutive sequence starting from this number:
      - Keep incrementing the number while the next number exists in the set.

   c) Update the maximum length found so far (lcs).

3. Return the longest consecutive sequence length (lcs).

Key Points:
- Only start counting from the beginning of a sequence (num-1 not in set) to avoid redundant work.
- Iterating over the set instead of the original array automatically avoids duplicates.

Time Complexity: O(n) on average (each number is checked at most twice: once as start, once in sequence traversal)
Space Complexity: O(n) for the unordered_set
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hset(nums.begin(), nums.end()); // store unique numbers
        int lcs = 0;

        for (int num : hset) { // iterate over unique numbers
            if (hset.find(num - 1) == hset.end()) { // start of a sequence
                int currNum = num;
                int currLen = 1;

                while (hset.find(currNum + 1) != hset.end()) {
                    currNum++;
                    currLen++;
                }

                lcs = max(lcs, currLen);
            }
        }

        return lcs;
    }
};

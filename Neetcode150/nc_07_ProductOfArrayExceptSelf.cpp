#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    Optimized Approach (without division):
    - Use two passes to calculate the product of all elements except self.
    - First pass: compute prefix products for each index and store in the answer array.
    - Second pass: compute suffix products while multiplying with existing prefix products.
    - This results in the product of all elements except the current index.

    Time Complexity: O(n), where n is the length of nums.
    Space Complexity: O(1) extra space (excluding the output array).

    Thought Process:
    - We cannot use division due to the possibility of zeros in the array.
    - Using prefix and suffix products allows us to compute the result in linear time.
    */

    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0); // Initialize answer array
        int pre = 1;           // Prefix product

        // Compute prefix products
        for (int i = 0; i < n; i++)
        {
            ans[i] = pre;
            pre *= nums[i];
        }

        int post = 1; // Suffix product

        // Compute suffix products and multiply with prefix
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= post;
            post *= nums[i];
        }

        return ans;
    }

    /*
    // Naive Approach (using nested loops):
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        for(int i = 0; i < n; i++) {
            int prod = 1;
            for(int j = 0; j < n; j++) {
                if(i != j) prod *= nums[j];
            }
            ans[i] = prod;
        }
        return ans;
    }
    // Time Complexity: O(n^2)
    // Space Complexity: O(1) extra space
    */
};

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*
    Approach 1: Sorting-Based
    - Count the frequency of each number using a hash map.
    - Store the frequencies in a vector of pairs {frequency, number}.
    - Sort the vector in descending order based on frequency.
    - Return the top k elements.

    Time Complexity: O(n log n), where n is the number of unique elements (for sorting the vector).
    Space Complexity: O(n), for the hash map and the vector of pairs.

    Thought Process:
    - Naive idea: Count frequency and sort. Simple and intuitive.
    - Works fine for small inputs but can be optimized further using a heap.
    */

    /*
    vector<int> topKFrequentSorting(vector<int> &nums, int k)
    {
        unordered_map<int, int> freqMap; // Count frequency of each number
        for (int num : nums)
        {
            freqMap[num]++;
        }

        vector<pair<int, int>> arr; // {frequency, number}
        for (auto entry : freqMap)
        {
            arr.push_back({entry.second, entry.first});
        }

        sort(arr.rbegin(), arr.rend()); // Sort in descending order of frequency

        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(arr[i].second); // Take the top k frequent elements
        }
        return ans;
    }

    */

    /*
    Approach 2: Heap-Based (Priority Queue)
    - Count the frequency of each number using a hash map.
    - Use a min-heap (priority queue) of size k to keep track of the top k frequent elements.
    - If heap size exceeds k, remove the smallest frequency element.
    - The heap will contain the k most frequent elements at the end.

    Time Complexity: O(n log k), because each insertion/removal in the heap takes O(log k).
    Space Complexity: O(n), for the hash map and heap.
    */

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freqMap;
        for (int num : nums)
        {
            freqMap[num]++;
        }

        // Min-heap to keep top k elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto entry : freqMap)
        {
            minHeap.push({entry.second, entry.first}); // {frequency, number}
            if (minHeap.size() > k)
            {
                minHeap.pop(); // Remove the element with smallest frequency
            }
        }

        vector<int> ans;
        while (!minHeap.empty())
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        reverse(ans.begin(), ans.end()); // Optional: to return in descending frequency order
        return ans;
    }
};

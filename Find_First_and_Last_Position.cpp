// Problem: Find First and Last Position of Element in Sorted Array
// Platform: LeetCode
// Category: Array
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Author: Sarthak

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), first = -1, last = -1;
        int low = 0, high = n - 1;

        // Binary search to find the first occurrence
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                first = mid;          // record index
                high = mid - 1;       // move left to find earlier index
            } else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        low = 0; high = n - 1;
        // Binary search to find the last occurrence
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                last = mid;           // record index
                low = mid + 1;        // move right to find later index
            } else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        // Return both positions
        return {first, last};
    }
};

int main() {
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> result = s.searchRange(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}

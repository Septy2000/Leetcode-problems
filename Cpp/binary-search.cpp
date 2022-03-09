// https://leetcode.com/problems/binary-search/

#include <vector>
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot;
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right) {
            pivot = (left + right) / 2;
            if (nums[pivot] == target) return pivot;
            
            if(target < nums[pivot]) {
                right = pivot - 1;
            }
            else {
                left = pivot + 1;
            }

            
        }
        
        if (nums[pivot] == target) {
            return pivot;
        }
        else {
            return -1;
        }

    }
};
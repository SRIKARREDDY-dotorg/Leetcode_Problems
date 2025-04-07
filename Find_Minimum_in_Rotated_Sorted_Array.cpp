// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=problem-list-v2&envId=binary-search
class Solution {
public:
    int findMin(vector<int>& nums) {
        // Binary Search
        int n = nums.size();
        int left = 0, right = n-1;
        while(left < right) {
            int mid = (left + right)/2;

            if(nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

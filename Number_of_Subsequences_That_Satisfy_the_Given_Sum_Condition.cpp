// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/?envType=daily-question&envId=2025-06-29

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9+7;
       sort(nums.begin(), nums.end());
       int totalCount = 0;
       int left = 0, right = nums.size()-1;

        vector<int> power(nums.size(), 1);

        for(int i = 1; i < nums.size(); i ++) {
            power[i] = (power[i-1]*2) % mod;
        }
       while(left <= right) {
            if(nums[left] + nums[right] <= target) {
                totalCount = (totalCount + power[right-left])%mod;
                left++;
            } else {
                right--;
            }
       }

       return totalCount;
    }
};

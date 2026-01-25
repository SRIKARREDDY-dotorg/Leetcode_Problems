// https://leetcode.com/problems/minimum-size-subarray-sum/?envType=problem-list-v2&envId=prefix-sum
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 1;
        int n = nums.size();
        int res = INT_MAX;
        // calculate prefix sum
        for(int i = 1; i < n; i ++) {
            if(nums[i] >= target) return 1;
            nums[i] += nums[i-1];
        }
        nums.insert(nums.begin(), 0);
        while(right < (n+1)) {
            if((nums[right] - nums[left]) < target) {
                right++;
            } else {
                // cout<<left<<" "<<right<<endl;
                res = min(res, right-left);
                left++;
            }
        }

        if(res == INT_MAX) return 0;
        return res;
    }
};

// Optimised to not using the insert operation.
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int res = INT_MAX;
        int currentSum = 0;

        // calculate prefix sum
        for(int right = 0; right < n; right ++) {
            currentSum += nums[right];
            while(currentSum >= target) {
                res = min(res, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }

        if(res == INT_MAX) return 0;
        return res;
    }
};

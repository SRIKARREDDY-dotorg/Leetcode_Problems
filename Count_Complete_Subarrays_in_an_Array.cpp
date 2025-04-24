// https://leetcode.com/problems/count-complete-subarrays-in-an-array/editorial/?envType=daily-question&envId=2025-04-24
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        // sliding window
        int res = 0;
        unordered_map<int,int> count;
        int n = nums.size();
        int right = 0;
        unordered_set<int> distinct(nums.begin(), nums.end());
        int distinctCount = distinct.size();
        
        for(int left = 0; left < n; left++) {
            if(left) {
                int remove = nums[left-1];
                count[remove]--;
                if(!count[remove]) count.erase(remove);
            }

            while(right < n && count.size() < distinctCount) {
                count[nums[right]]++;
                right++;
            }

            if(count.size() == distinctCount) {
                res += (n-right+1);
            }
        }
        return res;
    }
};

// https://leetcode.com/problems/longest-harmonious-subsequence/?envType=daily-question&envId=2025-06-30

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        int maxLen = 0;
        
        while(i < nums.size()) {
            if(abs(nums[i]-nums[j]) > 1) {
                j++;
                continue;
            }
            if(abs(nums[i]-nums[j]) == 1)
                maxLen = max(maxLen, i-j+1);
            i++;
        }
        return maxLen;
    }
};

// Further optimised

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        for(auto& num: nums) {
            hashMap[num]++;
        }
        int maxLen = 0;
        for(auto& [num, freq]: hashMap) {
            if(hashMap.count(num+1)) {
               maxLen = max(maxLen, freq+hashMap[num+1]);
            }
        }
        return maxLen;
    }
};

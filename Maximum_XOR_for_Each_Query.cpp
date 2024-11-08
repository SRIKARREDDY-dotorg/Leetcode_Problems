// https://leetcode.com/problems/maximum-xor-for-each-query/description/?envType=daily-question&envId=2024-11-08
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        for(int i = 1; i < n; i ++) {
            nums[i]^=(nums[i-1]);
        }
        vector<int> result;
        for(int i = n-1; i >= 0; i --) {
            int maximised = 0;
            for(int j = 0; j < maximumBit; j ++) {
                maximised |= ((~nums[i] >> j) & 1) << j;
            }
            result.push_back(maximised);
        }
        return result;
    }
};

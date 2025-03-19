// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/?envType=daily-question&envId=2025-03-19
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i = 0;
        int countOps = 0;
        while(i < (nums.size()-2)) {
            if(nums[i] == 0) {
                nums[i] = !nums[i];
                nums[i+1] = !nums[i+1];
                nums[i+2] = !nums[i+2];
                countOps++;
            }
            i++;
        }
        for(auto& ele: nums) cout<<ele<<" ";
        if(nums[nums.size()-1] == 0 || nums[nums.size()-2] == 0) return -1;
        return countOps;
    }
};

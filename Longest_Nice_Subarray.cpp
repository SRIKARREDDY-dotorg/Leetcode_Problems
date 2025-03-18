// https://leetcode.com/problems/longest-nice-subarray/?envType=daily-question&envId=2025-03-18
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int usedBits = 0;
        int maxLength = 0;
        int windowStart = 0;

        for(int windowEnd = 0; windowEnd < nums.size(); ++windowEnd) {
            while((usedBits & nums[windowEnd]) != 0) {
                usedBits ^= nums[windowStart];
                windowStart++;
            }
            usedBits |= nums[windowEnd];
            maxLength = max(maxLength, windowEnd-windowStart+1);
        }

        return maxLength;
    }
};

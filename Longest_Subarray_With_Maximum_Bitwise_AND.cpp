// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/?envType=daily-question&envId=2024-09-14
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = 0, currentStreak = 0, maxLength = 1;

        for(auto& num: nums) {
            if(maxNum < num) {
                maxNum = num;
                maxLength = 1;
                currentStreak = 1;
            } else if(maxNum == num) {
                currentStreak++;
            } else {
                maxLength = max(maxLength, currentStreak);
                currentStreak = 0;
            }
        }
        // cout<<maxLength<<endl;
        maxLength = max(maxLength, currentStreak);
        return maxLength;
    }
};

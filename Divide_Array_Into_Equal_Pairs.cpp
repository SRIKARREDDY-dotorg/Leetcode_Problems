// https://leetcode.com/problems/divide-array-into-equal-pairs/description/?envType=daily-question&envId=2025-03-17
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // Find maximum value in array
        int maxNum = 0;
        for (int num : nums) {
            maxNum = max(num, maxNum);
        }

        // Toggle pair status for each number
        vector<bool> needsPair(maxNum + 1, false);
        for (int num : nums) {
            needsPair[num] = !needsPair[num];
        }

        // Check if any number remains unpaired
        for (int num : nums) {
            if (needsPair[num]) {
                return false;
            }
        }

        return true;
    }
};

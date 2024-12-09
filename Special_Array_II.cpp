// https://leetcode.com/problems/special-array-ii/?envType=daily-question&envId=2024-12-09

class Solution {
public:

    vector<int> splitArray(vector<int>& nums) {
        int counter = 0;
        vector<int> result;
        result.push_back(counter);
        for(int i = 1; i < nums.size(); i ++) {
            if(nums[i]%2 == nums[i-1]%2) {
                result.push_back(++counter);
            } else {
                result.push_back(counter);
            }
            // cout<<result.back()<<endl;
        }
        return result;
    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> nonIntersectedArray = splitArray(nums);
        vector<bool> result;
        for(auto& query: queries) {
            if(nonIntersectedArray[query[0]] == nonIntersectedArray[query[1]]) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};

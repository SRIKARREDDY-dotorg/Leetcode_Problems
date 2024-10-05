// https://leetcode.com/problems/rank-transform-of-an-array/submissions/1412443291/?envType=daily-question&envId=2024-10-02
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int rank = 0;
        vector<int> result = arr;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> rankMap;
        for(int i = 0; i < arr.size(); i ++) {
            if(!rankMap[arr[i]]) rankMap[arr[i]]=(++rank);
        }
        for(int i = 0; i < arr.size(); i ++) {
            result[i] = rankMap[result[i]];
        }

        return result;
    }
};

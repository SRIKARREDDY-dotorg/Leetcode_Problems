// https://leetcode.com/problems/the-number-of-beautiful-subsets/?envType=daily-question&envId=2024-05-23
// Bruteforce
class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int>& nums, int index, int k, unordered_map<int, int>& count, vector<int>& subsets) {
        for(int i = index; i < nums.size(); i ++) {
            if(count[nums[i] - k] || count[nums[i]+k]) continue;
            subsets.push_back(nums[i]);
            result.push_back(subsets);
            count[nums[i]]++;
            backtrack(nums, i+1, k, count, subsets);
            subsets.pop_back();
            count[nums[i]]--;
        }
    }
    
    void print() {
        for(auto& ele: result) {
            cout<<"[";
            for(auto& num: ele) {
                cout<<num<<", ";
            }
            cout<<"]";
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        result.clear();
        unordered_map<int, int> count;
        vector<int> subsets;
        // int total_result = 0;
        for(int i = 0; i < nums.size(); i ++) {
            count[nums[i]] = 1;
            subsets.push_back(nums[i]);
            result.push_back(subsets);
            backtrack(nums, i+1, k, count, subsets);
            subsets.pop_back();
            count.clear();
        }

        // print();
        return result.size();
    }
};

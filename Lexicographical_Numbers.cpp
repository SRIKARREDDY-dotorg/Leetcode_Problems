// https://leetcode.com/problems/lexicographical-numbers/?envType=daily-question&envId=2024-09-21
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> stringSort;
        for(int i=1; i <= n; i ++) {
           stringSort.push_back(to_string(i)); 
        }
        sort(stringSort.begin(), stringSort.end());
        vector<int> result;
        for(auto& ele: stringSort) {
            result.push_back(stoi(ele));
        }
        return result;
    }
};

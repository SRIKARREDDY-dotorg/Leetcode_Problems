// https://leetcode.com/problems/combinations/description/?envType=problem-list-v2&envId=backtracking
class Solution {
public:
    vector<vector<int>> result;
    void fun(vector<int> curr, int n, int k, int index) {
        if(index == k) {
            // add to result;
            result.push_back(curr);
            return;
        }
        int temp = (curr.size()>0) ? curr.back()+1 : 1;
        for(int i = temp; i <= n; i ++) {
            // push only if i > curr.back()
            curr.push_back(i);
            fun(curr, n, k, index+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        vector<int> curr;
        fun(curr, n, k, 0);
        return result;
    }
};

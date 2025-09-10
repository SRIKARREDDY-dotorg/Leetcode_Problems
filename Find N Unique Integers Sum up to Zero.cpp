// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/?envType=daily-question&envId=2025-09-07
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        if(n%2) {
            result.push_back(0);
            n--;
        }
        
        for(int i = 0; i < n/2; i ++) {
            result.push_back(i+1);
            result.push_back(-(i+1));
        }
        return result;
    }
};

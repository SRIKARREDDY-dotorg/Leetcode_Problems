// https://leetcode.com/problems/minimum-array-end/submissions/1447366202/?envType=daily-question&envId=2024-11-09
class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        while(--n) {
            result = (result + 1) | x;
        }
        return result;
    }
};

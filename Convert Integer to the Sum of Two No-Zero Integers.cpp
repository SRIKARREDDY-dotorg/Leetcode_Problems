// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/?envType=daily-question&envId=2025-09-08
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int A = 1; A < n; A ++) {
            int B = n - A;
            if ((to_string(A) + to_string(B)).find('0') == string::npos) {
                return {A, B};
            }
        }
        return {};
    }
};

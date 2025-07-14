// https://leetcode.com/problems/integer-replacement/?envType=problem-list-v2&envId=bit-manipulation

class Solution {
public:
    int helper(int x, int c) {
        if(x==1) return c;

        if (x%2 == 0) {
            return helper(x>>1, c+1);
        } else {
            if (x==3 || !((x>>1)&1)) {
                return helper(x-1, c+1);
            } else {
                return helper(x+1, c+1);
            }
        }
    }
    int integerReplacement(int n) {
        if(n==2147483647) {
            n--;
        }
        return helper(n, 0);
    }
};

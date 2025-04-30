// https://leetcode.com/problems/regular-expression-matching/submissions/1621663666/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
public:
    vector<vector<int>> dp;
    bool fun(string s, string p, int si, int pi) {
       // Base conditions
       if(si < 0 && pi < 0) return true;
       if(pi < 0) return false;
       if(dp[si+1][pi+1] != -1) return dp[si+1][pi+1];
       if(si < 0 && p[pi] == '*') return dp[si+1][pi+1] = fun(s, p, si, pi-2);
       if(si < 0) return false;

        if(s[si] == p[pi] || p[pi] == '.') return dp[si+1][pi+1] = fun(s, p, si-1, pi-1);
        if(p[pi] == '*') {
            if(p[pi-1] == s[si] || p[pi-1] == '.') {
                return dp[si+1][pi+1] = fun(s, p, si-1, pi) || fun(s, p, si, pi-2);
            } else {
                return dp[si+1][pi+1] = fun(s, p, si, pi-2);
            }
        }
        return false;
    }
    bool isMatch(string s, string p) {
        dp = vector<vector<int>>(s.size()+1, vector<int>(p.size()+1, -1));
        return fun(s, p, s.size()-1, p.size()-1);
    }
};

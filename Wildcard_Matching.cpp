// https://leetcode.com/problems/wildcard-matching/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
public:
    vector<vector<int>> dp;
    bool fun(string& s, string& p, int si, int pi, int ss, int ps) {
        // cout<<"si: "<<si<<", pi: "<<pi<<endl;
        if(si == ss && pi == ps) return true;
        if(pi == ps) return false;
        if(dp[si][pi] != -1) return dp[si][pi];
        if(si == ss && p[pi] == '*') return dp[si][pi] = fun(s, p, si, pi+1, ss, ps);
        if(si == ss) return false;
        if(s[si] == p[pi] || p[pi] == '?') {
            return dp[si][pi] = fun(s, p, si+1, pi+1, ss, ps);
        }
        if(p[pi] == '*') {
            return dp[si][pi] = fun(s, p, si+1, pi, ss, ps) || fun(s, p, si, pi+1, ss, ps);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        dp = vector<vector<int>>(s.size()+1, vector<int>(p.size()+1, -1));
        return fun(s, p, 0, 0, s.size(), p.size());
    }
};

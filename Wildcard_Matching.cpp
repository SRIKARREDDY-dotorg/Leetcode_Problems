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

// Iterative
class Solution {
public:
    bool isMatch(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();
        vector<vector<bool>> dp(s_size+1, vector<bool>(p_size+1, 0));
        dp[0][0] = 1;
        for(int j = 1; j <= p_size; j ++) {
            if(p[j-1] == '*') {
                dp[0][j] = dp[0][j-1];
            }
        }
        for(int i = 1; i <= s_size; i++) {
            for(int j = 1; j <= p_size; j++) {
                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if(p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
            }
        }
        return dp[s_size][p_size];
    }
};

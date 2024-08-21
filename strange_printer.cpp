// Explanation for the solution https://leetcode.com/problems/strange-printer/editorial
typedef vector<vector<int>> vvi;

class Solution {
public:
    int strangePrinter(string s) {
        s = removeDuplicates(s);
        int n = s.size();
        vvi memo(n, vector<int>(n, -1));
        return minimumTurns(0, n-1, s, memo);
    }

    int minimumTurns(int start, int end, string s, vvi& memo) {
        if(start > end) return 0;

        if(memo[start][end] != -1) return memo[start][end];

        // worst case take one by one char
        int minTurns = 1 + minimumTurns(start+1, end, s, memo);

        // optimising chars is start and the end(here k) are same then we don't need to print it, we can do it in single pass
        // "abcda", => aaaaa, bcd => total 4 instead of printing individually.
        for(int k = start+1; k <= end; k ++) {
            if(s[k] == s[start]) {
                // 
                minTurns = min(minTurns, minimumTurns(start, k-1, s, memo) + minimumTurns(k+1, end, s, memo));
            }
        }

        return memo[start][end] = minTurns;
    }

    string removeDuplicates(string s) {
        int length = s.size();
        int i = 0;
        string uniqueChars = "";
        while(i < length) {
            char currentChar = s[i];
            uniqueChars += currentChar;
            while(i < length && currentChar == s[i]) {
                i++;
            }
        }
        return uniqueChars;
    }
};

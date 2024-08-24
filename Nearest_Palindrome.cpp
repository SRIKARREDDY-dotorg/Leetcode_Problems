// leetcode: https://leetcode.com/problems/find-the-closest-palindrome/?envType=daily-question&envId=2024-08-24
class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        int i = (len % 2 == 0) ? len/2 - 1 : len/2;
        long firstHalf = stol(n.substr(0, i + 1));

        long nl = stol(n);
        vector<long> possibilities;
        possibilities.push_back(firstHalfToPalindrome(firstHalf, (len % 2 == 0)));
        possibilities.push_back(firstHalfToPalindrome(firstHalf+1, (len % 2 == 0)));
        possibilities.push_back(firstHalfToPalindrome(firstHalf-1, (len % 2 == 0)));
        possibilities.push_back((long)(pow(10, len - 1) - 1));
        possibilities.push_back((long)(pow(10, len) + 1));

        long res = 0, diff = LONG_MAX;
        for(auto cand: possibilities) {
            // cout<<cand<<"\n";
            if(cand == nl) continue;

            if(abs(cand - nl) < diff) {
                res = cand;
                diff = abs(cand - nl);
            } else if(abs(cand - nl) == diff) {
                res = min(res, cand);
            }
        }

        return to_string(res);
    }

    long firstHalfToPalindrome(long left, bool even) {
        long res = left;
        if(!even) left = left / 10;

        while(left) {
            res = (res * 10) + (left % 10);
            left = left / 10;
        }
        return res;
    }
};

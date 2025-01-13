// https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13
class Solution {
public:
    int minimumLength(string s) {
        // abaacbcbb - 1 + 2 + 2 = 5
        unordered_map<char, int> charFreq;
        for(char& c: s){
            charFreq[c]++;
        }
        int ans = 0;
        for(auto& ele: charFreq) {
            if(ele.second%2) ans++;
            else ans+=2;
        }
        return ans;
    }
};

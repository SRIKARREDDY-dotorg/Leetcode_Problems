// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/?envType=daily-question&envId=2024-09-15
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int prefixXor = 0;
        int characterMap[26] = {0};
        characterMap['a'-'a'] = 1;
        characterMap['e'-'a'] = 2;
        characterMap['i'-'a'] = 4;
        characterMap['o'-'a'] = 8;
        characterMap['u'-'a'] = 16;

        vector<int> mp(32, -1);
        int longestSubstring = 0;
        for(int i = 0; i < s.size(); i ++) {
            prefixXor ^= characterMap[s[i]-'a'];
            if(mp[prefixXor] == -1 && prefixXor != 0) mp[prefixXor] = i;

            longestSubstring = max(longestSubstring, i - mp[prefixXor]);
        }
        return longestSubstring;
    }
};

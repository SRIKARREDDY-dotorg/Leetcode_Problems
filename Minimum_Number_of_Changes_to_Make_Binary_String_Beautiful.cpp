// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/?envType=daily-question&envId=2024-11-05
class Solution {
public:
    int minChanges(string s) {
        int minChangesRequired = 0;
        for(int i = 1; i < s.size(); i+=2) {
            if(s[i]!=s[i-1]) minChangesRequired++;
        }
        return minChangesRequired;
    }
};

// https://leetcode.com/problems/rotate-string/?envType=daily-question&envId=2024-11-03
class Solution {
public:
    
    bool rotateString(string s, string goal) {
        // abcdeabcde
        // bcdea
        if(s.size() != goal.size()) return false;
        s += s;
        // cout<<s<<endl;
        int index = 0;
        for(int i = 0; i < s.size(); i ++) {
            if(index < goal.size() && s[i]==goal[index]) {
                index++;
                if(index == goal.size()) return true;
            } else {
                i = i - index;
                index = 0;
            }
        }
        return false;
    }
};

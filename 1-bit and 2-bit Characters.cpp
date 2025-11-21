// https://leetcode.com/problems/1-bit-and-2-bit-characters/?envType=daily-question&envId=2025-11-18

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while(i < bits.size() - 1) {
            i += bits[i]+1;
        }
        return i == bits.size() - 1;
    }
};

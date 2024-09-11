// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/?envType=daily-question&envId=2024-09-11
class Solution {
public:
    int countBits(int n) {
        int count = 0;
        while (n) {
            n &= (n - 1);  // This operation reduces the number of set bits by 1
            count++;
        }
        return count;
    }

    int minBitFlips(int start, int goal) {
        // 1010
        // 0111
        int result = start ^ goal;
        return countBits(result);
    }
};

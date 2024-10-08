// Leetcode https://leetcode.com/problems/number-complement/description/?envType=daily-question&envId=2024-08-22
class Solution {
public:
    int findComplement(int num) {
        int result = 0;
        int mask = 0;

        int temp = num;
        while(num) {
            mask <<= 1;
            num >>= 1;
            mask = (mask|1);
        }

        // cout<<temp<<" "<<mask;
        return (~temp & mask);
    }
};

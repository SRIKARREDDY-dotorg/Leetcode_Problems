// https://leetcode.com/problems/count-total-number-of-colored-cells
class Solution {
public:
    long long coloredCells(int n) {
        long long numBlueCells = 1;
        int addend = 4;
        while(--n) {
            numBlueCells += addend;
            addend += 4;
        }
        return numBlueCells;
    }
};

// Math Formula F1
class Solution {
public:
    long long coloredCells(int n) {
        return 1 + (long long)n * (n-1) * 2;
    }
};

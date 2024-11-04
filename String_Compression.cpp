// https://leetcode.com/problems/string-compression-iii/?envType=daily-question&envId=2024-11-04
class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int currCount = 0;
        char curr = word[0];
        char prev = word[0];
        for(int i = 0; i < word.size(); i ++) {
            curr = word[i];
            if(prev == curr) {
                if(currCount < 9) currCount++;
                else {
                    comp += to_string(currCount)+prev;
                   currCount = 1; 
                }
            } else {
                comp += to_string(currCount)+prev;
                currCount = 1;
            }
            prev = curr;
        }
        comp += to_string(currCount)+prev;
        return comp;
    }
};

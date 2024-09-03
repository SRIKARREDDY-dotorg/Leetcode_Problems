// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/?envType=daily-question&envId=2024-09-03

class Solution {
public:
    int getLucky(string s, int k) {
        int num = 0;
        for(auto& ch: s) {
            int temp = (ch - 'a' + 1);
            int newTemp = 0;
            while(temp) {
                newTemp += temp%10;
                temp /= 10;
            }
            num = num + newTemp;
            
            // cout<<<<endl;
        }
        // cout<<num<<endl;
        k--;
        for(int i = 0; i < k; i ++) {
            int newNum = 0;
            while(num) {
                newNum += num%10;
                num /= 10;
            }
            num = newNum;
        }
        // cout<<num<<endl;
        return num;
    }
};

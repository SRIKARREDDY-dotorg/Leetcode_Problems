// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/editorial/?envType=daily-question&envId=2025-11-21

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int totalCount = 0;
        unordered_set<char> letters;
        for(char c: s) {
            letters.insert(c);
        }


        for(char letter: letters) {
            int i = -1;
            int j = 0;

            for(int k = 0; k < s.size(); k ++) {
                if(s[k] == letter) {
                    if(i == -1) i = k;
                    j = k;
                }
            }

            unordered_set<char> between;
            for(int m = i+1; m < j; m ++) {
                between.insert(s[m]);
            }

            totalCount += between.size();
        }

        return totalCount;
    }
};


// Another approach only traverse between the first & last if they are present

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int size = s.size();
        int count = 0;
        vector<int> first(26, -1), last(26, -1);

        for(int i = 0; i < size; i ++) {
            if(first[s[i]-97] == -1) {
                first[s[i]-97] = i;
            }
            last[s[i]-97] = i;
        }

        for(int i = 0; i < 26; i ++) {
            if(first[i] == -1) continue;
            unordered_set<char> between;
            for(int j = first[i]+1; j < last[i]; j ++) {
                between.insert(s[j]);
            }
            count += between.size();
        }

        return count;
    }
};

// https://leetcode.com/problems/count-vowel-strings-in-ranges/description/?envType=daily-question&envId=2025-01-02
class Solution {
public:
    bool isVowel(char& c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> vowels(n+1, 0);
        for(int i = 0; i < words.size(); i ++) {
            if(isVowel(words[i][0]) && isVowel(words[i][words[i].size()-1])) {
                vowels[i+1] += vowels[i]+1;
            } else {
                vowels[i+1] = vowels[i];
            }
        }
        vector<int> result;
        for(int i = 0; i <queries.size(); i ++) {
            int left = queries[i][0];
            int right = queries[i][1];
            result.push_back(vowels[right+1] - vowels[left]);
        }
        return result;
    }
};

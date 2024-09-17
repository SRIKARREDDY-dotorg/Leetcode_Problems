// https://leetcode.com/problems/uncommon-words-from-two-sentences/?envType=daily-question&envId=2024-09-17
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Solution {
public:
    void getWords(string& input_str, vector<string>& words) {
        std::stringstream ss(input_str);
        std::string word;
        
        while (std::getline(ss, word, ' ')) {
            words.push_back(word);
        }
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mpS1;
        unordered_map<string, int> mpS2;
        vector<string> words1;
        vector<string> words2;
        getWords(s1, words1);
        getWords(s2, words2);
        for(auto& w: words1) {
            mpS1[w]++;
        }
        for(auto& w: words2) {
            mpS2[w]++;
        }
        vector<string> result;
        for(auto& p: mpS1) {
            if(p.second == 1 && !mpS2[p.first]) result.push_back(p.first);
        }

        for(auto& p: mpS2) {
            if(p.second == 1 && !mpS1[p.first]) result.push_back(p.first);
        }

        return result;
    }
};

// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/?envType=daily-question&envId=2024-12-02

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream stream(sentence);
        string word;
        int index = 1;
        while(stream >> word) {
            if(word.rfind(searchWord, 0) == 0) {
                return index;
            }
            index++;
        }
        return -1;
    }
};

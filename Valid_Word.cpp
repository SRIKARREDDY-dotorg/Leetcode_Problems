// https://leetcode.com/problems/valid-word/submissions/1698248510/?envType=daily-question&envId=2025-07-15

class Solution {
public:
    bool isUpperCase(char& c) {
        return c > 64 && c < 91;
    }

    bool isLowerCase(char& c) {
        return c > 96 && c < 123;
    }

    bool isDigit(char& c) {
         return c > 47 && c < 58;
    }

    bool isVowel(char& c) {
        return c=='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
                c=='A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    bool isValid(string word) {
        if(word.size() < 3) return false;
        bool vowel = false;
        bool consonant = false;
        for(int i = 0; i < word.size(); i ++) {
            if(isUpperCase(word[i]) || isLowerCase(word[i])) {
                if(!vowel && isVowel(word[i])) {
                    vowel = true;
                }
                if(!consonant && !isVowel(word[i])) {
                    consonant = true;
                }
                continue;
            } else if (isDigit(word[i])) {
                continue;
            }
            return false;
        }
        return vowel && consonant;
    }
};

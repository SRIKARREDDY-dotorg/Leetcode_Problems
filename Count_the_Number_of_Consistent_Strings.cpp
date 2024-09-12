// https://leetcode.com/problems/count-the-number-of-consistent-strings/editorial/?envType=daily-question&envId=2024-09-12
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int result = 0;
        set<char> allowedSet;
        for(auto& c: allowed) {
            allowedSet.insert(c);
        }

        for(auto& word: words) {
            bool isEligible = 1;
            for(int i = 0; i < word.size(); i ++) {
                if(allowedSet.find(word[i])==allowedSet.end()) {
                    isEligible = 0;
                    break;
                }
            }
            result+=isEligible;
        }
        return result;
    }
};


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create a vector to mark which characters are allowed
        vector<bool> isAllowed(26, false);

        // Mark all characters in 'allowed' as true in the isAllowed vector
        for (int i = 0; i < allowed.length(); i++) {
            isAllowed[allowed[i] - 'a'] = true;
        }

        int consistentCount = 0;

        // Iterate through each word in the words array
        for (string& word : words) {
            bool isConsistent = true;

            // Check each character of the current word
            for (int i = 0; i < word.length(); i++) {
                // If any character is not allowed, mark as inconsistent and
                // break
                if (!isAllowed[word[i] - 'a']) {
                    isConsistent = false;
                    break;
                }
            }

            // If the word is consistent, increment the count
            if (isConsistent) {
                consistentCount++;
            }
        }

        return consistentCount;
    }
};


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // allowedBits will represent the bitmask of allowed characters
        int allowedBits = 0;

        // Set the corresponding bit for each character in allowed
        for (int i = 0; i < allowed.length(); i++) {
            allowedBits |= 1 << (allowed[i] - 'a');
        }

        int consistentCount = 0;

        // Iterate through each word in the words array
        for (string& word : words) {
            bool isConsistent = true;

            // Check each character in the word
            for (int i = 0; i < word.length(); i++) {
                // Calculate the bit position for the current character
                int bit = (allowedBits >> (word[i] - 'a')) & 1;

                // If the bit is 0, the character is not allowed
                if (bit == 0) {
                    isConsistent = false;
                    break;
                }
            }

            // If the word is consistent, increment the count
            if (isConsistent) {
                consistentCount++;
            }
        }

        return consistentCount;
    }
};

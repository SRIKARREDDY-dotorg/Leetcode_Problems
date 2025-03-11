// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left = 0; // Left pointer of the window
        int result = 0; // To store the result
        vector<int> count(3, 0); // To store counts of a, b, c

        for (int right = 0; right < n; right++) {
            // Update the count of the current character
            count[s[right] - 'a']++;

            // When the window contains at least one of each character
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                // All substrings ending at `right` and starting from `left` to `right` are valid
                result += n - right;

                // Move the left pointer to shrink the window
                count[s[left] - 'a']--;
                left++;
            }
        }

        return result;
    }
};

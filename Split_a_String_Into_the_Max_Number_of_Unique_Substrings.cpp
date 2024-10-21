// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/?envType=daily-question&envId=2024-10-21
class Solution {
    int result;
public:
    // Helper function to recursively generate substrings
    void generateSubstrings(string s, unordered_set<string>& substrings, int index) {
        if(index == s.size()) {
            // cout << "-----------------------------\n";
            // cout << substrings.size() << endl;  // Print the count of unique substrings
            // cout << "-----------------------------\n";
            // for (const string& sub : substrings) {
            //     cout << sub << endl;  // Print the actual substrings
            // }
            result = max(result, (int)substrings.size());
            return;
        }

        for(int i = index; i < s.size(); i++) {
            // Extract substring starting at 'index' of length 'i - index + 1'
            string sub = s.substr(index, i - index + 1);

            // Only add the substring if it's not already in the set
            if(substrings.find(sub) == substrings.end()) {
                substrings.insert(sub);  // Add substring to set
                generateSubstrings(s, substrings, i + 1);  // Recur for the next index
                substrings.erase(sub);  // Backtrack (remove substring)
            }
        }
    }

    // Function to start the substring generation process
    int maxUniqueSplit(string s) {
        result = 0;
        unordered_set<string> uniqueSubstrs;
        generateSubstrings(s, uniqueSubstrs, 0);
        return result;
    }
};

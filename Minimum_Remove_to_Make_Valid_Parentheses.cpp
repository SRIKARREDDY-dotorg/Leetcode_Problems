// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> removeIndices;

        // First pass: Identify misplaced parentheses
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    removeIndices.insert(i);
                }
            }
        }

        // Add remaining unmatched '(' to remove
        while (!st.empty()) {
            removeIndices.insert(st.top());
            st.pop();
        }

        // Construct valid string
        string result;
        for (int i = 0; i < s.size(); i++) {
            if (removeIndices.find(i) == removeIndices.end()) {
                result += s[i];
            }
        }
        return result;
    }
};

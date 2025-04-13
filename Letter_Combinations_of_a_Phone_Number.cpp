// https://leetcode.com/problems/letter-combinations-of-a-phone-number/?envType=problem-list-v2&envId=backtracking
class Solution {
public:
    vector<string> result;
    void permute(int index, string& curr, string& digits, unordered_map<char, string>& digitMap) {
        if(index == digits.size()) {
            result.push_back(curr);
            return;
        }
        for(char c: digitMap[digits[index]]) {
            curr.push_back(c);
            permute(index+1, curr, digits, digitMap);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        result.clear();
        if(digits.size() == 0) return {};
        // store the map of elements
        // for each digit, start with it's mapping values, 
        unordered_map<char, string> digitMap;
        digitMap['2'] = "abc";
        digitMap['3'] = "def";
        digitMap['4'] = "ghi";
        digitMap['5'] = "jkl";
        digitMap['6'] = "mno";
        digitMap['7'] = "pqrs";
        digitMap['8'] = "tuv";
        digitMap['9'] = "wxyz";
        
        string curr = "";
        permute(0, curr, digits, digitMap);
        return result;
    }
};

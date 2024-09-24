// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/submissions/1400234084/?envType=daily-question&envId=2024-09-24
class Solution {
public:
    void getPrefixes(int num, unordered_set<int>& prefixSet) {
        // Convert the integer to a string
        std::string numStr = std::to_string(num);
        // Extract and store each prefix
        for (size_t i = 1; i <= numStr.size(); ++i) {
            prefixSet.insert(std::stoi(numStr.substr(0, i)));
        }
    }
    int isPrefixPresent(int num, unordered_set<int>& prefixSet) {
        // Convert the integer to a string
        std::string numStr = std::to_string(num);
        int result = 0;
        for(size_t i = 1; i <= numStr.size(); ++i) {
            int prefix = std::stoi(numStr.substr(0, i));
            if(prefixSet.count(prefix)) {
                result = max(result, (int)i);
            }
        }

        return result;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // bruteforce
        unordered_set<int> prefixSet;
        for(int& ele: arr1) {
            getPrefixes(ele, prefixSet);
        }
        int result = 0;
        for(int& ele: arr2) {
            result = max(result, isPrefixPresent(ele, prefixSet));
        }
        return result;
    }
};

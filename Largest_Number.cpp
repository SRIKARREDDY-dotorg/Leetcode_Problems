// https://leetcode.com/problems/largest-number/description/?envType=daily-question&envId=2024-09-18
bool comp(const string& num1, const string& num2) {
    return num1 + num2 > num2 + num1;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> stringConversions;
        for(int i = 0; i < nums.size(); i ++) {
            stringConversions.push_back(to_string(nums[i]));
        }
        sort(stringConversions.begin(), stringConversions.end(), comp);
        if(stringConversions[0] == "0")return "0";
        string result= "";
        for(auto& ele: stringConversions) {
            result += ele;
        }
        return result;
    }
};

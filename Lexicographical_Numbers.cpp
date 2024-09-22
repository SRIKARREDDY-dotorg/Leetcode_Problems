// https://leetcode.com/problems/lexicographical-numbers/?envType=daily-question&envId=2024-09-21
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> stringSort;
        for(int i=1; i <= n; i ++) {
           stringSort.push_back(to_string(i)); 
        }
        sort(stringSort.begin(), stringSort.end());
        vector<int> result;
        for(auto& ele: stringSort) {
            result.push_back(stoi(ele));
        }
        return result;
    }
};


// other approach
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicalOrderNumbers;
        int currentNumber = 1;
        for(int i = 0; i < n; i++) {
            lexicalOrderNumbers.push_back(currentNumber);

            if(currentNumber*10 <= n) {
                currentNumber*=10;
            } else {
                while(currentNumber%10 == 9 || currentNumber >=n) {
                    currentNumber/=10;
                }
                currentNumber+=1;
            }
        }
        return lexicalOrderNumbers;
    }
};

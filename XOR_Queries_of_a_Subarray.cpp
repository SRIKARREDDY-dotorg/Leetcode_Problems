// https://leetcode.com/problems/xor-queries-of-a-subarray/?envType=daily-question&envId=2024-09-13
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // precomputation 
        for(int i = 1; i < arr.size(); i ++) {
            arr[i]^=arr[i-1];
            // cout<<arr[i]<<endl;
        }
        vector<int> result;
        for(int i = 0; i < queries.size(); i++) {
            int leftIndex = queries[i][0];
            int rightIndex = queries[i][1];
            cout<<leftIndex<<" "<<rightIndex<<endl;
            if(leftIndex == 0) result.push_back(arr[rightIndex]);
            else result.push_back(arr[leftIndex-1]^arr[rightIndex]);
        }
        return result;
    }
};

// https://leetcode.com/problems/product-of-array-except-self/?envType=problem-list-v2&envId=prefix-sum

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Compute Prefix product sum & Suffix product sum at the element
        int n = nums.size();
        vector<int> prefixProduct(n, 0);
        vector<int> suffixProduct(n, 0);

        prefixProduct[0] = nums[0];
        for(int i = 1; i < n; i ++) {
            prefixProduct[i] = (nums[i]*prefixProduct[i-1]);
        }

        suffixProduct[n-1] = nums[n-1];
        for(int i = n-2; i >=0; i --) {
            suffixProduct[i] = ((nums[i]*suffixProduct[i+1]));
        }

        vector<int> result;
        result.push_back(suffixProduct[1]);
        for(int i = 1; i < n-1; i ++) {
            result.push_back(prefixProduct[i-1]*suffixProduct[i+1]);
        }
        result.push_back(prefixProduct[n-2]);

        return result;
    }
};

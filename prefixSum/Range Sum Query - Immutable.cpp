// https://leetcode.com/problems/range-sum-query-immutable/description/?envType=problem-list-v2&envId=prefix-sum
class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        prefixSum.push_back(0);
        for(int i = 0; i < nums.size(); i ++) {
            prefixSum.push_back(prefixSum.back()+nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right+1] - prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

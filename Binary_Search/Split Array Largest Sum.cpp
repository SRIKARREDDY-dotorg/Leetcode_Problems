// https://leetcode.com/problems/split-array-largest-sum/description/
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        int ans = 0;

        for(int num: nums) high += num;
        while(low<=high) {
            int sum = 0;
            int mid = (low+high)/2;
            int count = 1;
            for(int i = 0; i < n; i ++) {
                if((sum + nums[i]) <= mid) sum += nums[i];

                else {
                    count++;
                    sum = nums[i];
                }
            }

            if(count > k) {
                // mid is small, move it right;
                low = mid+1;
            } else {
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};

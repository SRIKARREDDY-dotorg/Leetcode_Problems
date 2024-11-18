// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description/?envType=daily-question&envId=2024-11-16
class Solution {
public:
// sliding window
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> power;
        vector<bool> comp;
        int compsum = 0;
        if(k == 1) {
            for(int i = 0; i < nums.size(); i ++) {
                power.push_back(nums[i]);
            }
            return power;
        }
        for(int i = 1; i < k; i ++) {
            if((nums[i] - nums[i-1])==1) {
                comp.push_back(0);
            } else {
                compsum += 1;
                comp.push_back(1);
            }
        }
        if(!compsum) {
            power.push_back(nums[k-1]);
        } else {
            power.push_back(-1);
        }

        for(int i = k; i < nums.size(); i ++) {
            compsum -= comp[0];
            comp.erase(comp.begin());
            if((nums[i] - nums[i-1])==1) {
                comp.push_back(0);
            } else {
                compsum += 1;
                comp.push_back(1);
            }
            if(!compsum) {
                power.push_back(nums[i]);
            } else { 
                power.push_back(-1);
            }
        }
        return power;
    }
};

// Sol2
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> result(length - k + 1, -1);
        deque<int> indexDeque;

        for (int currentIndex = 0; currentIndex < length; currentIndex++) {
            if (!indexDeque.empty() &&
                indexDeque.front() < currentIndex - k + 1) {
                indexDeque.pop_front();
            }

            if (!indexDeque.empty() &&
                nums[currentIndex] != nums[currentIndex - 1] + 1) {
                indexDeque.clear();
            }

            indexDeque.push_back(currentIndex);

            if (currentIndex >= k - 1) {
                if (indexDeque.size() == k) {
                    result[currentIndex - k + 1] = nums[indexDeque.back()];
                } else {
                    result[currentIndex - k + 1] = -1;
                }
            }
        }
        return result;
    }
};

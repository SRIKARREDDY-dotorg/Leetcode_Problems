// https://leetcode.com/problems/magnetic-force-between-two-balls/?envType=daily-question&envId=2024-06-20

class Solution {
public:
    bool canPlace(int gap, vector<int>& position, int m) {
        int balls = 1;
        int previousPosition = position[0];
        for(int i = 0; i < position.size() && balls<m; i ++) {
            int currentPosition = position[i];
            if((currentPosition - previousPosition) >= gap) {
                previousPosition = currentPosition;
                balls++;
                // cout<<balls<<", ";
            }
        }
        // cout<<endl;
        return balls == m;
    }

    int maxDistance(vector<int>& position, int m) {
        // order doesn't matter, we can think of sorting or heap
        int answer = 0;
        int n = position.size();
        sort(position.begin(), position.end());

        int low = 1;
        int high = ceil(position[n-1]/(m - 1.0));
        int ans = 0;
        while(low <= high) {
            int mid = (low + high)/2;
            cout<<mid<<"-> ";
            if(canPlace(mid, position, m)) {
                // cout<<mid<<" ";
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

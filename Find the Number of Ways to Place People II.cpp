// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/description/?envType=daily-question&envId=2025-09-03
class Solution {
public:
    static bool customCompare(vector<int> a, vector<int> b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), customCompare);
        int count = 0;
        for(int i = 0; i < points.size(); i ++) {
            int x1 = points[i][0], y1 = points[i][1];
            int maxY = INT_MIN;

            for(int j = i+1; j < points.size(); j ++) {
                int x2 = points[j][0], y2 = points[j][1];
            
                if(y2 > y1) continue;
            
                if(maxY < y2) {
                    maxY = y2;
                    count++;
                }
            }
        }
        return count;
    }
};

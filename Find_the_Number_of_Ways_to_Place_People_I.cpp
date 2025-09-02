// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/
class Solution {
public:
    static bool customCompare(vector<int> a, vector<int> b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    bool isUpperLeft(vector<int>& a, vector<int>& b) {
        if(a[0] <= b[0] && a[1] >= b[1]) {
            return true;
        }
        return false;
    }
    bool isPointInBetween(vector<vector<int>>& points, int x, int y) {
        vector<int> a = points[x];
        vector<int> b = points[y];
        for(int i = 0; i < points.size(); i ++) {
            if(i == x || i == y) continue;
            if(a[0] <= points[i][0] && points[i][0] <= b[0] && a[1] >= points[i][1] && points[i][1] >= b[1]) {
                return true;
            }
        }
        return false;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), customCompare);
        int count = 0;
        for(int i = 0; i < points.size(); i ++) {
            for(int j = i+1; j < points.size(); j ++) {
                if(isUpperLeft(points[i], points[j]) && !isPointInBetween(points, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};
